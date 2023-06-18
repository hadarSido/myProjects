#pragma once
#include <chrono> //time
#include <functional>
namespace mt {

namespace implementation_details {

class Task {
public:
    explicit Task(std::function<bool()> a_func, std::chrono::milliseconds a_period);
    explicit Task(std::function<void()> a_func, std::chrono::milliseconds a_period);
    explicit Task(std::function<void()> a_func, std::chrono::milliseconds a_period ,uint64_t a_repeatCount);
    Task() = default;
    ~Task() = default;
    Task(const Task& a_other) = default;
    Task& operator=(const Task& a_other) = default;

    void operator()();
    bool operator<(const Task& a_other) const;

    void setRunTime();
    void setRepeatCount();

    std::function<bool()> m_boolFunc;
    std::function<void()> m_voidFunc;
    uint64_t m_repeatCount;
    std::chrono::milliseconds m_period;
    std::chrono::steady_clock::time_point m_startTime;
};

}//namespace implementation_details
} // namespace mt

