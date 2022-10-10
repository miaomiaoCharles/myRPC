#include <iostream>
#include "test.pb.h"
using namespace std;
using namespace fixbug;
int main(){
    //序列化
    // LoginRequest req;
    // req.set_name("kaka");
    // req.set_pwd("lqc123");
    // string send_str;
    // if(req.SerializeToString(&send_str)){
    //     cout << send_str << endl;
    // }

    // //反序列化
    // LoginRequest req2;
    // if(req2.ParseFromString(send_str)){
    //     cout << req2.name() << endl;
    //     cout << req2.pwd() << endl;
    // }
    getFriendsResponse req;
    resCode* res = req.mutable_res();
    res->set_errcode(1);
    res->set_errmsg("错误！");
    User* u = req.add_friends();
    u->set_id(5);
    u->set_name("lala");
    User* u2 = req.add_friends();
    u2->set_id(6);
    u2->set_name("yaya");
    string send_str;
    if(req.SerializeToString(&send_str)){
        cout << send_str << endl;
    }
    
}