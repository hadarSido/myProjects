#pragma once
#include <vector>

#include "url_data.hpp"
#include "term.hpp"

namespace info_pair {

class Updater {
public:
    virtual ~Updater() = default;

    virtual void addTermCountIgnore(size_t a_count) = 0; 
    virtual void addTermCountUniqe(size_t a_count) = 0;
    virtual void addTermUrlData(Term const& a_term, URLdata& a_data) = 0;

    virtual bool addPagesConnection(std::string const& a_urlData, std::vector<std::string> const& a_childrens) = 0;

protected:
    Updater() = default;
    Updater(const Updater& a_other) = default;
    Updater& operator=(const Updater &a_other) = default; 
};

}//info_pair
