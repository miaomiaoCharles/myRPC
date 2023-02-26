#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
//框架读取配置文件类
class RpcConfig{
public:
    void loadConfig(const char* config_file);//解析加载配置文件
    string load(string key);//查询配置项信息
private:
    unordered_map<string, string > configMap;
};