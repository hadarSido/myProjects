#include "mu_test.h"

#include "query.hpp"
#include "term.hpp"


BEGIN_TEST( add_term_test )
    using namespace info_pair;
	Query myQuery;
    
    myQuery.addWord("Hello", false);
    myQuery.addWord("WORLD", true);

    ASSERT_EQUAL(myQuery.size(), 2);

    ASSERT_EQUAL(myQuery[0].second , "hello");
    ASSERT_EQUAL(myQuery[1].second , "world");

    ASSERT_EQUAL(myQuery[0].first , false);
    ASSERT_EQUAL(myQuery[1].first , true);

END_TEST


TEST_SUITE()
	TEST( add_term_test )


END_SUITE
