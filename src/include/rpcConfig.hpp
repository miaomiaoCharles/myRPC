#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
class rpcConfig{
public:
    void loadConfig(const char* config_file);
    string load(string key);
private:
    unordered_map<string, string > configMap;
};