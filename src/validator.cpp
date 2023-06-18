#include "validator.hpp"

namespace info_pair {

Validator::Validator()
: m_wordPattern("^[A-Za-z]{3,}$")
, m_urlPattern(R"(^(?:(?:https?|ftp)://)(?:\S+@)?(?:(?!10(?:\.\d{1,3}){3})(?!127(?:\.\d{1,3}){3})(?!169\.254(?:\.\d{1,3}){2})(?!192\.168(?:\.\d{1,3}){2})(?!172\.(?:1[6-9]|2\d|3[0-1])(?:\.\d{1,3}){2})(?:[1-9]\d?|1\d\d|2[01]\d|22[0-3])(?:\.(?:1?\d{1,2}|2[0-4]\d|25[0-5])){2}(?:\.(?:[1-9]\d?|1\d\d|2[0-4]\d|25[0-4]))|(?:[a-z\u00a1-\uffff0-9]+-)*[a-z\u00a1-\uffff0-9]+(?:\.(?:[a-z\u00a1-\uffff0-9]+-)*[a-z\u00a1-\uffff0-9]+)*(?:\.(?:[a-z\u00a1-\uffff]{2,})))(?::\d{2,5})?(?:/\S*)?$)")
, m_domainPattern("(https?|ftp|www)://([^/?#:]+)")
, m_punctuationPattern("[.,!?:;]")
, m_htmlDoctype("<!DOCTYPE html>")
, m_minAppearance(1)
{

}

bool Validator::url(std::string const& a_url)
{
    bool answer = true;
    try {
        answer = std::regex_match(a_url, m_urlPattern);
    } catch (...) {
        answer = false;
    }
    return answer;
}

bool Validator::sameSite(std::string const& a_firstUrl, std::string const& a_secondUrl)
{
    bool answer = false;
    try {
        std::smatch matchFirst;
        std::smatch matchSecond;
        if (std::regex_search(a_firstUrl, matchFirst, m_domainPattern)
                && std::regex_search(a_secondUrl, matchSecond, m_domainPattern)) {
            if (matchFirst.str(2) == matchSecond.str(2)) {
                answer = true;
            }
        }
    } catch (...) {
        answer = false;
    }
    return answer;
}

bool Validator::word(std::string& a_word)
{
    std::string firstLetter(1, a_word[0]);
    std::string lastLetter(1, a_word[a_word.length()-1]);

    if (!a_word.empty() && std::regex_match(firstLetter, m_punctuationPattern)) {
        a_word.erase(0,1);
    }
    while (!a_word.empty() && std::regex_match(lastLetter, m_punctuationPattern)) {
        a_word.erase(a_word.length()-1);
        lastLetter = a_word[a_word.length()-1];
    }
    return std::regex_match(a_word, m_wordPattern);
}

bool Validator::html(std::string const& a_text)
{
    return a_text.find(m_htmlDoctype) != std::string::npos;
}

bool Validator::appearance(size_t const a_appearance)
{
    return a_appearance >= m_minAppearance;
}

} // info_pair
