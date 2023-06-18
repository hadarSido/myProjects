#include "pages_connection.hpp"

#include <iostream>
#include <ostream>

namespace info_pair {

namespace {
    
static bool comperUrlData( std::string const& a_url1, std::string const& a_url2) 
{
    if(a_url1 == a_url2) {
        return true;
    }
    return false;
}

    
bool isIndexInVec(std::vector<size_t> const& a_vec, size_t a_index) 
{
    if(a_vec.empty()) {
        return false;
    }
    for(auto const& num : a_vec) {
        if(num == a_index) {
            return true;
        }
    }
    return false;
} 

}//namespace

PagesConnection::PagesConnection(size_t a_reserve)
: m_pagesData()
, m_perentsIndex()
, m_childrensIndex()
{
    if(a_reserve < 1000) {
        a_reserve = 1000;
    }
    m_pagesData.reserve(a_reserve);
    m_perentsIndex.reserve(a_reserve);
    m_childrensIndex.reserve(a_reserve);
}

size_t PagesConnection::addUrl(std::string const& a_url) noexcept
{
    size_t index = findUrlIndex(a_url);
    if (index == m_pagesData.size()) {
        m_pagesData.push_back(a_url);
    }
    return index;
}

void PagesConnection::addUrlPerents(size_t a_index, size_t a_perentLocation) 
{
    if(!isIndexInVec(m_perentsIndex[a_index], a_perentLocation)) {
        m_perentsIndex[a_index].push_back(a_perentLocation);
    }
    if(!isIndexInVec(m_childrensIndex[a_perentLocation], a_index)) {
        m_perentsIndex[a_perentLocation].push_back(a_index);
    }
}

void PagesConnection::addUrlchildrens(size_t a_index, size_t a_childLocation) 
{
    if(!isIndexInVec(m_childrensIndex[a_index], a_childLocation)) {
        m_childrensIndex[a_index].push_back(a_childLocation);
    }
    if(!isIndexInVec(m_perentsIndex[a_childLocation], a_index)) {
        m_perentsIndex[a_childLocation].push_back(a_index);
    }
}

size_t PagesConnection::findUrlIndex(std::string const& a_url) const noexcept
{
    for(size_t i = 0; i < m_pagesData.size(); ++i) {
        if(comperUrlData(m_pagesData[i], a_url)) {
            return i;
        }
    }
    return m_pagesData.size();
}

std::vector<size_t> const& PagesConnection::getChildrens(size_t a_index) const 
{
    return m_childrensIndex[a_index];
}

std::vector<size_t> const& PagesConnection::getPerents(size_t a_index) const 
{
    return m_perentsIndex[a_index];
}

size_t PagesConnection::size() const noexcept {
    return m_pagesData.size();
}

std::string const& PagesConnection::getUrlData(size_t a_index) const noexcept 
{
    return m_pagesData[a_index];
}

std::vector<std::string> const& PagesConnection::getPagesData() const noexcept
{
    return m_pagesData;
}


}//info_pair