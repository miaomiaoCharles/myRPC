#pragma once
#include <iostream>
#include <google/protobuf/service.h>
#include <string>
using namespace std;
class Controler: public google::protobuf::RpcController{
public:
    Controler();
    void Reset();
    bool Failed() const;
    string ErrorText() const;
    void SetFailed(const string& reason);
    //以下三个暂时用不上
    void StartCancel(){}
    bool IsCanceled() const{return true;}
    void NotifyOnCancel(google::protobuf::Closure* callback){}
private:
    string errorMessge;
    bool isError;
};