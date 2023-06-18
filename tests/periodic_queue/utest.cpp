#include <vector> //cheack if consumer is ok
#include <thread>
#include <vector>
#include <algorithm> // sort 
#include <iostream>//cout
#include <chrono>//sleep, milliseconds
#include "mu_test.h"
#include "waitable_queue.hpp"
#include "periodic_executor.hpp"
#include "task.hpp"

void printTask() 
{
    std::cout<< "print_task! \n";
}

void mathTask() 
{
    std::cout<< "2 + 3 = " << 3 + 2 << "\n";
}

bool boolTask() 
{
    std::cout<< "bool_task! \n";
    return true;
}

void exceptionTask() {
    std::cout << "Exception task" << std::endl;
    throw std::runtime_error("Test exception");
}
BEGIN_TEST(periodic_executor_empty)   
    using namespace mt;
    PeriodicExecutor pe(20);
    pe.stop();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    ASSERT_EQUAL(pe.size(), 1);
END_TEST


BEGIN_TEST(periodic_executor_add_tasks_and_stop)   
    using namespace mt;
    PeriodicExecutor pe(20);
    auto stopPE = [&pe](){
        pe.stop();
    };
    for(size_t i = 0; i < 9; ++i) {
        pe.submit(printTask, std::chrono::milliseconds(10 + i));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    pe.submit(stopPE, std::chrono::milliseconds(80));
    ASSERT_PASS();

END_TEST


BEGIN_TEST(periodic_executor_add_tasks_add_vector_ot_time)   
    using namespace mt;
    std::vector<std::chrono::steady_clock::time_point> timeSaver;
    PeriodicExecutor pe(7);
    pe.submit([&timeSaver](){
        timeSaver.push_back(std::chrono::steady_clock::now());
    }, std::chrono::milliseconds(80), 8);
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    pe.stop();
    ASSERT_EQUAL(timeSaver.size(), 7);

END_TEST

BEGIN_TEST(periodic_executor_add_tasks_pause_resume)   
    using namespace mt;
    PeriodicExecutor pe(20);
    auto stopPE = [&pe](){
        pe.stop();
    };
    for(size_t i = 0; i < 9; ++i) {
        pe.submit(printTask, std::chrono::milliseconds(10 + i));
    }
    
    for(size_t i = 0; i < 4; ++i) {
        pe.submit(mathTask, std::chrono::milliseconds(10 + i + 1), 2);
    }
    for(size_t i = 0; i < 5; ++i) {
        pe.submit(boolTask, std::chrono::milliseconds(10 + i + 2), 3);
    }
    pe.pause();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    pe.resume();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    pe.submit(stopPE, std::chrono::milliseconds(80));
    ASSERT_PASS();

END_TEST



BEGIN_TEST(periodic_executor_throws_exception)
    using namespace mt;
    PeriodicExecutor pe(10);
    auto stopPE = [&pe](){
        pe.stop();
    };
    pe.submit(exceptionTask, std::chrono::milliseconds(500),3);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    pe.submit(stopPE, std::chrono::milliseconds(80));    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // pause for 3 seconds
    ASSERT_PASS();
END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
    TEST(periodic_executor_empty) 
    TEST(periodic_executor_add_tasks_and_stop)
    TEST(periodic_executor_add_tasks_add_vector_ot_time)  
    TEST(periodic_executor_add_tasks_pause_resume) 
    TEST(periodic_executor_throws_exception)
END_SUITE
