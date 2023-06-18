#include "mu_test.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstddef>
#include <climits>
#include <list>

#include "generic_utils.hpp"
#include "algorithms.hpp"


BEGIN_TEST(vector_int_reverse_test)
    using namespace advcpp;
    std::vector<int> vec = {1, 2, 3, 4};
    std::cout << vec;
    reverse(vec.begin(), vec.end());
    std::cout << vec;
    ASSERT_PASS();
END_TEST

BEGIN_TEST(list_int_reverse_test)
    using namespace advcpp;
    std::list<std::string> lst = {"Someone", "told", "me", "long", "ago", "There's", "a", "calm ", "before", "the", "storm"};
    std::cout << lst;
    reverse(lst.begin(), lst.end());
    std::cout << lst;
    ASSERT_PASS();    
END_TEST

BEGIN_TEST(arr_int_reverse_test)
    using namespace advcpp;
    std::array<int,4> arr = {1, 2, 3, 4};
    std::cout << arr;
    reverse(arr.begin(), arr.end());
    std::cout << arr;
    ASSERT_PASS();    
END_TEST

BEGIN_TEST(arr_str_reverse_test)
    using namespace advcpp;
    std::array<std::string,11> arr = {"Someone", "told", "me", "long", "ago", "There's", "a", "calm ", "before", "the", "storm"};
    std::cout << arr;
    reverse(arr.begin(), arr.end());
    std::cout << arr;
    ASSERT_PASS();    
END_TEST


BEGIN_TEST(vector_int_reverse_test_enable_if)
    using namespace advcpp;
    std::vector<int> vec = {1, 2, 3, 4};
    std::cout << vec;
    reverse(vec.begin(), vec.end());
    std::cout << std::endl;
    std::cout << vec;
    ASSERT_PASS();
END_TEST

BEGIN_TEST(list_int_reverse_test_enable_if)
    using namespace advcpp;
    std::list<std::string> lst = {"Someone", "told", "me", "long", "ago", "There's", "a", "calm ", "before", "the", "storm"};
    std::cout << lst;
    reverse(lst.begin(), lst.end());
    std::cout << std::endl;
    std::cout << lst;
    ASSERT_PASS();   
END_TEST

BEGIN_TEST(vector_int_sum_by_operator)
    using namespace advcpp;
    std::vector<int> vec = {1, 2, 3, 4};
    std::cout << vec;
    int result = reduce(vec.begin(), vec.end(), 0, Adder{});
    std::cout <<  result << std::endl;
    ASSERT_PASS();   
END_TEST

BEGIN_TEST(vector_str_sum_by_operator)
    using namespace advcpp;
    std::vector<std::string> vec = {"Someone", "told", "me"};
    std::string str = "III";
    std::cout << vec;
    std::string result = reduce(vec.begin(), vec.end(), str, Adder{});
    std::cout <<  result << std::endl;
    ASSERT_PASS();   
END_TEST


BEGIN_TEST(vector_float_sum_by_operator)
    using namespace advcpp;
    std::vector<float> vec = {1.2, 2.4, 3.9, 4.1};
    std::cout << vec;
    float result = reduce(vec.begin(), vec.end(), 1.0F, Adder{});
    std::cout <<  result << std::endl;
    ASSERT_PASS();   
END_TEST



TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(vector_int_reverse_test)
    TEST(list_int_reverse_test)
    TEST(arr_int_reverse_test)
    TEST(arr_str_reverse_test)
    TEST(vector_int_reverse_test_enable_if)
    TEST(list_int_reverse_test_enable_if)
    TEST(vector_int_sum_by_operator)
    TEST(vector_float_sum_by_operator)
END_SUITE
