#include <iostream>
#include <string>
#include "user.pb.h"
#include "rpcApplication.hpp"
#include "rpcProvider.hpp"
using namespace std;
using namespace lqc;

class UserService:public UserServiceRpc{
public:
    bool login(int id, string pwd){
        cout << "deng lu!" << endl;
        cout << id << " " << pwd << endl;
        return true; 
    }
    // bool Register(int id, string name, string pwd){
    //     cout << "zhu ce!" << endl;
    //     cout << id << " " << name << " " << pwd << endl;
    // }
    void login(google::protobuf::RpcController* controller,
                       const ::lqc::LoginRequest* request,
                       ::lqc::LoginResponse* response,
                       ::google::protobuf::Closure* done)
                       {
                        int id = request->id(); //四步，首先接收request里面给的参数，其次用参数调用自己的函数，之后写res的值，最后使用done->run的方法将res里的东西返回回去(这里的run的内容由框架完成)
                        string pwd = request->pwd();
                        bool ifSuccess = login(id, pwd);
                        resCode* res = response->mutable_res();
                        res->set_errcode(0);
                        res->set_errmsg("");
                        done->Run();
                       }
    // void register(google::protobuf::RpcController* controller,
    //                    const ::lqc::RegisterRequest* request,
    //                    ::lqc::RegisterResponse* response,
    //                    ::google::protobuf::Closure* done)
    //                    {
    //                     int id = request->id(); 
    //                     string name = request->name();
    //                     string pwd = request->pwd();
    //                     bool ifSuccess = Register(id, name, pwd);
    //                     resCode* res = response->mutable_res();
    //                     res->set_errcode(0);
    //                     res->set_errmsg("");
    //                     done->Run();
    //                    }
};

int main(int argc, char** argv){
    RpcApplication::init(argc, argv);  
    RpcProvider provider; //负责数据序列化与网络收发
    provider.notifyService(new UserService());
    provider.start();//进程进入阻塞等待调用 
    return 0;
}

