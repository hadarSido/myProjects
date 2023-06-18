#include <assert.h>

#include "query.hpp"

namespace info_pair {

Query::Query(size_t a_length)
: m_terms()
{
    assert(a_length != 0);
    m_terms.reserve(a_length);
}

void Query::addWord(std::string const& a_word, bool a_sign)
{
    Term newTermToAdd(a_word, a_sign);
    m_terms.emplace_back(newTermToAdd);
}

std::pair<bool, std::string> Query::operator[] (size_t const i) const
{
    return std::make_pair(m_terms[i].getSign(), m_terms[i].getTerm());
}

size_t Query::size() const
{
    return m_terms.size();
}

}//info_pair
