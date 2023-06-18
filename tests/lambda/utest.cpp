#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include "mu_test.h"

BEGIN_TEST(fill_vector_even_numbers)
	std::vector<int> vec;
	int num = 30;
	int size = 20;
    std::generate_n(std::back_inserter(vec),
			size,             
			[n = num]() mutable { return n += 2; });
	int firstNum = 30;
	for(size_t i = 0; i < vec.size(); ++i) {
		ASSERT_EQUAL(vec[i], firstNum += 2);
	}
END_TEST


BEGIN_TEST(create_map_string_int)
	auto stringCompare = [](std::string a_str1, std::string a_str2) {
		auto up = [](std::string& s) {
			std::transform(s.begin(), s.end(),s.begin(), [](char a_c) {
				return std::tolower(a_c);
			});
			return s;
		};
		return up(a_str1) < up(a_str2);
	};
	std::map<std::string, int, decltype(stringCompare)> m(stringCompare);
	m.insert(std::make_pair("c", 4));
	ASSERT_EQUAL(m["c"], 4);
	m["C"] = 1;
	m["b"] = 2;
	ASSERT_EQUAL(m["c"], 1);
	ASSERT_EQUAL(m["b"], 2);
	ASSERT_EQUAL(m.size(), 2);
END_TEST

template<typename Container, typename T>
typename Container::const_iterator findeFirstInInterval(Container const& a_container, std::pair<T, T> const& a_interval){
    if(a_interval.second < a_interval.first){
        assert(a_interval.first > a_interval.second);
        return a_container.end();
    }
    if(a_interval.first == a_interval.second){
        return std::find(a_container.begin(), a_container.end(), a_interval.first);
    }
    return std::find_if(a_container.begin(), a_container.end(), [a_interval](T const& a_element){
        return a_interval.first <= a_element && a_element <= a_interval.second;
    });
}

BEGIN_TEST(find_first_in_interval)
	std::list<double> lst{-3.2, -1.1, 15.6, 0.1, 5.8, 3.14, 14.5, 1.15, 4.8, 4.5};
    std::list<double>::const_iterator it = findeFirstInInterval(lst, std::make_pair(-10.0, -5.0));
    ASSERT_THAT(it == lst.end());

    it = findeFirstInInterval(lst, std::make_pair(4.5, 4.5));
    ASSERT_THAT(it != lst.end());
    ASSERT_EQUAL(*it, 4.5);

    int distance = std::distance(lst.cbegin(), it);
    ASSERT_EQUAL(distance, 9);

    it = findeFirstInInterval(lst, std::make_pair(-1.0, 1.8));
    ASSERT_THAT(it != lst.end());
    ASSERT_EQUAL(*it, 0.1);

END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(fill_vector_even_numbers)
	TEST(create_map_string_int)
	TEST(find_first_in_interval)
END_SUITE
