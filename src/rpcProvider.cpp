#include "rpcProvider.hpp"
#include "rpcHeader.pb.h"
#include "rpcApplication.hpp"
#include "zookeeper.hpp"
void RpcProvider::notifyService(google::protobuf::Service* service){
    //获得这个service的描述，比如说是UserService的抽象描述
    const google::protobuf::ServiceDescriptor* serviceDescription = service->GetDescriptor();
    const string serviceName = serviceDescription->name();
    //获得这个service里面有多少个方法
    int methodNum = serviceDescription->method_count();
    //用这个结构体来表示这个service
    ServiceInfo service_info;
    service_info._service = service;
    //遍历所有在里面的方法
    for(int i = 0; i < methodNum; i++){
        //获得方法的抽象描述
        const google::protobuf::MethodDescriptor* methodDescription = serviceDescription->method(i);
        const string methodName = methodDescription->name();
        //采用方法名字当key，方法抽象描述当value是因为调用时候是只知道方法名字的，根据这个map来获得描述从而获得真正的函数。
        service_info._methodMap.insert({methodName, methodDescription});   
    }
    _serviceMap.insert({serviceName, service_info});
}
void RpcProvider::start(){
    string ip = RpcApplication::getRpcApplication().GetConfig().load("rpcserverip");
    uint16_t port = atoi(RpcApplication::getRpcApplication().GetConfig().load("rpcserverport").c_str());

    InetAddress address(port, ip);   //muduo的五步  1.设置InetAddress地址，将服务器端口号和ip写进去
   //2.设置server对象，里面传递的eventloop指针需要自己在hpp里的私有里设置
    TcpServer server(&_eventLoop, address, "rpcProvider");  
    //3.设置connection回调和message回调，里面传递的函数应该用bind绑定，因为这些回调函数是在类的私有里设置的，要多传this。
    server.setConnectionCallBack(bind(&RpcProvider::onConnection, this, placeholders::_1));
    server.setMessageCallBack(bind(&RpcProvider:: onMessage, this, placeholders::_1, placeholders::_2, placeholders::_3));
    //4.设置线程数量，一个网络线程三个业务线程
    server.setThreadNum(4);

    ZKClient zkcil;
    zkcil.start();
    for(auto& sp: _serviceMap){
        string servicePath = "/" + sp.first;
        zkcil.create(servicePath.c_str(),nullptr,0);
        for(auto& mp: sp.second._methodMap){
            string method_path = servicePath + "/" + mp.first;
            char method_data[128] = {0};
            sprintf(method_data,"%s:%d", ip.c_str(), port);
            zkcil.create(method_path.c_str(),method_data, strlen(method_data),ZOO_EPHEMERAL);
        }
    }
    cout << "RpcProvider start service at ip:" << ip << " port:" << port << std::endl;
    //5.最后启动服务
    server.start();
    cout << "rpc服务已启动" << endl;
    _eventLoop.loop();
}

void RpcProvider::onConnection(const TcpConnectionPtr& conn){
    if(!conn->connected()){
        conn->shutdown();
    }
}
//传输格式：前4个字节记录服务名和方法名长度，之后参数长度，之后参数
void RpcProvider::onMessage(const TcpConnectionPtr& conn, Buffer* buffer, TimeStamp time){
    string reciveBuf = buffer->retriveAllString();
    uint32_t header_size = 4;
    reciveBuf.copy((char*)&header_size,4,0);
    //开始反序列化
    string rpc_header_str = reciveBuf.substr(4,header_size);
    rpc::RpcHeader rpcheader;
    string serviceName;
    string methodName;
    int argSize; 
    if(rpcheader.ParseFromString(rpc_header_str)){
        serviceName = rpcheader.service_name();
        methodName = rpcheader.method_name();
        argSize = rpcheader.args_size();
        RPCLogger::GetInstance().Log("log:远端rpc请求反序列化成功：" + methodName);
    }else{
        RPCLogger::GetInstance().Log("error:数据" + rpc_header_str+"反序列化失败");
        return;
    }
    string args_str = reciveBuf.substr(4+header_size, argSize);
    auto it = _serviceMap.find(serviceName);
    if(it == _serviceMap.end()){
        RPCLogger::GetInstance().Log("error:找不到service：" + rpc_header_str+"反序列化失败");
        return;
    }
    auto serviceInfo = it->second;
    auto mit = serviceInfo._methodMap.find(methodName);
    if(mit == serviceInfo._methodMap.end()){
        RPCLogger::GetInstance().Log("error:找不到method：" + methodName);
        return;
    }
    google::protobuf::Service* service = it->second._service;
    const google::protobuf::MethodDescriptor* methodDes = mit->second;
    //生成request和response
    google::protobuf::Message* request = service->GetRequestPrototype(methodDes).New();
    if(!request->ParseFromString(args_str)){
        RPCLogger::GetInstance().Log("error:参数反序列化失败:" + args_str);
        return;
    }
    google::protobuf::Message* response = service->GetResponsePrototype(methodDes).New();
    //绑定一个closure回调函数
    google::protobuf::Closure* done =  
    google::protobuf::NewCallback<RpcProvider, const TcpConnectionPtr&, google::protobuf::Message* >(this, &RpcProvider::sendResponse, conn, response);
    //调用方法 
    service->CallMethod(methodDes,nullptr,request,response, done);
}
//closure的回调方法，用于rpc的序列化以及发送回去
void RpcProvider::sendResponse(const TcpConnectionPtr& conn, google::protobuf::Message* response){
    string responseStr;
    if(response->SerializeToString(&responseStr)){
        conn->send(responseStr);
        RPCLogger::GetInstance().Log("log:远端rpc请求的回复已发送:" + responseStr);
    }else{
        RPCLogger::GetInstance().Log("error:response序列化失败");
    }
    conn->shutdown();
}