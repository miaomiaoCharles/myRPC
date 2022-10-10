#pragma once
#include "rpcConfig.hpp"
#include "rpcChannel.hpp"
#include "rpcControler.hpp"
//框架的基础类，负责框架的初始化等操作。
class RpcApplication{
public:
    static void init(int argc, char** argv);
    static RpcApplication& getRpcApplication();
    static rpcConfig& GetConfig();
    // static RpcApplication* getRpcApplication(){
    //     if(rpc == nullptr){
    //         return new RpcApplication();
    //     }else{
    //         return rpc;
    //     }
    // }
private:
    RpcApplication(){}
    RpcApplication(const RpcApplication&) = delete;
    RpcApplication(RpcApplication&&) = delete;
    static RpcApplication* rpc;
    static rpcConfig _config;
};