#include <vector> //cheack if consumer is ok
#include <thread>
#include <algorithm> // sort 
#include "mu_test.h"
#include "waitable_queue.hpp"

class Cat{
public:         
    enum Color {
        BLACK,
        WHITE,
        RED,
        GRAY
    };

    explicit Cat(size_t a_id, Color a_color) : m_id(a_id) , m_color(a_color) {} 
    Cat() : m_id(0) , m_color(BLACK) {} 
    ~Cat() = default;
    Cat(const Cat &a_other) = default;                                      
    Cat& operator=(const Cat &a_other) = default;   
    bool operator<(const Cat &a_other) const {return m_id < a_other.m_id; };   

    operator size_t() const {return m_id;}
  
    size_t m_id;
    Color m_color;
};

bool sortCats(const Cat& cat1, const Cat& cat2) {
    if (cat1.m_color != cat2.m_color) {
        return cat1.m_color < cat2.m_color;
    }
    return cat1.m_id < cat2.m_id;
}

BEGIN_TEST(FIFO_with_one_thread_cat)
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    WaitableQueue<Cat> cats{capacity};
    for(size_t i = 0; i < capacity; ++i) {
        Cat oneCat{i, Cat::RED};
        cats.enqueue(oneCat);
    }

    ASSERT_EQUAL(cats.size(), capacity);

    for(size_t i = 0; i < capacity; ++i) {
        Cat deletedCat{0, Cat::BLACK};
        cats.dequeue(deletedCat);
        ASSERT_EQUAL(deletedCat.m_id, i);
    }
    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);

END_TEST
 

BEGIN_TEST(FIFO_with_one_consumer_and_one_producer_cat)
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    constexpr size_t numOfCats = 1'000'000;
    WaitableQueue<Cat> cats{capacity};
    bool isInOrder = true;

    std::thread producerThread ([&cats, &isInOrder, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }   
    });

    std::thread consumerThread ([&cats, &numOfCats, &isInOrder]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat != i) {
                isInOrder = false;
                break;
            }
        }
    });
    
    producerThread.join();
    consumerThread.join();

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);
    ASSERT_EQUAL(isInOrder, true);

END_TEST


BEGIN_TEST(FIFO_with_one_consumer_and_two_producer_cat)   
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    constexpr size_t numOfCats = 500'000;
    WaitableQueue<Cat> cats{capacity};
    bool isInOrder = true;
    size_t redCounter = 0;
    size_t blackCounter = 0;
    std::thread producerThread1 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread2 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::RED};
            cats.enqueue(oneCat);
        }
    });

    std::thread consumerThread ([&cats, &numOfCats, &isInOrder, &redCounter, &blackCounter]() {
        for(size_t i = 0; i < numOfCats * 2; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat.m_color == Cat::BLACK ) {
                if(deletedCat != blackCounter) {
                    isInOrder = false;
                    break;
                }
                ++blackCounter;
            }
            if(deletedCat.m_color == Cat::RED ) {
                if(deletedCat != redCounter) {
                    isInOrder = false;
                    break;
                }
                ++redCounter;
            }
        }
    });
    
    producerThread1.join();
    producerThread2.join();
    consumerThread.join();

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);
    ASSERT_EQUAL(isInOrder, true);

END_TEST


BEGIN_TEST(FIFO_with_two_consumer_and_one_producer_cat)   
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    constexpr size_t numOfCats = 1'000'000;
    size_t blackCounter_1 = 0;
    size_t blackCounter_2 = 0;
    WaitableQueue<Cat> cats{capacity};
    bool isInOrder = true;
    std::vector<Cat> catsCheck_1;
    std::vector<Cat> catsCheck_2;
    std::thread producerThread ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }
    });

    std::thread consumerThread1 ([&cats, &numOfCats, &isInOrder, &blackCounter_1, &catsCheck_1]() {
        for(size_t i = 0; i < numOfCats /2; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat < blackCounter_1) {
                isInOrder = false;
                break;
            }
            blackCounter_1 = deletedCat;
            catsCheck_1.push_back(deletedCat);
        }
    });

    std::thread consumerThread2 ([&cats, &numOfCats, &isInOrder, &blackCounter_2, &catsCheck_2]() {
        for(size_t i = 0; i < numOfCats /2; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat < blackCounter_2) {
                isInOrder = false;
                break;
            }
            blackCounter_2 = deletedCat;
            catsCheck_2.push_back(deletedCat);
        }
    });

    producerThread.join();
    consumerThread1.join();
    consumerThread2.join();

    catsCheck_1.insert(catsCheck_1.end(), catsCheck_2.begin(), catsCheck_2.end());
    std::sort(catsCheck_1.begin(), catsCheck_1.end());
    for(size_t i = 0; i < catsCheck_1.size(); ++i) {
        ASSERT_EQUAL(catsCheck_1[i].m_id, i);
        ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::BLACK);
    }

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);
    ASSERT_EQUAL(isInOrder, true);

END_TEST


BEGIN_TEST(FIFO_with_4_consumer_and_4_producer_cat)   
    using namespace advcpp;
    size_t capacity = 1000;
    size_t numOfCats = 250'000;
    WaitableQueue<Cat> cats{capacity};
    bool isInOrder = true;

    std::vector<Cat> catsCheck_1;
    std::vector<Cat> catsCheck_2;
    std::vector<Cat> catsCheck_3;
    std::vector<Cat> catsCheck_4;

    size_t counter_1[4] = {0};
    size_t counter_2[4] = {0};
    size_t counter_3[4] = {0};
    size_t counter_4[4] = {0};
    
    std::thread producerThread1 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread2 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::WHITE};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread3 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::RED};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread4 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::GRAY};
            cats.enqueue(oneCat);
        }
    });

    std::thread consumerThread1([&cats, &numOfCats, &isInOrder, &counter_1, &catsCheck_1]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat < counter_1[deletedCat.m_color]) {
                    isInOrder = false;
                    break;
                }
            counter_1[deletedCat.m_color] = deletedCat;
            catsCheck_1.push_back(deletedCat);
        }
    });

    std::thread consumerThread2([&cats, &numOfCats, &isInOrder, &counter_2, &catsCheck_2]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat < counter_2[deletedCat.m_color]) {
                    isInOrder = false;
                    break;
                }
            counter_2[deletedCat.m_color] = deletedCat;
            catsCheck_2.push_back(deletedCat);
        }
    });

    std::thread consumerThread3([&cats, &numOfCats, &isInOrder, &counter_3, &catsCheck_3]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat < counter_3[deletedCat.m_color]) {
                    isInOrder = false;
                    break;
                }
            counter_3[deletedCat.m_color] = deletedCat;
            catsCheck_3.push_back(deletedCat);
        }
    });

    std::thread consumerThread4([&cats, &numOfCats, &isInOrder, &counter_4, &catsCheck_4]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat < counter_4[deletedCat.m_color]) {
                isInOrder = false;
                break;
            }
            counter_4[deletedCat.m_color] = deletedCat;
            catsCheck_4.push_back(deletedCat);
        }
    });
    
    
    producerThread1.join();
    producerThread2.join();
    producerThread3.join();
    producerThread4.join();
    consumerThread1.join();
    consumerThread2.join();
    consumerThread3.join();
    consumerThread4.join();

    catsCheck_1.insert(catsCheck_1.end(), catsCheck_2.begin(), catsCheck_2.end());
    catsCheck_1.insert(catsCheck_1.end(), catsCheck_3.begin(), catsCheck_3.end());
    catsCheck_1.insert(catsCheck_1.end(), catsCheck_4.begin(), catsCheck_4.end());

    std::sort(catsCheck_1.begin(), catsCheck_1.end(), sortCats);

    size_t j = 0;
    for(size_t i = 0; i < catsCheck_1.size(); ++i) {
    
        if( i == catsCheck_1.size()/4 || i == catsCheck_1.size()/2 || i == 3 * catsCheck_1.size()/4) {
            j = 0;
        }
        if(i < catsCheck_1.size()/4) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::BLACK);
            ++j;
        }
        else if(i >= catsCheck_1.size()/4 && i < catsCheck_1.size()/2) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::WHITE);
            ++j;
        }
        else if(i >= catsCheck_1.size()/2 && i < 3 * catsCheck_1.size()/4) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::RED);
            ++j;
        }
        else if(i >= 3 * catsCheck_1.size()/4 && i < catsCheck_1.size()) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::GRAY);
            ++j;
        }
    }
    

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);
    ASSERT_EQUAL(isInOrder, true);



    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);
    ASSERT_EQUAL(isInOrder, true);

END_TEST

BEGIN_TEST(FIFO_with_one_thread_cat_priority_queue)
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    WaitableQueue<Cat, std::priority_queue<Cat>> cats{capacity};
    for(size_t i = 0; i < capacity; ++i) {
        Cat oneCat{i, Cat::RED};
        cats.enqueue(oneCat);
    }

    ASSERT_EQUAL(cats.size(), capacity);
    size_t j = cats.size() - 1;
    for(size_t i = 0; i < capacity; ++i) {
        Cat deletedCat{0, Cat::BLACK};
        cats.dequeue(deletedCat);
        ASSERT_EQUAL(deletedCat.m_id, j);
        --j;
    }
    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);

END_TEST

BEGIN_TEST(FIFO_with_one_consumer_and_one_producer_cat_priority_queue)
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    constexpr size_t numOfCats = 1'000'000;
    WaitableQueue<Cat, std::priority_queue<Cat>> cats{capacity};
    bool isInOrder = true;

    std::thread producerThread ([&cats, &isInOrder, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }   
    });

    std::thread consumerThread ([&cats, &numOfCats, &isInOrder]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
        }
    });
    
    producerThread.join();
    consumerThread.join();

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);

END_TEST


BEGIN_TEST(FIFO_with_one_consumer_and_two_producer_cat_priority_queue)   
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    constexpr size_t numOfCats = 500'000;
    WaitableQueue<Cat, std::priority_queue<Cat>> cats{capacity};
    bool isInOrder = true;
    size_t redCounter = 0;
    size_t blackCounter = 0 ;
    std::thread producerThread1 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread2 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::RED};
            cats.enqueue(oneCat);
        }
    });

    std::thread consumerThread ([&cats, &numOfCats, &isInOrder, &redCounter, &blackCounter]() {
        for(size_t i = 0; i < numOfCats * 2; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            if(deletedCat.m_color == Cat::BLACK ) {
                ++blackCounter;
            }
            if(deletedCat.m_color == Cat::RED ) {
                ++redCounter;
            }
        }
    });
    
    producerThread1.join();
    producerThread2.join();
    consumerThread.join();

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);

END_TEST

BEGIN_TEST(FIFO_with_two_consumer_and_one_producer_cat_priority_queue)   
    using namespace advcpp;
    constexpr size_t capacity = 1000;
    constexpr size_t numOfCats = 1'000'000;
    size_t blackCounter_1 = 0;
    size_t blackCounter_2 = 0;
    WaitableQueue<Cat, std::priority_queue<Cat>> cats{capacity};
    bool isInOrder = true;
    std::vector<Cat> catsCheck_1;
    std::vector<Cat> catsCheck_2;
    std::thread producerThread ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }
    });

    std::thread consumerThread1 ([&cats, &numOfCats, &isInOrder, &blackCounter_1, &catsCheck_1]() {
        for(size_t i = 0; i < numOfCats /2; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            blackCounter_1 = deletedCat;
            catsCheck_1.push_back(deletedCat);
        }
    });

    std::thread consumerThread2 ([&cats, &numOfCats, &isInOrder, &blackCounter_2, &catsCheck_2]() {
        for(size_t i = 0; i < numOfCats /2; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            blackCounter_2 = deletedCat;
            catsCheck_2.push_back(deletedCat);
        }
    });

    producerThread.join();
    consumerThread1.join();
    consumerThread2.join();

    catsCheck_1.insert(catsCheck_1.end(), catsCheck_2.begin(), catsCheck_2.end());
    std::sort(catsCheck_1.begin(), catsCheck_1.end());
    for(size_t i = 0; i < catsCheck_1.size(); ++i) {
        ASSERT_EQUAL(catsCheck_1[i].m_id, i);
        ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::BLACK);
    }

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);

END_TEST


BEGIN_TEST(FIFO_with_4_consumer_and_4_producer_cat_priority_queue)   
    using namespace advcpp;
    size_t capacity = 1000;
    size_t numOfCats = 250'000;
    WaitableQueue<Cat, std::priority_queue<Cat>> cats{capacity};
    bool isInOrder = true;

    std::vector<Cat> catsCheck_1;
    std::vector<Cat> catsCheck_2;
    std::vector<Cat> catsCheck_3;
    std::vector<Cat> catsCheck_4;

    size_t counter_1[4] = {0};
    size_t counter_2[4] = {0};
    size_t counter_3[4] = {0};
    size_t counter_4[4] = {0};
    
    std::thread producerThread1 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::BLACK};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread2 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::WHITE};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread3 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::RED};
            cats.enqueue(oneCat);
        }
    });

    std::thread producerThread4 ([&cats, &numOfCats]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat oneCat{i, Cat::GRAY};
            cats.enqueue(oneCat);
        }
    });

    std::thread consumerThread1([&cats, &numOfCats, &isInOrder, &counter_1, &catsCheck_1]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            counter_1[deletedCat.m_color] = deletedCat;
            catsCheck_1.push_back(deletedCat);
        }
    });

    std::thread consumerThread2([&cats, &numOfCats, &isInOrder, &counter_2, &catsCheck_2]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            counter_2[deletedCat.m_color] = deletedCat;
            catsCheck_2.push_back(deletedCat);
        }
    });

    std::thread consumerThread3([&cats, &numOfCats, &isInOrder, &counter_3, &catsCheck_3]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            counter_3[deletedCat.m_color] = deletedCat;
            catsCheck_3.push_back(deletedCat);
        }
    });

    std::thread consumerThread4([&cats, &numOfCats, &isInOrder, &counter_4, &catsCheck_4]() {
        for(size_t i = 0; i < numOfCats; ++i) {
            Cat deletedCat{0, Cat::BLACK};
            cats.dequeue(deletedCat);
            counter_4[deletedCat.m_color] = deletedCat;
            catsCheck_4.push_back(deletedCat);
        }
    });
    
    
    producerThread1.join();
    producerThread2.join();
    producerThread3.join();
    producerThread4.join();
    consumerThread1.join();
    consumerThread2.join();
    consumerThread3.join();
    consumerThread4.join();

    catsCheck_1.insert(catsCheck_1.end(), catsCheck_2.begin(), catsCheck_2.end());
    catsCheck_1.insert(catsCheck_1.end(), catsCheck_3.begin(), catsCheck_3.end());
    catsCheck_1.insert(catsCheck_1.end(), catsCheck_4.begin(), catsCheck_4.end());

    std::sort(catsCheck_1.begin(), catsCheck_1.end(), sortCats);

    size_t j = 0;
    for(size_t i = 0; i < catsCheck_1.size(); ++i) {
    
        if( i == catsCheck_1.size()/4 || i == catsCheck_1.size()/2 || i == 3 * catsCheck_1.size()/4) {
            j = 0;
        }
        if(i < catsCheck_1.size()/4) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::BLACK);
            ++j;
        }
        else if(i >= catsCheck_1.size()/4 && i < catsCheck_1.size()/2) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::WHITE);
            ++j;
        }
        else if(i >= catsCheck_1.size()/2 && i < 3 * catsCheck_1.size()/4) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::RED);
            ++j;
        }
        else if(i >= 3 * catsCheck_1.size()/4 && i < catsCheck_1.size()) {
            ASSERT_EQUAL(catsCheck_1[i].m_id, j);
            ASSERT_EQUAL(catsCheck_1[i].m_color, Cat::GRAY);
            ++j;
        }
    }
    

    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);



    ASSERT_EQUAL(cats.empty(), true);
    ASSERT_EQUAL(cats.full(), false);
    ASSERT_EQUAL(cats.size(), 0);

END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
    TEST(FIFO_with_one_thread_cat)
    TEST(FIFO_with_one_consumer_and_one_producer_cat)
    TEST(FIFO_with_one_consumer_and_two_producer_cat)
    TEST(FIFO_with_two_consumer_and_one_producer_cat) 
    TEST(FIFO_with_4_consumer_and_4_producer_cat)

    TEST(FIFO_with_one_thread_cat_priority_queue)
    TEST(FIFO_with_one_consumer_and_one_producer_cat_priority_queue)
    TEST(FIFO_with_one_consumer_and_two_producer_cat_priority_queue)
    TEST(FIFO_with_two_consumer_and_one_producer_cat_priority_queue)
    TEST(FIFO_with_4_consumer_and_4_producer_cat_priority_queue) 


END_SUITE
