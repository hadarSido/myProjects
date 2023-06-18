#pragma once
#include <string> //std::string
#include <optional> // std::optional
#include <utility> //std::pair
#include <vector>

#include "url_data.hpp"
#include "term.hpp"

namespace info_pair {

class Finder {
public:
    virtual ~Finder() = default;

    virtual std::optional<std::vector<URLdata>> findTermsUrlData(Term const& a_term) const = 0;
    virtual size_t findTermCountIgnore() const noexcept = 0;
    virtual size_t findTermCountUniqe() const noexcept = 0;

    virtual std::optional<std::vector<std::string>> findUrlPerentsData(std::string const& a_child) const = 0;
    virtual std::optional<std::vector<std::string>> findUrlChildrensData( std::string const& a_perent) const = 0;

    virtual std::vector<std::string> const& getAllPagesData() const = 0;

protected:
    Finder() = default;
    Finder(const Finder& a_other) = default;
    Finder& operator=(const Finder &a_other) = default; 
};

}//info_pair
