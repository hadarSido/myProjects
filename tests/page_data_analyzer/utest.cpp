#include "mu_test.h"

#include "page.hpp"
#include "url_data_download.hpp"
#include "page_data_analyzer.hpp"

BEGIN_TEST( single_page_analyze )
    std::string link("https://harrypotter.fandom.com/wiki/Albus_Dumbledore");
    try {
        TRACER << "create a downloader... \n";
        info_pair::UrlDataDownload d;

        TRACER << "download html data... \n";
        std::string htmlData = d.download(link);

        //TRACER << "DATA \n\n" << htmlData << "\n\n\n\n";

        TRACER << "create analyzer... \n";
        info_pair::PageDataAnalyzer pa;

        TRACER << "create page... \n";
        info_pair::Page pageHarry(link, 0);

        TRACER << "analyzing data... \n";
        bool ok = pa.analyzeThat(htmlData, pageHarry);

        std::string title = pageHarry.title();
        TRACER << "title = " << title << "\n"; 

        std::vector<std::string> vec = pageHarry.links();
        size_t counter = 0;
        // for (size_t i=0; i<vec.size(); ++i) {
        //     //std::cout << i << vec[i] << "\n";
        // }

        size_t linkSize = pageHarry.links().size();
        TRACER << "links = " << linkSize << "\n"; 

        std::vector<std::string> vecW = pageHarry.words();

        for (size_t i=0; i<vecW.size(); ++i) {
            //std::cout << i << vecW[i] << "\n";
            if(vecW[i] == "Hogwarts") {
                ++counter;
            }
        }

        size_t wordSize = pageHarry.words().size();
        TRACER << "words = " << wordSize << "\n";

        TRACER << "ok?! \n";
        ASSERT_THAT(ok);
        TRACER << "counter = " << counter << "\n";
        
        
    }
    catch(std::exception const& e) {
        TRACER << e.what();
    }
    
END_TEST

BEGIN_TEST( single_page_analyze2 )
    std::string link("https://harrypotter.fandom.com/wiki/Harry_Potter_and_the_Half-Blood_Prince_(video_game)");
    try {
        TRACER << "create a downloader... \n";
        info_pair::UrlDataDownload d;

        TRACER << "download html data... \n";
        std::string htmlData = d.download(link);

        //TRACER << "DATA \n\n" << htmlData << "\n\n\n\n";

        TRACER << "create analyzer... \n";
        info_pair::PageDataAnalyzer pa;

        TRACER << "create page... \n";
        info_pair::Page pageHarry(link, 0);

        TRACER << "analyzing data... \n";
        bool ok = pa.analyzeThat(htmlData, pageHarry);

        std::string title = pageHarry.title();
        TRACER << "title = " << title << "\n"; 

        std::vector<std::string> vec = pageHarry.links();
        size_t counter = 0;
        // for (size_t i=0; i<vec.size(); ++i) {
        //     //std::cout << i << vec[i] << "\n";
        // }

        size_t linkSize = pageHarry.links().size();
        TRACER << "links = " << linkSize << "\n"; 

        std::vector<std::string> vecW = pageHarry.words();

        for (size_t i=0; i<vecW.size(); ++i) {
            //std::cout << i << vecW[i] << "\n";
            if(vecW[i] == "Hogwarts") {
                ++counter;
            }
        }

        size_t wordSize = pageHarry.words().size();
        TRACER << "words = " << wordSize << "\n";

        TRACER << "ok?! \n";
        ASSERT_THAT(ok);
        TRACER << "counter = " << counter << "\n";
        
        
    }
    catch(std::exception const& e) {
        TRACER << e.what();
    }
    
END_TEST

BEGIN_TEST( analyze_example_html_data )
    std::string link("https://harrypotter.fandom.com/wiki/Main_Page");
    try {
        
        std::string htmlData = R"(<!DOCTYPE html> 
                <html>
                    <head>
                        <title>Example Page Title</title>
                    </head>
                    <body>
                        <h1>header </h1>
                        <p>This is a sample paragraph with words to count .</p>
                        <a href="https://harrypotter.fandom.com/wiki/Main_Page">Link 1</a>
                        <a href="https://harrypotter.fandom.com/wiki/Main_Page">Link 2</a>
                    </body>
                </html>
                )";

        TRACER << "create analyzer... \n";
        info_pair::PageDataAnalyzer pa;

        TRACER << "create page... \n";
        info_pair::Page pageExample(link, 0);

        TRACER << "analyzing data... \n";
        bool ok = pa.analyzeThat(htmlData, pageExample);

        size_t linkSize = pageExample.links().size();
        TRACER << "links = " << linkSize << "\n"; 
        ASSERT_EQUAL(linkSize, 2);

        std::string title = pageExample.title();
        TRACER << "title = " << title << "\n"; 
        ASSERT_EQUAL(title, "Example Page Title");

        size_t wordSize = pageExample.words().size();
        ASSERT_EQUAL(wordSize, 6);

        

        TRACER << "ok = "<< ok << " \n";
        ASSERT_THAT(ok);
        
        
    }
    catch(std::exception const& e) {
        TRACER << e.what();
    }
END_TEST

TEST_SUITE()
    TEST( single_page_analyze )
    //TEST( single_page_analyze2 )
    //TEST( analyze_example_html_data )
    
END_SUITE
