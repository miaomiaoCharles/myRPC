#pragma once
#include <iostream>
#include <google/protobuf/service.h>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include "rpcLogger.hpp"
using namespace std;
using namespace google::protobuf;

class MyRpcChannel:public google::protobuf::RpcChannel{
public:

    void CallMethod(const MethodDescriptor* method,
                          RpcController* controller, const Message* request,
                          Message* response, Closure* done);
private:
};
