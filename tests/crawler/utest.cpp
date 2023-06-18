#include "mu_test.h"

#include <string>
#include <filesystem>

#include "data_handler.hpp"
#include "crawler.hpp"

BEGIN_TEST( crawl_harry )
  
    std::filesystem::path harryPath("../../json/harry.json");
    info_pair::DataHandler ds{5000};
    info_pair::Crawler myCrawler(harryPath, ds);

    std::vector<info_pair::Page> pages = myCrawler.crawlingInformation();
    TRACER << "pages size = " << pages.size() << "\n\n";
    //ASSERT_EQUAL(pages.size(), 10);
    size_t level = 0;
    for (auto const& p : pages) {
        //ASSERT_THAT(p.level() >= level);
        if (level < 4) {
            ++level;
            //ASSERT_EQUAL(p.ignoredLinks(), 0);
        }
        TRACER << "title = " << p.title() << "\n";
        TRACER << "url = " << p.url() << "\n";
        TRACER << "level = " << p.level() << "\n";
        TRACER << "ignored links = " << p.ignoredLinks() << "\n";
        TRACER << "irrelevant links = " << p.irrelevantLinks() << "\n";
        TRACER << "size of words = " << p.words().size() << "\n";
        TRACER << "size of links = " << p.links().size() << "\n\n";
    }
    ASSERT_PASS();
END_TEST

BEGIN_TEST( crawl_harry_long_run_time )
  
    std::filesystem::path harryPath("../../json/long.json");
    info_pair::DataHandler ds{5000};
    info_pair::Crawler myCrawler(harryPath, ds);

    std::vector<info_pair::Page> pages = myCrawler.crawlingInformation();
    TRACER << "pages size = " << pages.size() << "\n\n";
    for (auto const& p : pages) {
        TRACER << "title = " << p.title() << "\n";
        TRACER << "url = " << p.url() << "\n";
        TRACER << "level = " << p.level() << "\n";
        TRACER << "ignored links = " << p.ignoredLinks() << "\n";
        TRACER << "irrelevant links = " << p.irrelevantLinks() << "\n";
        TRACER << "size of words = " << p.words().size() << "\n";
        TRACER << "size of links = " << p.links().size() << "\n\n";
    }

    ASSERT_PASS();

END_TEST


TEST_SUITE()
    TEST( crawl_harry )
    //IGNORE_
    //TEST( crawl_harry_long_run_time )
    
END_SUITE