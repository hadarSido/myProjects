#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "mu_test.h"
#include "data_handler.hpp"
#include "term.hpp"

BEGIN_TEST(add_data_handler_test)
	using namespace info_pair;
	DataHandler ds{10};
	ASSERT_PASS();

END_TEST

BEGIN_TEST(data_handler_add_term_test)
	using namespace info_pair;
	Term t1{"hadar"};
	DataHandler ds{10};
	ds.addTermCountIgnore(10);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(data_handler_add_term_uniqe_test)
	using namespace info_pair;
	Term t1{"hadar"};
	DataHandler ds{10};
	ds.addTermCountUniqe(10);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(data_handler_add_connnections_test)
	using namespace info_pair;
	Term t1{"hadar"};
	DataHandler ds{10};
	ds.addTermCountUniqe(10);
	URLdata ud{"Hadar", "hadar.com"};

	URLdata ud_p1{"Mashiah", "mas.com"};
	URLdata ud_p2{"Gila", "gila.com"};

	ds.addPagesConnection(ud.getURL(), {ud_p1.getURL(), ud_p2.getURL()});
	std::optional<std::vector<std::string>> per = ds.findUrlPerentsData("mas.com");

	ASSERT_PASS();

END_TEST

BEGIN_TEST(data_handler_add_and_find_connnections_test)
	using namespace info_pair;
	Term t1{"hadar"};
	Term t2{"lioz"};
	Term t3{"hod"};
	DataHandler ds{10};
	size_t ignoreCount = 0;
	size_t uniqeCount = 0;
	size_t ignore = 10;
	size_t uniqe = 10;
	ds.addTermCountIgnore(ignore);
	ignoreCount += ignore;
	ds.addTermCountUniqe(uniqe);
	uniqeCount += uniqe;
	size_t i1 = ds.findTermCountIgnore();
	size_t u1 = ds.findTermCountUniqe();
	ASSERT_EQUAL(i1, ignoreCount);
	ASSERT_EQUAL(u1, uniqeCount);

	ignore = 1;
	uniqe= 15;
	ds.addTermCountIgnore(ignore);
	ignoreCount += ignore;
	ds.addTermCountUniqe(uniqe);
	uniqeCount += uniqe;
	size_t i2 = ds.findTermCountIgnore();
	size_t u2 = ds.findTermCountUniqe();
	ASSERT_EQUAL(i2, ignoreCount);
	ASSERT_EQUAL(u2, uniqeCount);

	ignore = 3;
	uniqe = 2;
	ds.addTermCountIgnore(ignore);
	ignoreCount += 3;
	ds.addTermCountUniqe(uniqe);
	uniqeCount += uniqe;
	size_t i3 = ds.findTermCountIgnore();
	size_t u3 = ds.findTermCountUniqe();
	ASSERT_EQUAL(i3, ignoreCount);
	ASSERT_EQUAL(u3, uniqeCount);

END_TEST





TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(add_data_handler_test)
	TEST(data_handler_add_term_test)
	TEST(data_handler_add_term_uniqe_test)
	TEST(data_handler_add_connnections_test)
	TEST(data_handler_add_and_find_connnections_test)

END_SUITE

