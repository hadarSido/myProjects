#include "data_handler.hpp"

#include <iostream>
#include <ostream>


namespace info_pair {

namespace {
static bool isDataExist(std::vector<URLdata>& a_dataHandler , URLdata& a_data) 
{
    for (auto& data : a_dataHandler) {
        if (data == a_data) {
            data.incrementTermCounter();
            return true;
        }
    }
    return false;
}

// static size_t insertInRightPlace(std::vector<URLdata>& a_dataHandler , URLdata a_data) 
// {
//     for (size_t i = 0; i < a_dataHandler.size() ; ++i) {
//         if (a_dataHandler[i] > a_data) {
//             a_dataHandler.insert(a_dataHandler.begin() + i, a_data);
//             return i;
//         }
//     }
//     a_dataHandler.push_back(a_data);
//     return a_dataHandler.size() - 1;
// }

} //namespace

DataHandler::DataHandler(size_t a_reserve)
: m_termsUrlHandler()
, m_countIgnore(0)
, m_countUnique(0)
, m_pagesConnections(a_reserve)
{}

void DataHandler::addTermCountIgnore(size_t a_count) 
{
    m_countIgnore += a_count;
}

void DataHandler::addTermCountUniqe(size_t a_count) 
{
    m_countUnique += a_count;
}

void DataHandler::addTermUrlData(Term const& a_term, URLdata& a_data) 
{
    if(!isDataExist(m_termsUrlHandler[a_term], a_data)) {
        m_termsUrlHandler[a_term].push_back(a_data);
    }
}

bool DataHandler::addPagesConnection(std::string const& a_urlData, std::vector<std::string> const& a_childrens) 
{   
    size_t counter = 0;
    size_t index = m_pagesConnections.addUrl(a_urlData);
    for(size_t i = 0; i < a_childrens.size(); ++i) {
        size_t pIndex = m_pagesConnections.findUrlIndex(a_childrens[i]);
        if(pIndex == m_pagesConnections.size()) {
            pIndex = m_pagesConnections.addUrl(a_childrens[i]);
        }
        m_pagesConnections.addUrlchildrens(index, pIndex);
        ++counter;
    }  
    if(counter == a_childrens.size()){
        return true;
    }
    return false;
}

size_t DataHandler::findTermCountIgnore() const noexcept
{
    return m_countIgnore;
}

size_t DataHandler::findTermCountUniqe() const noexcept
{
    return m_countUnique;
}

std::optional<std::vector<URLdata>> DataHandler::findTermsUrlData(Term const& a_term) const {
    auto finder = m_termsUrlHandler.find(a_term);
    if (finder == m_termsUrlHandler.end()) {
        return std::nullopt;
    }
    return finder->second;
}

std::optional<std::vector<std::string>> DataHandler::findUrlPerentsData(std::string const& a_child) const {
    size_t pIndex = m_pagesConnections.findUrlIndex(a_child);
    std::vector<size_t> perentsIndexVec = m_pagesConnections.getPerents(pIndex);
    std::vector<std::string> perntsURL;
    perntsURL.reserve(perentsIndexVec.size());
    if(perentsIndexVec.empty()) {
        return std::nullopt;
    }
    for(size_t i = 0; i < perentsIndexVec.size(); ++i) {
        perntsURL.push_back(m_pagesConnections.getUrlData(perentsIndexVec[i]));
    }
    return perntsURL;
}


std::optional<std::vector<std::string>> DataHandler::findUrlChildrensData(std::string const& a_perent) const {
    size_t cIndex = m_pagesConnections.findUrlIndex(a_perent);
    std::vector<size_t> childrensIndexVec = m_pagesConnections.getChildrens(cIndex);
    std::vector<std::string> childrensURL;
    childrensURL.reserve(childrensIndexVec.size());
    if(childrensIndexVec.empty()) {
        return std::nullopt;
    }
    for(size_t i = 0; i < childrensIndexVec.size(); ++i) {
        childrensURL.push_back(m_pagesConnections.getUrlData(childrensIndexVec[i]));      
    }
    return childrensURL;
}

std::vector<std::string> const& DataHandler::getAllPagesData() const {
    return m_pagesConnections.getPagesData();
}

}//info_pair
