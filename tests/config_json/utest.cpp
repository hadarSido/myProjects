#include "mu_test.h"

#include <vector>
#include <string>

#include "config_json.hpp"


BEGIN_TEST( read_data_from_json_file )

    try {
        info_pair::ConfigJson cj("../../json/harry.json");
        std::vector<std::string> vecLinks = cj.readUrl();
        TRACER << "link: " << vecLinks.front() << "\n";
        size_t limitPages = cj.readMaxLimitPages();
        TRACER << "limit page: " << limitPages << "\n";
        size_t maxDepth = cj.readMaxDepth();
        TRACER << "max depth: " << maxDepth << "\n";
        //info_pair::Mode mode = cj.readCrawlMode();
        //TRACER << "mode: " << static_cast<std::string>(mode) << "\n";

        ASSERT_EQUAL(vecLinks.size(), 1);
        ASSERT_EQUAL(limitPages, 200);
        ASSERT_EQUAL(maxDepth, 5);
        //ASSERT_EQUAL(mode, info_pair::Mode::DFS);

    }
    catch(std::exception const& e) {
        TRACER << e.what();
    }
END_TEST


TEST_SUITE()
	TEST( read_data_from_json_file )
    
END_SUITE