#pragma once

#include <string>
#include <vector>

#include "validator.hpp"

namespace info_pair {

class Page
{
public:
    explicit Page(std::string const& a_url, size_t const a_level = 0);
    Page(Page const& a_other) = default;
    Page& operator=(Page const& a_other) = default;
    ~Page() = default;

    void updateTitle(std::string const& a_title);
    bool addLink(std::string const& a_url);
    bool addWord(std::string& a_word);
    void increaseIgnoredLinks();
 
    std::string const& url() const;
    std::string const& title() const;
    size_t level() const;
    std::vector<std::string> const& links() const;
    std::vector<std::string> const& words() const;
    size_t ignoredLinks() const;
    size_t irrelevantLinks() const;

private:
    std::string m_url;
    std::string m_title;
    size_t m_level;
    std::vector<std::string> m_links;
    std::vector<std::string> m_words;
    size_t m_ignoredLinks;
    size_t m_irrelevantLinks;

    Validator m_valid;
};

} // namespace info_pair
