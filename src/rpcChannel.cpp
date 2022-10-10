
#include "rpcChannel.hpp"
#include "rpcHeader.pb.h"
#include "rpcApplication.hpp"
#include "zookeeper.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <functional>
#include <memory>
void MyRpcChannel::CallMethod(const MethodDescriptor* method,
                          RpcController* controller, const Message* request,
                          Message* response, Closure* done)
    {
        //首先要进行数据的序列化，回顾一下序列化的格式:
        //rpcHeader的长度 + rpcHeader（service_name + method_name + args_size) + args
        const google::protobuf::ServiceDescriptor* sd = method->service();
        string methodName = method->name();
        string serviceName = sd->name();
        uint32 args_size = 0;
        
        string args;
        if(request->SerializePartialToString(&args)){
            args_size = args.size();
        }else{
            controller->SetFailed("调用请求序列化失败");
            return;
        }
        rpc::RpcHeader rpcHeader;
        rpcHeader.set_method_name(methodName);
        rpcHeader.set_service_name(serviceName);
        rpcHeader.set_args_size(args_size);
        uint32 rpcHeader_size;
        string rpcHeaderStr;
        if(rpcHeader.SerializePartialToString(&rpcHeaderStr)){
            rpcHeader_size = rpcHeaderStr.size();
        }else{
            controller->SetFailed("rpc头序列化失败");
            return;
        }
        string sendStr;
        sendStr.insert(0, string((char*)&rpcHeader_size, 4));
        sendStr += rpcHeaderStr;
        sendStr += args;


        //使用tcp编程来发送数据
        // string ip = RpcApplication::getRpcApplication().GetConfig().load("rpcserverip");
        // uint16_t port = atoi(RpcApplication::getRpcApplication().GetConfig().load("rpcserverport").c_str());
        ZKClient zkcil;
        zkcil.start();
        char name[128] = {0};
        sprintf(name, "/%s/%s", serviceName.c_str(), methodName.c_str());
        string addStr = zkcil.getData(name);
        if(addStr == ""){
            controller->SetFailed("在zookeeper里没有找到对应的ip地址与端口号");
            return;
        }
        int index = addStr.find(":");
        string ip = addStr.substr(0,index);
        uint16_t port = atoi(addStr.substr(index+1, addStr.size()-index).c_str()); 
        unique_ptr<int, function<void(int*)> > socketfdPtr(new int(socket(AF_INET, SOCK_STREAM, 0)), [](int* fd)->void{close(*fd);});
        struct sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());
        if(-1 == connect(*socketfdPtr,(struct sockaddr*)&serverAddr,sizeof(serverAddr))){
            controller->SetFailed("连接失败");
            return;
        }
        if(-1 == send(*socketfdPtr, sendStr.c_str(), sendStr.size(),0)){
            controller->SetFailed("发送调用请求失败");
            return;
        }
        char recive_buf[1024] = {0};
        int recive_size = 0;
        if(-1 == (recive_size = recv(*socketfdPtr,recive_buf,1024, 0))){
            controller->SetFailed("接收调用的回复失败");
            return;
        }
        // string responseStr(recive_buf,0,recive_size);
        if(!response->ParseFromArray(recive_buf, recive_size)){
            controller->SetFailed("调用回复的反序列化失败");
            return;
        }
    }