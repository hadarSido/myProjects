#include "waitable_queue.hpp" //header file

namespace advcpp {

template<typename T, typename Queue>
WaitableQueue<T, Queue>::WaitableQueue(size_t a_capacity)
: m_queue()
, m_capacity(a_capacity)
, m_mutex()
, m_cvNotFull()
, m_cvNotEmpty()
{}

template<typename T, typename Queue>
bool WaitableQueue<T, Queue>::empty() const
{
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.empty();
}

template<typename T, typename Queue>
size_t WaitableQueue<T, Queue>::size() const
{
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.size();
}

template<typename T, typename Queue>
bool WaitableQueue<T, Queue>::full() const
{
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_capacity == m_queue.size();
}

template<typename T, typename Queue>
void WaitableQueue<T, Queue>::enqueue(T const& a_item)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while(innerFull()) {
        m_cvNotFull.wait(lock);
    }
    m_queue.push(a_item);
    m_cvNotEmpty.notify_all();
}

template<typename T, typename Queue>
template<typename Q>
typename std::enable_if<std::is_same<Q, std::priority_queue<T>>::value, void>::type
WaitableQueue<T, Queue>::dequeue(T& a_item)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while(innerEmpty()) {
        m_cvNotEmpty.wait(lock);
    }
    a_item = m_queue.top();
    m_queue.pop();
    m_cvNotFull.notify_all();
}

template<typename T, typename Queue>
template<typename Q>
typename std::enable_if<std::is_same<Q, std::queue<T>>::value, void>::type
WaitableQueue<T, Queue>::dequeue(T& a_item)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while(innerEmpty()) {
        m_cvNotEmpty.wait(lock);
    }
    a_item = m_queue.front();
    m_queue.pop();
    m_cvNotFull.notify_all();
}

template<typename T, typename Queue>
bool WaitableQueue<T, Queue>::innerFull() const noexcept 
{
    return m_capacity == m_queue.size();
}

template<typename T, typename Queue>
bool WaitableQueue<T, Queue>::innerEmpty() const noexcept 
{
    return m_queue.empty();
}


}//advcpp