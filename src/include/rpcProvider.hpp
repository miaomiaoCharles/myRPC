#pragma once
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <functional>
#include <unordered_map>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include "rpcApplication.hpp"
#include "logger.hpp"
using namespace std;
//专门发布网络服务的对象
class RpcProvider{
public:
    void notifyService(google::protobuf::Service* service);
    void start();
    struct ServiceInfo{   //服务信息，用于注册rpc节点
        google::protobuf::Service* _service;
        unordered_map<string, const google::protobuf::MethodDescriptor*> _methodMap;
    };
    unordered_map <string, ServiceInfo> _serviceMap; //已注册的rpc节点，key是服务名称
private:
    //unique_ptr<muduo::net::TcpServer> _tcpServerPtr;
    muduo::net::EventLoop _eventLoop;
    void onConnection(const muduo::net::TcpConnectionPtr&); //连接回调
    void onMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*, muduo::Timestamp);
    void sendResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);
};