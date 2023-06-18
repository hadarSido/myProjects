#include "url_data.hpp"

namespace info_pair {

URLdata::URLdata(std::string const& a_title, std::string const& a_url)
: m_title(a_title) 
, m_url(a_url)
, m_termsCounter(1)
{}


std::string const& URLdata::getTitle() const noexcept 
{
    return m_title;
}
std::string const& URLdata::getURL() const noexcept 
{
    return m_url;
}

size_t URLdata::getTermCounter() const noexcept 
{
    return m_termsCounter;
}

void URLdata::incrementTermCounter() noexcept 
{
    ++m_termsCounter;
}

bool URLdata::operator==(URLdata const& a_other) const noexcept 
{
    return m_title == a_other.m_title && m_url == a_other.m_url;
}

bool URLdata::operator>(URLdata const& a_other) const noexcept 
{
    return a_other.m_termsCounter > m_termsCounter;
}

bool URLdata::operator<(URLdata const& a_other) const noexcept 
{
    return m_url < a_other.m_url;
}
void URLdata::operator+=(URLdata const& a_other) noexcept 
{
    if (*this == a_other) {
        m_termsCounter += a_other.m_termsCounter;
    }
}

}//info_pair
