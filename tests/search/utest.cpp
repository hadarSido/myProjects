#include <string>
#include <array>
#include <tuple> //tuple return
#include "mu_test.h"
#include "search.hpp"
#include "term.hpp"
#include "query.hpp"
#include "data_handler.hpp"

BEGIN_TEST(add_search_test)
	using namespace info_pair;
	DataHandler ds{12};
	Search s{ds};
	ASSERT_PASS();

END_TEST

BEGIN_TEST(data_handler_add_and_find_connnections_perents_test)
	using namespace info_pair;
	DataHandler ds{12};
	URLdata url1{"ex1","http://www.example1.com"};
	URLdata url2{"ex2","http://www.example2.com"};
	URLdata url3{"ex3","http://www.example3.com"};
	URLdata url4{"ex4","http://www.example4.com"};
	URLdata url5{"ex5","http://www.example5.com"};
	URLdata url6{"ex6","http://www.example6.com"};
	std::array<std::string, 6> dataUrl = {"http://www.example1.com", "http://www.example2.com", "http://www.example3.com", "http://www.example4.com", "http://www.example5.com", "http://www.example6.com"};
	std::array<std::string, 10> data = { "hadar", "lioz", "hod", "sido", "gaon", "malchoto", "tal", "roni", "aviad", "masihah"};
	std::array<URLdata, 6> dataUrlAll = {url1, url2, url3, url4, url5, url6};
	size_t j = 0;
	for(size_t i = 0; i < data.size(); ++i) {
		Term t{data[i]};
		ds.addTermCountIgnore(i + 2);
		ds.addTermCountUniqe(i + 1);
		ds.addTermUrlData(t, dataUrlAll[j]);
		if(j == 5) {
			j = 0;
		}
	}

	std::vector<std::string> childrens1 = {dataUrl[4], dataUrl[5]};
	bool isOK1 = ds.addPagesConnection(dataUrl[0], childrens1);
	std::vector<std::string> childrens2 = {dataUrl[3], dataUrl[2]};
	bool isOK2 = ds.addPagesConnection(dataUrl[1], childrens2);
	ASSERT_THAT(isOK1);
	ASSERT_THAT(isOK2);
	Search se{ds};
	std::optional<std::vector<std::string>> myChildrensVec2 = se.childrensDataForUrl("http://www.example2.com");
	std::vector<std::string> myChildrensCheck2 = {"http://www.example4.com", "http://www.example3.com"};
	for(size_t x = 0; x < myChildrensVec2->size(); ++x) {
		ASSERT_THAT((*myChildrensVec2)[x] == myChildrensCheck2[x]);
	}
	
END_TEST


BEGIN_TEST(data_handler_add_and_find_test)
	using namespace info_pair;
	DataHandler ds{12};
	URLdata url1{"ex1","http://www.example1.com"};
	URLdata url2{"ex2","http://www.example2.com"};
	URLdata url3{"ex3","http://www.example3.com"};
	URLdata url4{"ex4","http://www.example4.com"};
	URLdata url5{"ex5","http://www.example5.com"};
	URLdata url6{"ex6","http://www.example6.com"};
	std::array<std::string, 6> dataUrl = {"http://www.example1.com", "http://www.example2.com", "http://www.example3.com", "http://www.example4.com", "http://www.example5.com", "http://www.example6.com"};
	std::array<std::string, 10> data = { "hadar", "lioz", "hod", "sido", "gaon", "malchoto", "tal", "roni", "aviad", "masihah"};
	std::array<URLdata, 6> dataUrlAll = {url1, url2, url3, url4, url5, url6};
	size_t j = 0;
	size_t ignoreCount = 0;
	size_t ignoreUniqe = 0;
	for(size_t i = 0; i < data.size(); ++i) {
		Term t{data[i]};
		ds.addTermCountIgnore(i + 2);
		ignoreCount+= i+2;
		ds.addTermCountUniqe(i + 1);
		ignoreUniqe+= i+1;
		ds.addTermUrlData(t, dataUrlAll[j]);
		if(j == 5) {
			j = 0;
		}
	}

	j = 0;
	for(size_t i = 0; i < data.size(); ++i) {
		Search se{ds};
		std::optional<std::vector<URLdata>> myVec = se.allInformationForTerm(data[i]);
		for(size_t x = 0; x < myVec->size(); ++x) {
			ASSERT_THAT((*myVec)[x] == dataUrlAll[j]);
			if(j == 5) {
				j = 0;
			}
		}
	}
	
END_TEST


BEGIN_TEST(data_handler_add_and_find_comon_test)
	using namespace info_pair;
	DataHandler ds{12};
	URLdata url1{"ex1","http://www.example1.com"};
	URLdata url2{"ex2","http://www.example2.com"};
	URLdata url3{"ex3","http://www.example3.com"};
	URLdata url4{"ex4","http://www.example4.com"};
	URLdata url5{"ex5","http://www.example5.com"};
	URLdata url6{"ex6","http://www.example6.com"};
	Term t1{"Hadar"};
	ds.addTermUrlData(t1, url2);
	ds.addTermUrlData(t1, url1);
	ds.addTermUrlData(t1, url4);
	ds.addTermUrlData(t1, url5);

	Term t2{"Lioz"};
	ds.addTermUrlData(t2, url2);
	ds.addTermUrlData(t2, url3);
	ds.addTermUrlData(t2, url4);
	ds.addTermUrlData(t2, url5);


	Search se{ds};
	std::optional<std::vector<URLdata>> myVecHadar = se.allInformationForTerm("hadar");
	if (myVecHadar) {
        std::cout <<"term: hadar"<< std::endl;
		for(auto url : *myVecHadar) {
			std::cout << url.getURL() << std::endl;
		}
    }
	std::optional<std::vector<URLdata>> myVecLioz = se.allInformationForTerm("lioz");
	std::cout <<"term: lioz"<< std::endl;
	if (myVecLioz) {
        for(auto url : *myVecLioz) {
			std::cout << url.getURL() << std::endl;
		}
    }

	std::vector<std::string> vecStr = {"hadar", "lioz"};
	Query q;
	q.addWord(vecStr[0]);
	q.addWord(vecStr[1]);
	std::optional<std::vector<URLdata>> myVec = se.allInformationForQuery(q);
	if (myVec) {
        std::cout <<"commons"<< std::endl;
		for(auto url : *myVec) {
			std::cout << url.getURL() << std::endl;
		}
    }
	std::vector<URLdata> myCheckVec = {url2,url4, url5};
	ASSERT_THAT((*myVec) == myCheckVec);

END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(add_search_test)
	TEST(data_handler_add_and_find_connnections_perents_test)
	TEST(data_handler_add_and_find_test)
	TEST(data_handler_add_and_find_comon_test)

END_SUITE

