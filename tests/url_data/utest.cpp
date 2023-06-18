#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "mu_test.h"
#include "url_data.hpp"

BEGIN_TEST(add_url_data_test)
	using namespace info_pair;
	URLdata data("Hadar", "hadar.com");

	ASSERT_EQUAL(data.getTitle(), "Hadar");
	ASSERT_EQUAL(data.getURL(), "hadar.com");

END_TEST

BEGIN_TEST(add_url_data_vector_test)
	using namespace info_pair;
	URLdata data1("Hadar", "hadar.com");
	URLdata data2("Chaya", "chaya.com");
	URLdata data3("Or", "or.com");
	URLdata data4("Adaya", "adaya.com");
	URLdata data5("Tomer", "tomer.com");
	std::vector<URLdata> data;
	data.push_back(data1);
	data.push_back(data2);
	data.push_back(data3);
	data.push_back(data4);
	data.push_back(data5);
	std::array<std::string , 5> titles = {"Hadar", "Chaya", "Or", "Adaya", "Tomer"};
	std::array<std::string , 5> urls = {"hadar.com", "chaya.com", "or.com", "adaya.com", "tomer.com"};
	size_t i = 0;
	for(auto& d : data) {
		ASSERT_EQUAL(d.getTitle(), titles[i]);
		ASSERT_EQUAL(d.getURL(), urls[i]);
		++i;
	}
	
END_TEST

BEGIN_TEST(add_url_data_map_value_test)
	using namespace info_pair;
	URLdata data1("Hadar", "hadar.com");
	URLdata data2("Chaya", "chaya.com");
	URLdata data3("Or", "or.com");
	URLdata data4("Adaya", "adaya.com");
	URLdata data5("Tomer", "tomer.com");
	std::map<std::string, URLdata> data;
	data["Hadar"] = data1;
	data["Chaya"] = data2;
	data["Or"] = data3;
	data["Adaya"] = data4;
	data["Tomer"] = data5;
	std::array<std::string , 5> titles = {"Adaya", "Chaya", "Hadar",  "Or", "Tomer"};
	std::array<std::string , 5> urls = {"adaya.com", "chaya.com", "hadar.com", "or.com", "tomer.com"};
	size_t i = 0;
	for(auto& d : data) {
		ASSERT_EQUAL(d.second.getTitle(), titles[i]);
		ASSERT_EQUAL(d.second.getURL(), urls[i]);

		ASSERT_EQUAL(d.first, titles[i]);
		++i;
	}
	
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(add_url_data_test)
	TEST(add_url_data_vector_test)
	TEST(add_url_data_map_value_test)

END_SUITE

