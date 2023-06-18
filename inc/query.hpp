#pragma once

#include <string>
#include <vector>
#include <utility> // pair

#include "term.hpp"

namespace info_pair {

class Query {
public:
    explicit Query(size_t a_length = 10);
    ~Query() = default;

    void addWord(std::string const& a_word, bool a_sign = true);
    std::pair<bool, std::string> operator[] (size_t const i) const;
    size_t size() const;

private:
    std::vector<Term> m_terms;
};

}//info_pair
