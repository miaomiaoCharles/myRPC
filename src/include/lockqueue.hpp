#pragma once
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

//模板类，不能声明定义分离了
template<typename T>
class LockQueue{
public:
    void push(const T& data){
        unique_lock<mutex> lock(_mutex);
        _queue.push(data);
        _conditionVariable.notify_all();
    }
    T pop(){
        unique_lock<mutex> lock(_mutex);
        while (_queue.empty())
        {
            _conditionVariable.wait(lock);
        }
        T& data = _queue.front();
        _queue.pop();
        return data;
    }
private:
    queue<T> _queue;
    mutex _mutex;
    condition_variable _conditionVariable;
};