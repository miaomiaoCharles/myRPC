#include "rpcConfig.hpp"
void trim(string& bufStr){    //该函数用于数据清洗时去除前后多余空格
    int loc = bufStr.find_first_not_of(' ');
    if(loc != -1){
        bufStr = bufStr.substr(loc, bufStr.size()-loc);
    }
    loc = bufStr.find_last_not_of(' ');
    if(loc != -1){
        bufStr = bufStr.substr(0, loc+1);
    }
}


void rpcConfig::loadConfig(const char* config_file){
    FILE* pf = fopen(config_file,"r");
    if(pf == nullptr){
        cout << config_file << " 不存在" << endl;
        exit(EXIT_FAILURE);
    }
    while(!feof(pf)){
        char buf[512] = {0};
        fgets(buf,512,pf);
        string bufStr(buf);
        bufStr = bufStr.substr(0, bufStr.size()-1);  //去掉多余的换行符
        //进入数据清洗
        trim(bufStr);
        if(bufStr[0] == '#' || bufStr.empty()) continue;
        //处理解析配置项
        auto idx = bufStr.find('=');
        if(idx == -1) continue;
        string key = bufStr.substr(0, idx);
        trim(key);
        string value = bufStr.substr(idx+1, bufStr.size()- idx-1);
        trim(value);
        configMap.insert({key,value});

    }
}
string rpcConfig::load(string key){
    auto it = configMap.find(key);
    if(it != configMap.end()){
        return it->second;
    }else{
        return "";
    }
    
}
