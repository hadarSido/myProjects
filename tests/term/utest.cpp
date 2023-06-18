#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <utility> //pair
#include "mu_test.h"
#include "term.hpp"

std::string toLowerCase(std::string const& a_word) {
    std::string result;
    result.reserve(a_word.size());
    for(size_t i = 0; i < a_word.size(); ++i) {
        result.push_back(std::tolower(a_word[i]));
    }
    return result;
}
BEGIN_TEST(add_term_test)
	using namespace info_pair;
	Term t1("Hadar");

	ASSERT_EQUAL(t1.getTerm(), toLowerCase("Hadar"));
	
END_TEST

BEGIN_TEST(add_term_vector_test)
	using namespace info_pair;
	Term t1("Hadar");
	Term t2("Chaya");
	Term t3("Or");
	Term t4("Adaya");
	Term t5("Tomer");
	std::vector<Term> terms;
	terms.push_back(t1);
	terms.push_back(t2);
	terms.push_back(t3);
	terms.push_back(t4);
	terms.push_back(t5);
	std::array<std::string , 5> names = {"Hadar", "Chaya", "Or", "Adaya", "Tomer"};
	size_t i = 0;
	for(auto& term : terms) {
		ASSERT_EQUAL(term.getTerm(), toLowerCase(names[i]));
		++i;
	}
	
END_TEST

BEGIN_TEST(add_term_map_test)
	using namespace info_pair;
	Term t1("Hadar");
	Term t2("Chaya");
	Term t3("Or");
	Term t4("Adaya");
	Term t5("Tomer");
	std::map<Term, size_t> terms;
	terms[t1] = 3;
	terms[t2] = 2;
	terms[t3] = 4;
	terms[t4] = 1;
	terms[t5] = 5;
	
	std::array<std::string , 5> names = {"Adaya", "Chaya", "Hadar", "Or", "Tomer"};
	size_t i = 0;
	for(auto const& term : terms) {
		std::cout << term.first.getTerm() << " = " << term.second << std::endl;
		ASSERT_EQUAL(term.first.getTerm(), toLowerCase(names[i]));
		ASSERT_EQUAL(term.second, i+1);
		++i;
	}
	
END_TEST


BEGIN_TEST(add_term_map_vector_test)
	using namespace info_pair;
	Term t1("Hadar");
	Term t2("Chaya");
	Term t3("Or");
	Term t4("Adaya");
	Term t5("Tomer");
	std::map<Term, std::vector<size_t>> terms;
	terms[t1] = {1,2,3,4,5};
	terms[t2] = {3,4,5};
	terms[t3] = {1};
	terms[t4] = {2,3};
	terms[t5] = {1,2,3,4,5,7};
	
	std::array<Term, 5> names = {t4, t2, t1, t3, t5};
	std::array<std::vector<size_t>, 5> numbers = {std::vector<size_t>{2,3}, std::vector<size_t>{3,4,5}, std::vector<size_t>{1,2,3,4,5}, std::vector<size_t>{1}, std::vector<size_t>{1,2,3,4,5,7}};
	size_t i = 0;
	for(auto const& term : terms) {
		ASSERT_EQUAL(term.first.getTerm(), names[i].getTerm());
		ASSERT_THAT(term.second == numbers[i]);
		++i;
	}
	ASSERT_PASS();
	
END_TEST

BEGIN_TEST(add_term_map_pair_test)
	using namespace info_pair;
	Term t1("Hadar");
	Term t2("Chaya");
	Term t3("Or");
	Term t4("Adaya");
	Term t5("Tomer");
	std::map<Term, std::pair<size_t, size_t>> terms;
	terms[t1] = std::make_pair(3, 2);
	terms[t2] = std::make_pair(4, 2);
	terms[t3] = std::make_pair(13, 11);
	terms[t4] = std::make_pair(6, 7);
	terms[t5] = std::make_pair(9, 20);
	
	std::array<std::string , 5> names = {"Adaya", "Chaya", "Hadar", "Or", "Tomer"};
	std::array<std::pair<size_t, size_t>, 5> numbers = {std::make_pair(6, 7) , std::make_pair(4, 2) , std::make_pair(3, 2), std::make_pair(13, 11) , std::make_pair(9, 20)};
	size_t i = 0;
	for(auto const& term : terms) {
		ASSERT_EQUAL(term.first.getTerm(), toLowerCase(names[i]));
		ASSERT_THAT(term.second == numbers[i]);
		++i;
	}
	ASSERT_PASS();
	
END_TEST




TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(add_term_test)
	TEST(add_term_vector_test)
	TEST(add_term_map_test)
	TEST(add_term_map_vector_test)
	TEST(add_term_map_pair_test)

END_SUITE

