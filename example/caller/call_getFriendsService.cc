#include <iostream>
#include "friends.pb.h"
#include "rpcApplication.hpp"
using namespace std;
using namespace lqc;

int main(int argc, char** argv){
    RpcApplication::init(argc, argv);
    lqc::FriendsServiceRpc_Stub stub(new MyRpcChannel());
    lqc::getFriendsRequest request;
    request.set_id(1);
    lqc::getFriendsResponse response;
    RpcController* controler = new Controler();
    stub.getFriends(controler, &request, &response, nullptr);
    if(response.res().errcode() == 0){
        cout << "rpc调用成功" << endl;
    }else{
        cout << "rpc调用失败：" << response.res().errmsg() << endl;
    }
    
}