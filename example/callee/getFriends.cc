#include <iostream>
#include <string>
#include "friends.pb.h"
#include "rpcApplication.hpp"
#include "rpcProvider.hpp"
using namespace std;
using namespace lqc;

struct User{
    int id;
    string name;
};

class GetFriends:public FriendsServiceRpc {
public:
    vector<User> getFirends(int id){
        vector<User> ans;
        cout << "返回id:" <<id <<"的朋友列表" << endl;
        User u;
        u.id = 1;
        u.name = "la";
        ans.push_back(u);
        return ans;
    }
    void getFriends(google::protobuf::RpcController* controller,
                       const ::lqc::getFriendsRequest* request,
                       ::lqc::getFriendsResponse* response,
                       ::google::protobuf::Closure* done)
                    {
                        int id = request->id();
                        vector<User> res = getFirends(id);
                        response->mutable_res()->set_errmsg("");
                        response->mutable_res()->set_errcode(0);
                        for(auto u: res){
                            lqc::user* p = response->add_friends();
                            p->set_id(u.id);
                            p->set_name(u.name);
                        }
                        done->Run();
                    }
};

int main(int argc, char** argv){
    RpcApplication::init(argc, argv);  
    RpcProvider provider; //负责数据序列化与网络收发
    provider.notifyService(new GetFriends());
    provider.start();//进程进入阻塞等待调用 
    return 0;
}
