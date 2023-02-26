#pragma once
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <functional>
#include <unordered_map>
#include <mymuduo/tcpServer.hpp>
#include "rpcApplication.hpp"
#include "rpcLogger.hpp"
using namespace std;
//专门发布网络服务的对象
class RpcProvider{
public:
//通过该函数发布RPC方法
    void notifyService(google::protobuf::Service* service);
    void start();
    struct ServiceInfo{   //服务信息，用于注册rpc节点
        google::protobuf::Service* _service;
        unordered_map<string, const google::protobuf::MethodDescriptor*> _methodMap;
    };
    unordered_map <string, ServiceInfo> _serviceMap; //已注册的rpc节点，key是服务名称
private:
    //unique_ptr<muduo::net::TcpServer> _tcpServerPtr;
    EventLoop _eventLoop;
    void onConnection(const TcpConnectionPtr&); //连接回调
    void onMessage(const TcpConnectionPtr&, Buffer*, TimeStamp);
    void sendResponse(const TcpConnectionPtr&, google::protobuf::Message*);
};