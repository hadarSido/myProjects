#pragma once
#include <vector>
#include <optional> // std::optional
#include <utility> //std::pair
#include <map>

#include "term.hpp"
#include "pages_connection.hpp"
#include "url_data.hpp"
#include "finder.hpp"
#include "updater.hpp"

namespace info_pair {
class DataHandler : public Finder, public Updater {
public:
    explicit DataHandler(size_t a_reserve);
    ~DataHandler() override = default; 
    DataHandler(DataHandler const& a_other) = default;                                      
    DataHandler& operator=(DataHandler const& a_other) = default;

    void addTermCountIgnore(size_t a_count);
    void addTermCountUniqe(size_t a_count);
    void addTermUrlData(Term const& a_term, URLdata& a_data);

    bool addPagesConnection(std::string const& a_urlData, std::vector<std::string> const& a_childrens);

    std::optional<std::vector<URLdata>> findTermsUrlData(Term const& a_term) const;
    size_t findTermCountIgnore() const noexcept;
    size_t findTermCountUniqe() const noexcept;

    std::optional<std::vector<std::string>> findUrlPerentsData(std::string const& a_child) const;
    std::optional<std::vector<std::string>> findUrlChildrensData( std::string const& a_perent) const;

    std::vector<std::string> const& getAllPagesData() const;

private:
    std::map<Term, std::vector<URLdata>> m_termsUrlHandler;
    size_t m_countIgnore;
    size_t m_countUnique;
    PagesConnection m_pagesConnections;
};


}//info_pair
