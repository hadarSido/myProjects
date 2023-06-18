#include "mu_test.h"
#include <memory>
#include <string>
#include <iostream>

#include "url_data_loader.hpp"

BEGIN_TEST( test_load_url_data_to_string_ptr )
    InfoPair::UrlDataLoader loader;
    std::string url("https://harrypotter.fandom.com/wiki/Main_Page");
    std::shared_ptr<std::string> data = std::make_shared<std::string>();
    loader.getBody(url, data);
    TRACER << "DATA: " << *data;
    std::string searchStr("<!DOCTYPE html>");
    size_t answer = data->find(searchStr);
    ASSERT_EQUAL(answer, !std::string::npos);

END_TEST


TEST_SUITE()
    TEST( test_load_url_data_to_string_ptr )

    
END_SUITE