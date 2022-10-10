#pragma once
#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>
using namespace std;
class ZKClient{
public:
    ZKClient();
    ~ZKClient();
    void start(); //启动zkserver
    //创建一个znode节点
    void create(const char* path, const char* data, int dataLen, int state = 0);
    string getData(const char* path);
private:
    zhandle_t* _zhandle; //用来操纵zookeeper的句柄
};