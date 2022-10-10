#include "rpcApplication.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
rpcConfig RpcApplication::_config;
void showArgsHelp(){
    cout << "format command -i <configfile>" << endl;
}

void RpcApplication::init(int argc, char** argv){
    if(argc < 2){
        showArgsHelp();
        exit(EXIT_FAILURE);
    }
    int c = 0;
    string config_file;
    while((c = getopt(argc, argv, "i:")) != -1 ){
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            cout << "无效参数" << endl;
            showArgsHelp();
            exit(EXIT_FAILURE);
        case ':':
            cout << "need <configfile>" << endl;
            showArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
    _config.loadConfig(config_file.c_str());
}

RpcApplication& RpcApplication::getRpcApplication(){
        static RpcApplication app;
        return app;
}
rpcConfig& RpcApplication::GetConfig()
{
    return _config;
}