#include <string>
#include <vector>
#include <regex>

#include "page.hpp"

namespace info_pair {

Page::Page(std::string const& a_url, size_t const a_level)
: m_url(a_url)
, m_title()
, m_level(a_level)
, m_links()
, m_words()
, m_ignoredLinks(0)
, m_irrelevantLinks(0)
, m_valid()
{
    if (!m_valid.url(m_url)) {
        throw std::invalid_argument("Page: Invalid Url\n");
    }
}

void Page::updateTitle(std::string const& a_title)
{
    m_title = a_title;
}

bool Page::addLink(std::string const& a_url)
{
    if (m_valid.url(a_url) && m_valid.sameSite(a_url, m_url)) {
        m_links.emplace_back(a_url);
        return true;
    }
    ++m_irrelevantLinks;
    return false;
}

bool Page::addWord(std::string& a_word)
{
    if (m_valid.word(a_word)) {
        m_words.emplace_back(a_word);
        return true;
    }
    return false;
}

void Page::increaseIgnoredLinks()
{
    ++m_ignoredLinks;
}

std::string const& Page::url() const
{
    return m_url;
}

std::string const& Page::title() const
{
    return m_title;
}

size_t Page::level() const
{
    return m_level;
}

std::vector<std::string> const& Page::links() const
{
    return m_links;
}

std::vector<std::string> const& Page::words() const
{
    return m_words;
}

size_t Page::ignoredLinks() const
{
    return m_ignoredLinks;
}

size_t Page::irrelevantLinks() const
{
    return m_irrelevantLinks;
}

} // namespace info_pair
