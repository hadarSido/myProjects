#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <cmath> //pow
#include "algos.hpp"
#include "mu_test.h"

BEGIN_TEST(sort_a_vector_of_pointes)
	using namespace advcpp;
	std::vector<std::pair<double, double>> vec = {{2.1, 4.3}, {0.1, 0.4}, {3.3, 1.0}, {10.0, 11.1}, {2.2, 1.0}};
	printPointsVector(vec);
	sortPointsByDistance(vec);
	printPointsVector(vec);
	ASSERT_THAT(vec[0] == std::make_pair(0.1, 0.4));
	ASSERT_THAT(vec[4] == std::make_pair(10.0, 11.1));
	
END_TEST

BEGIN_TEST(sort_a_vector_of_pointes_in_range)
	using namespace advcpp;
	std::vector<std::pair<double, double>> vec = {{2.1, 4.3}, {0.1, 0.4}, {3.3, 1.0}, {10.0, 11.1}, {2.2, 1.0}};
	printPointsVector(vec);
	sortPointsByRange(vec, 2, 8);
	printPointsVector(vec);
	ASSERT_THAT(vec[0] == std::make_pair(2.2, 1.0));
	ASSERT_THAT(vec[4] == std::make_pair(10.0, 11.1));
	
END_TEST


BEGIN_TEST(add_from_list_to_vector_eve_numa_and_power_by_3)
	using namespace advcpp;
	std::list<int> lst = {2, 5, 6, 6, 7 ,9 ,0 ,10 ,12, 0};
	std::vector<double> vec = thirdPowerOfEvenNumbersFromList(lst);
	printVector(vec);
	ASSERT_THAT(vec[0] == std::pow(2,3));
	ASSERT_THAT(vec[1] == std::pow(6,3));
	ASSERT_THAT(vec[vec.size()-1] == std::pow(0,3));
	
END_TEST

BEGIN_TEST(quadratic_equations)
    using namespace advcpp;
    std::vector<std::tuple<double, double, double>> vec = {{2, 5, -3}, {1, 0, 4}, {3, 1, 0}, {10, 0, 11}, {2, 2, 1}};
    std::list<QuadraticRoots> lst = solveQuadraticEquations(vec);
    for (std::list<QuadraticRoots>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
		if (*it) {
			std::cout << "Roots: " << (*it)->first << ", " << (*it)->second << std::endl;
		}
		else {
			std::cout << "No real roots" << std::endl;
		}
	}
	ASSERT_THAT(lst.front().value().first == 0.5);
	ASSERT_THAT(lst.front().value().second == -3);
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(sort_a_vector_of_pointes)
	TEST(sort_a_vector_of_pointes_in_range)
	TEST(add_from_list_to_vector_eve_numa_and_power_by_3)
	TEST(quadratic_equations)

END_SUITE
