#pragma once

#include <regex>

namespace info_pair {

class Validator 
{
public:
    Validator();
    ~Validator() = default;

    bool url(std::string const& a_url);
    bool sameSite(std::string const& a_firstUrl, std::string const& a_secondUrl);
    bool word(std::string& a_word);
    bool html(std::string const& a_text);
    bool appearance(size_t const a_appearance);

private:
    const std::regex m_wordPattern;
    const std::regex m_urlPattern;
    const std::regex m_domainPattern;
    const std::regex m_punctuationPattern;
    const std::string m_htmlDoctype;
    size_t m_minAppearance;
};

} // info_pair
