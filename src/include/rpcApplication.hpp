#pragma once
#include "rpcConfig.hpp"
#include "rpcChannel.hpp"
#include "rpcControler.hpp"
//框架的基础类，负责框架的初始化等操作。
//单例模式      
class RpcApplication{
public:
    static void init(int argc, char** argv);
    static RpcApplication& getRpcApplication();
    static RpcConfig& GetConfig();
private:
    RpcApplication(){}
    RpcApplication(const RpcApplication&) = delete;
    RpcApplication(RpcApplication&&) = delete;
    static RpcApplication* rpc;
    static RpcConfig _config;
    static int _started; //保证只初始化一次
};