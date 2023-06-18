#include "mu_test.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstddef>
#include <climits>
#include <list>

#include "generic_utils.hpp"

BEGIN_TEST(vector_int_test)
    using namespace advcpp;
    std::vector<int> v = {1, 2, 3, 4};
    std::cout << v;
    ASSERT_PASS();
END_TEST

BEGIN_TEST(vector_char_test)
    using namespace advcpp;
    std::vector<int> v = {'j', 'a', 's', 't'};
    std::cout << v;
    ASSERT_PASS();
END_TEST

BEGIN_TEST(vector_string_test)
    using namespace advcpp;
    std::vector<std::string> s = {"Hadar", "Lioz" };
    std::cout << s;

    ASSERT_PASS();
END_TEST

BEGIN_TEST(find_min_string)
    using namespace advcpp;
    std::list<std::string> lst = {"Someone", "told", "me", "long", "ago", "There's", "a", "calm ", "before", "the", "storm"};
    std::list<std::string>::iterator r = minimal(lst.begin(), lst.end());
    std::cout << *r << std::endl; 
   
    ASSERT_EQUAL(*r, "Someone");    
END_TEST

BEGIN_TEST(find_min_vector_int)
    using namespace advcpp;
    std::vector<int> v = {5, 2, 3, 4};
    std::vector<int>::iterator r = minimal(v.begin(), v.end());
    std::cout << *r << std::endl;
    ASSERT_EQUAL(*r, 2);
END_TEST

BEGIN_TEST(find_sum_vector_int)
    using namespace advcpp;
    std::vector<int> v = {5, 2, 3, 4};
    int r = sum<int>(v.begin(), v.end());
    std::cout << r << std::endl;
    
    ASSERT_EQUAL(r, 14);
END_TEST


BEGIN_TEST(find_sum_list_double)
    using namespace advcpp;
    std::list<double> l = {1.1, 2.2, 3.3, 4.4};
    double r = sum<double>(l.begin(), l.end());
    std::cout << r << std::endl;

    ASSERT_EQUAL(r, 11);

END_TEST

BEGIN_TEST(find_sum_list_string)
    using namespace advcpp;
    std::list<std::string> l = {"C++ ", "is a ", "hard ", "language!"};
    std::string const& r = sum<std::string>(l.begin(), l.end());
    std::cout << r << std::endl;

    ASSERT_PASS();
END_TEST

BEGIN_TEST(find_first_unicque_vector)
    using namespace advcpp;
    std::vector<int> v = {1,2,3,4,5,6,7};
    std::vector<int>::iterator r = firstUnique(v.begin(), v.end());
    std::cout << *r << std::endl;

    ASSERT_EQUAL(*r, 1);
END_TEST


/************************************************************************/

// BEGIN_TEST(vector_int_reverse_test)
//     using namespace advcpp;
//     std::vector<int> vec = {1, 2, 3, 4};
//     std::cout << vec;
//     reverse(vec.begin(), vec.end());
//     std::cout << vec;
//     ASSERT_PASS();
// END_TEST




TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(vector_int_test)
	TEST(vector_char_test)
	TEST(vector_string_test)
	TEST(find_min_string)
	TEST(find_min_vector_int)
    TEST(find_sum_vector_int)
    TEST(find_sum_list_double)
    TEST(find_sum_list_string)
    TEST(find_first_unicque_vector)
    //TEST(vector_int_reverse_test)



END_SUITE




