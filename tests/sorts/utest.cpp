#include <vector>
#include <iostream>
#include "mu_test.h"
#include "sorts.hpp"


BEGIN_TEST(bubble_sort_vector)
	using namespace advcpp;
	std::vector<int> vec = {3, 5 ,60 ,88 ,70 ,1 ,3 ,0};
	printVector(vec);
	ASSERT_EQUAL(isSortOK(vec), false);
	bubbleSort(vec);
	printVector(vec);
	ASSERT_EQUAL(vec[0], 0);
	ASSERT_EQUAL(isSortOK(vec), true);
	ASSERT_EQUAL(vec[vec.size()-1], 88);
	
END_TEST


BEGIN_TEST(shake_sort_vector)
	using namespace advcpp;
	std::vector<int> vec = {3, 5 ,60 ,88 ,70 ,1 ,3 ,0};
	printVector(vec);
	ASSERT_EQUAL(isSortOK(vec), false);
	shakeSort(vec);
	 printVector(vec);
	ASSERT_EQUAL(vec[0], 0);
	ASSERT_EQUAL(isSortOK(vec), true);
	ASSERT_EQUAL(vec[vec.size()-1], 88);

END_TEST


BEGIN_TEST(selection_sort_vector)
	using namespace advcpp;
	std::vector<int> vec = {3, 5 ,60 ,88 ,70 ,1 ,3 ,0};
	printVector(vec);
	ASSERT_EQUAL(isSortOK(vec), false);
	selectionSort(vec);
	printVector(vec);
	ASSERT_EQUAL(vec[0], 0);
	ASSERT_EQUAL(isSortOK(vec), true);
	ASSERT_EQUAL(vec[vec.size()-1], 88);

END_TEST





TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(bubble_sort_vector)
	TEST(shake_sort_vector)
	TEST(selection_sort_vector)
END_SUITE
