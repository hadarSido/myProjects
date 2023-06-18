#include "term.hpp"

namespace info_pair {
namespace {
std::string toLowerCase(std::string const& a_word) {
    std::string result;
    result.reserve(a_word.size());
    for(size_t i = 0; i < a_word.size(); ++i) {
        result.push_back(std::tolower(a_word[i]));
    }
    return result;
}
} // namespace

Term::Term(std::string const& a_term, bool a_sign)
: m_term(toLowerCase(a_term)) 
, m_sign(a_sign)
{}

std::string const& Term::getTerm() const noexcept{
    return m_term;
}

bool Term::getSign() const noexcept
{
    return m_sign;
}

bool Term::operator<(const Term& a_other) const noexcept{
    return m_term < a_other.m_term;
}

}//info_pair
