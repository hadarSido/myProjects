#pragma once
#include <queue> // queue
#include <mutex> // mutex
#include <condition_variable> //condition variable

namespace advcpp {

template<typename T, typename Queue = std::queue<T>>
class WaitableQueue {
public:                                                            
    explicit WaitableQueue(size_t a_capacity);  
    ~WaitableQueue() = default;
    WaitableQueue(const WaitableQueue &a_other) = delete;                                      
    WaitableQueue& operator=(const WaitableQueue &a_other) = delete;    

    void enqueue(T const& a_item); 

    template<typename Q = Queue>
    typename std::enable_if<std::is_same<Q, std::queue<T>>::value, void>::type
    dequeue(T& a_item);

    template<typename Q = Queue>
    typename std::enable_if<std::is_same<Q, std::priority_queue<T>>::value, void>::type
    dequeue(T& a_item);

    bool empty() const; 
    bool full() const;
    size_t size() const; 

private:
    bool innerFull() const noexcept;
    bool innerEmpty() const noexcept;  

private:
    Queue m_queue;
    size_t m_capacity;
    mutable std::mutex m_mutex;
    std::condition_variable m_cvNotFull;
    std::condition_variable m_cvNotEmpty;

};

}//advcpp

#include "inl/waitable_queue.hxx"


