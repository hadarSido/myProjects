#pragma once
#include <string> //std::string
#include <optional>

#include "url_data.hpp"
#include "finder.hpp"
#include "query.hpp"

namespace info_pair {
class Search {
public:
    explicit Search(Finder& a_finder);
    ~Search() = default; 
    Search(const Search &a_other) = default;                                      
    Search& operator=(const Search &a_other) = default; 

    std::optional<std::vector<URLdata>> allInformationForTerm(std::string const& a_word) const;

    std::optional<std::vector<std::string>> perentsDataForUrl(std::string const& a_url) const;
    std::optional<std::vector<std::string>> childrensDataForUrl(std::string const& a_url) const;

    std::vector<std::string> const& getAllPagesData() const;

    std::optional<std::vector<URLdata>> allInformationForQuery(Query const& a_wordsQuery) const;    

private:
    Finder& m_finder;
};

}//info_pair
