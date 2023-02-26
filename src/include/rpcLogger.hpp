#pragma once
#include "lockqueue.hpp"
#include <string>

// 定义宏 LOG_INFO("xxx %d %s", 20, "xxxx")
#define RPC_LOG_INFO(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance(); \
        logger.SetLogLevel(INFO); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c); \
    } while(0) \

#define RPC_LOG_ERR(logmsgformat, ...) \
    do \
    {  \
        Logger &logger = Logger::GetInstance(); \
        logger.SetLogLevel(ERROR); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c); \
    } while(0) \

// 定义日志级别
enum logLevel
{
    RPC_INFO,  // 普通信息
    RPC_ERROR, // 错误信息
};

// Mprpc框架提供的日志系统
class RPCLogger
{
public:
    // 获取日志的单例
    static RPCLogger& GetInstance();
    // 设置日志级别 
    void SetLogLevel(logLevel level);
    // 写日志
    void Log(std::string msg);
private:
    int m_loglevel; // 记录日志级别
    LockQueue<std::string>  m_lckQue; // 日志缓冲队列

    RPCLogger();
    RPCLogger(const RPCLogger&) = delete;
    RPCLogger(RPCLogger&&) = delete;
};