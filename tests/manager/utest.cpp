#include <string>
#include <array>
#include <tuple> //tuple return
#include "mu_test.h"
#include "manager.hpp"

BEGIN_TEST(add_manager_test)
	using namespace info_pair;
	Manager m{"../../json/long.json"};
	m.run();
	ASSERT_PASS();

END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(add_manager_test)
END_SUITE

