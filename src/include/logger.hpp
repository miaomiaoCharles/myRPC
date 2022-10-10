#pragma once
#include <iostream>
#include <time.h>
#include "lockqueue.hpp"
using namespace std;

// enum logLevel{
//     normal = 1,
//     error = 2
// };

class Logger{
public:
    static Logger& getInstance();
    // void setLogLevel(logLevel level);
    void Log(string msg);
private:
    // int _logLevel;
    LockQueue<string> _queue;
    Logger();
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
};