#pragma once
#include <string> //std::string

namespace info_pair {

class Term {
public:
    explicit Term(std::string const& a_term, bool a_sign = true);
    ~Term() = default; 
    Term(const Term &a_other) = default;                                      
    Term& operator=(const Term &a_other) = default; 

    std::string const& getTerm() const noexcept;
    bool getSign() const noexcept;

    bool operator<(const Term& a_other) const noexcept;

private:
    std::string m_term;
    bool m_sign;
};

}//info_pair
