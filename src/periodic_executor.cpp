#include <ostream> //endl try-catch
#include <iostream> //cerr try-catch
#include <exception> // terminate

#include "periodic_executor.hpp"

namespace mt {
PeriodicExecutor::PeriodicExecutor(size_t a_capacity)
: m_tasks(a_capacity + 1) 
, m_capacity(a_capacity)
, m_isPause(false)
, m_shouldStop(false)
, m_thread([this](){run();})
, m_mutex()
, m_cvIsResume()
{}

PeriodicExecutor::~PeriodicExecutor()
{
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void PeriodicExecutor::stop()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_shouldStop = true;
    m_cvIsResume.notify_one();
    lock.unlock();
    submit([](){}, std::chrono::milliseconds(0));
}

size_t PeriodicExecutor::size()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_tasks.size();
}

void PeriodicExecutor::submit(std::function<bool()> a_func, std::chrono::milliseconds a_period) 
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if(m_capacity == m_tasks.size() -1) {
        std::cerr << "PeriodicExecutor::submit() - queue is full" << std::endl;
    }
    else {
        Task task{a_func, a_period};
        m_tasks.enqueue(task);
    }
    lock.unlock();
    m_cvIsResume.notify_all();
}

void PeriodicExecutor::submit(std::function<void()> a_func, std::chrono::milliseconds a_period) 
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if(m_capacity == m_tasks.size() - 1) {
        std::cerr << "PeriodicExecutor::submit() - queue is full" << std::endl;
    }
    else {
        Task task{a_func, a_period};
        m_tasks.enqueue(task);
    }
    lock.unlock();
    m_cvIsResume.notify_all();
}

void PeriodicExecutor::submit(std::function<void()> a_func, std::chrono::milliseconds a_period, uint64_t a_repeatCount) 
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if(m_capacity == m_tasks.size() - 1) {
        std::cerr << "PeriodicExecutor::submit() - queue is full" << std::endl;
    }
    else {
        Task task{a_func, a_period, a_repeatCount};
        m_tasks.enqueue(task);
    }
    lock.unlock();
    m_cvIsResume.notify_all();
}

void PeriodicExecutor::pause()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_isPause = true;
    std::cout<< "pause!!\n";
}

void PeriodicExecutor::resume() 
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_isPause = false;
    m_cvIsResume.notify_all();
    std::cout<< "resume!!\n";
}

void PeriodicExecutor::run() 
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while(!m_shouldStop) {
        lock.unlock();
        Task task;
        m_tasks.dequeue(task);
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            while(m_isPause) {
                m_cvIsResume.wait(lock);
            }
        }
        try {
           task();
        } catch (std::exception const& x) {
            std::cerr << "Exception in task: " << x.what()<< ".\n" << std::endl;
            task.setRepeatCount();
        } catch (...) {
            std::cerr << "Unknow exception in task.\n" << std::endl;
            task.setRepeatCount();
        }
        if (task.m_repeatCount > 1) {
            m_tasks.enqueue(task);
        }
        if (!m_isPause) {
            m_cvIsResume.notify_all();
        }
        else {
            break;
        }
        lock.lock();
    }
}

}//mt
