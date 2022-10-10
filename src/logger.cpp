#include "logger.hpp"

Logger& Logger::getInstance(){
    static Logger logger;
    return logger;
}


// void Logger::setLogLevel(logLevel level){
//     _logLevel = level;
// }


void Logger::Log(string msg){
    msg += "\n";
    _queue.push(msg);
}

Logger::Logger(){
    thread writeLogger([&](){
        for(;;){
            time_t now = time(nullptr);
            tm* noewTm = localtime(&now);
            char fileName[128];
            sprintf(fileName,"%d-%d-%d - log.txt", noewTm->tm_year+1900, noewTm->tm_mon+1, noewTm->tm_mday);
            FILE* file = fopen(fileName, "a+");
            if(file == nullptr){
                cout << "创建日志文件失败" << endl;
                exit(EXIT_FAILURE);
            }
            string msg = _queue.pop();
            char secTime[128];
            sprintf(secTime,"time:%d-%d-%d\n", noewTm->tm_hour, noewTm->tm_min, noewTm->tm_sec);
            msg.insert(0,secTime);
            fputs(msg.c_str(),file);
            fclose(file);
        }
    });
    writeLogger.detach();
}