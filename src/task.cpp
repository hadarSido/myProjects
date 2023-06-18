#include "task.hpp"

namespace mt {
namespace implementation_details {

Task::Task(std::function<bool()> a_func, std::chrono::milliseconds a_period)
: m_boolFunc(a_func)
, m_voidFunc()
, m_repeatCount(1)
, m_period(a_period)
, m_startTime(m_period + std::chrono::steady_clock::now())
{}

Task::Task(std::function<void()> a_func, std::chrono::milliseconds a_period)
: m_boolFunc()
, m_voidFunc(a_func)
, m_repeatCount(1)
, m_period(a_period)
, m_startTime(m_period + std::chrono::steady_clock::now())
{}

Task::Task(std::function<void()> a_func, std::chrono::milliseconds a_period, uint64_t a_repeatCount)
: m_boolFunc()
, m_voidFunc(a_func)
, m_repeatCount(a_repeatCount)
, m_period(a_period)
, m_startTime(m_period + std::chrono::steady_clock::now())
{}

void Task::operator()()
{
    if (m_boolFunc) {
        m_boolFunc();
    }
    else if (m_voidFunc) {
        m_voidFunc();
    }
    setRunTime();
}

bool Task::operator<(const Task& a_other) const 
{
    return m_startTime > a_other.m_startTime;
}

void Task::setRunTime() {
    if(m_repeatCount > 1){
        m_startTime += m_period;
        --m_repeatCount;
    }
}

void Task::setRepeatCount() {
    m_repeatCount = 0;
}

}//namespace implementation_details 
} // namespace mt

