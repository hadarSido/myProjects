#include "mu_test.h"
#include <memory>
#include <string>
#include <iostream>

#include "url_data_download.hpp"

BEGIN_TEST( test_downloading_html_string_form_url )
    info_pair::UrlDataDownload ud;
    std::string url("https://harrypotter.fandom.com/wiki/Main_Page");
    std::string data = ud.download(url);
    //TRACER << "DATA: " << data;
    std::string searchStr("<!DOCTYPE html>");
    size_t answer = data.find(searchStr);
    ASSERT_THAT(answer != std::string::npos);
END_TEST


TEST_SUITE()
    TEST( test_downloading_html_string_form_url )

    
END_SUITE