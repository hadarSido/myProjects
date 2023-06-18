#include "mu_test.h"

#include <string>

#include "page.hpp"

BEGIN_TEST( create_page_wrong_link )
    std::string wrongLink("htps://harrypotter.fandom.com/wiki/Main_Page");
    try {
        info_pair::Page myPage(wrongLink);
    }
    catch(std::exception const& e) {
        TRACER << e.what();
        ASSERT_PASS();
    }
END_TEST

BEGIN_TEST( create_page_valid_link )
    std::string validLink("https://harrypotter.fandom.com/wiki/Main_Page");
    try {
        info_pair::Page myPage(validLink);
        ASSERT_PASS();
    }
    catch(std::exception const& e) {
        TRACER << e.what();
    }
END_TEST

BEGIN_TEST( add_links )
    std::string validLink("https://harrypotter.fandom.com/wiki/Main_Page");
    try {
        info_pair::Page myPage(validLink);
        std::string url1("https://harrypotter.fandom.com/wiki/Harry_Potter");
        std::string url2("https://harrypotter.fandom.com/wiki/Hermione_Granger");
        //std::string wrongUrl("htps://harrypotter.fandom.com/wiki/Hermione_Granger");
        bool ok = myPage.addLink(url1);
        myPage.addLink(url2);
        //bool answer = myPage.addLink(wrongUrl);
        size_t size = myPage.links().size();
        ASSERT_EQUAL(size, 2);
        ASSERT_EQUAL(ok, true);
        //ASSERT_EQUAL(answer, false);
    }
    catch(std::exception const& e) {
        TRACER << e.what();
    }
END_TEST

BEGIN_TEST( add_words )
    std::string validLink("https://harrypotter.fandom.com/wiki/Main_Page");
    try {
        info_pair::Page myPage(validLink);
        std::string hello("hello");
        std::string he1llo("he1llo");
        std::string he("he");
        std::string h1234("1234");
        std::string phello(",hello");
        std::string hellop("hello.");
        std::string helloppp("hello!!!!!!!!!!!!");

        bool ok = myPage.addWord(hello);
        bool answer = myPage.addWord(he1llo);
        myPage.addWord(he);
        myPage.addWord(h1234);
        myPage.addWord(phello);
        myPage.addWord(hellop);
        myPage.addWord(helloppp);

        for (auto w: myPage.words()) {
            TRACER << w << "\n";
        }
        
        size_t size = myPage.words().size();
        ASSERT_EQUAL(size, 4);
        ASSERT_EQUAL(ok, true);
        ASSERT_EQUAL(answer, false);
    }
    catch(std::exception const& e) {
        TRACER << e.what();
    }
END_TEST

TEST_SUITE()
	IGNORE_TEST( create_page_wrong_link )
    TEST( create_page_valid_link )
    TEST( add_links )
    TEST( add_words )
    
END_SUITE