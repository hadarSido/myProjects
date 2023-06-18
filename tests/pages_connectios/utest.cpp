#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "mu_test.h"
#include "pages_connection.hpp"

BEGIN_TEST(add_pages_connectiona_test)
	using namespace info_pair;
	PagesConnection pc{10};
	ASSERT_PASS();

END_TEST

BEGIN_TEST(add_pages_connectiona_addUrl_test)
	using namespace info_pair;
	PagesConnection pc{10};
	size_t index = pc.addUrl("hadar.com");
	ASSERT_EQUAL(index, 0);

END_TEST

BEGIN_TEST(add_pages_connectiona_add_perents_add_childrens_test)
	using namespace info_pair;
	PagesConnection pc{30};
	size_t index1 = pc.addUrl( "lioz.com");
	size_t index2 = pc.addUrl( "hod.com");
	size_t index3 = pc.addUrl("eitan.com");
	size_t index4 = pc.addUrl( "mimi.com");

	pc.addUrlPerents(index1, index3);
	pc.addUrlchildrens(index1, index2);
	pc.addUrlPerents(index2, index1);
	pc.addUrlPerents(index1, index4);

	std::vector<size_t> liozPerCheck = {index3, index4};
	std::vector<size_t> liozChildCheck = {index2};

	std::vector<size_t> liozPer = pc.getPerents(index1);
	std::cout << index1 << std::endl;
	for(size_t i = 0; i < liozPer.size(); ++i) {
		std::cout << liozPer[i] << std::endl;
		ASSERT_EQUAL(liozPerCheck[i], liozPer[i]);
	}

	std::vector<size_t> liozChild = pc.getChildrens(index1);
	for(size_t i = 0; i < liozChild.size(); ++i) {
		std::cout << liozChild[i] << std::endl;
		ASSERT_EQUAL(liozChildCheck[i], liozChild[i]);
	}

	ASSERT_EQUAL(index1, 0);
	ASSERT_EQUAL(index2, 1);
	ASSERT_EQUAL(index3, 2);
	ASSERT_PASS();

END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(add_pages_connectiona_test)
	TEST(add_pages_connectiona_addUrl_test)
	TEST(add_pages_connectiona_add_perents_add_childrens_test)

END_SUITE

