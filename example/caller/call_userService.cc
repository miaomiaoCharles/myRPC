#include <iostream>
#include "user.pb.h"
#include "rpcApplication.hpp"
#include "rpcChannel.hpp"
using namespace std;
using namespace lqc;

int main(int argc, char** argv){
    RpcApplication::init(argc, argv);
    lqc::UserServiceRpc_Stub  stub(new MyRpcChannel());
    lqc::LoginRequest request;
    request.set_id(123456);
    request.set_pwd("lqc8193932");
    lqc::LoginResponse response;
    stub.login(nullptr, &request, &response, nullptr);
    if(response.res().errcode() == 0){
        cout << "rpc调用成功" << endl;
    }else{
        cout << "rpc调用失败：" << response.res().errmsg() << endl;
    }

    // lqc::RegisterRequest RegisterRequest;
    // RegisterRequest.set_id(123);
    // RegisterRequest.set_name("lala");
    // RegisterRequest.set_pwd("lqc8193932");
    // lqc::LoginResponse RegisterResponse;
    // stub.register(nullptr, &RegisterRequest, &RegisterResponse, nullptr);
    // if(RegisterResponse.res().errcode() == 0){
    //     cout << "注册rpc调用成功" << endl;
    // }else{
    //     cout << "注册rpc调用失败：" << response.res().errmsg() << endl;
    // }

}