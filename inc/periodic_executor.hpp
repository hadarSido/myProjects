#pragma once
#include <queue> // queue
#include <functional>
#include <thread>
#include <mutex> // mutex
#include <condition_variable> //condition variable
#include "waitable_queue.hpp"
#include "task.hpp"

namespace mt {

class PeriodicExecutor {
public:
    PeriodicExecutor(size_t a_capacity);
    ~PeriodicExecutor(); 
    PeriodicExecutor(const PeriodicExecutor &a_other) = delete;                                      
    PeriodicExecutor& operator=(const PeriodicExecutor &a_other) = delete; 

    void submit(std::function<bool()> , std::chrono::milliseconds a_period);
    void submit(std::function<void()> , std::chrono::milliseconds a_period);
    void submit(std::function<void()> , std::chrono::milliseconds a_period, uint64_t a_repeatCount);
    
    void pause(); 
    void resume();
    void stop();
    size_t size();

private:
    void run();

private:
    using Task = mt::implementation_details::Task;

    advcpp::WaitableQueue<Task, std::priority_queue<Task>> m_tasks;
    size_t m_capacity;
    bool m_isPause;
    bool m_shouldStop;
    std::thread m_thread;
    mutable std::mutex m_mutex;
    std::condition_variable m_cvIsResume; 
 


};

}//mt
