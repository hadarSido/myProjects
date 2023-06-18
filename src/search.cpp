#include <utility> // std::pair
#include <algorithm> // set_intersection
#include "search.hpp"

namespace info_pair {
namespace {
Term addWord(std::string a_word) {
    Term term{a_word};
    return term;
}

std::vector<URLdata> intersectionToPositiveTerms(std::vector<std::vector<URLdata>> a_positivesVec) 
{
    std::vector<URLdata> urlsPositive = a_positivesVec[0];
    for(size_t i = 1; i < a_positivesVec.size() ; ++i) {
        std::vector<URLdata> urlsPositivCurrent = a_positivesVec[i];
        for(size_t j = 0; j < urlsPositive.size(); ++j) {
            for(size_t k = 0; k < a_positivesVec[i].size(); ++k) {
                if(urlsPositive[j] == (a_positivesVec[i])[k]) {
                    urlsPositive[j] += (a_positivesVec[i])[k];
                }
            }
        }
        std::sort(a_positivesVec[i].begin(), a_positivesVec[i].end());
        std::sort(urlsPositive.begin(), urlsPositive.end());
        std::vector<URLdata> tempVector;
        std::set_intersection(a_positivesVec[i].begin(), a_positivesVec[i].end(),
                          urlsPositive.begin(), urlsPositive.end(),
                          std::back_inserter(tempVector));
        urlsPositive = tempVector;
    }
    return urlsPositive;
}


std::vector<URLdata> unionToNegativeTerms(std::vector<std::vector<URLdata>> a_negativeVec) {
    std::vector<URLdata> urlsNegative = a_negativeVec[0];
    for(size_t i = 1; i < a_negativeVec.size() ; ++i) {
        std::sort(a_negativeVec[i].begin(), a_negativeVec[i].end());
        std::sort(urlsNegative.begin(), urlsNegative.end());
        std::vector<URLdata> tempVector;
        std::set_union(a_negativeVec[i].begin(), a_negativeVec[i].end(),
                          urlsNegative.begin(), urlsNegative.end(),
                          std::back_inserter(tempVector));       
        urlsNegative = tempVector;
    }
    return urlsNegative;
}

std::vector<URLdata> setDifferentFromNegativToPositev(std::vector<URLdata> a_negativVec, std::vector<URLdata> a_posativVec) {
    std::sort(a_posativVec.begin(), a_posativVec.end());
    std::sort(a_negativVec.begin(), a_negativVec.end()); 
    std::vector<URLdata> returnVector;
    std::set_difference(a_posativVec.begin(), a_posativVec.end(),
                          a_negativVec.begin(), a_negativVec.end(),
                          std::back_inserter(returnVector));
    return returnVector;
}


std::vector<URLdata> comperURLsInVec(std::vector<std::pair<bool,std::vector<URLdata>>> const& a_urlsVectorAll) 
{
    std::vector<std::vector<URLdata>> commonUrlsNegative;
    std::vector<std::vector<URLdata>> commonUrlsPositive;
    for(auto const& url : a_urlsVectorAll) {
        if(url.first) {
            commonUrlsPositive.emplace_back(url.second);
        }
        else {
            commonUrlsNegative.emplace_back(url.second);
        }
    }
    std::vector<URLdata> urlsPositiv = intersectionToPositiveTerms(commonUrlsPositive);
    
    if(commonUrlsNegative.empty()){
        return urlsPositiv;
    }
    std::vector<URLdata> urlsNegativ = unionToNegativeTerms(commonUrlsNegative);
    return setDifferentFromNegativToPositev(urlsNegativ, urlsPositiv);
}


} //namespace

Search::Search(Finder& a_finder)
: m_finder(a_finder)
{}

std::optional<std::vector<URLdata>> Search::allInformationForTerm(std::string const& a_word) const
{    
    std::optional<std::vector<URLdata>> optVec = m_finder.findTermsUrlData(addWord(a_word));
    if (optVec) {
        return *optVec;
    } 
    else {
        return std::nullopt;
    }
}

std::optional<std::vector<std::string>> Search::perentsDataForUrl(std::string const& a_url) const
{
    std::optional<std::vector<std::string>> optVec = m_finder.findUrlPerentsData(a_url);
    if (optVec) {
        return optVec;
    }
    else {
        return std::nullopt;
    }
}
std::optional<std::vector<std::string>> Search::childrensDataForUrl(std::string const& a_url) const
{
    std::optional<std::vector<std::string>> optVec = m_finder.findUrlChildrensData(a_url);
    if (optVec) {
        return optVec;
    }
    else {
        return std::nullopt;
    }
}

std::vector<std::string> const& Search::getAllPagesData() const {
    return m_finder.getAllPagesData();
}


std::optional<std::vector<URLdata>> Search::allInformationForQuery(Query const& a_wordsQuery) const
{
    std::vector<std::pair<bool,std::vector<URLdata>>> termDataSaver;
    size_t size = a_wordsQuery.size();
    termDataSaver.reserve(size);
    for(size_t i=0; i<size; ++i) { 
        std::optional<std::vector<URLdata>> dataForTerm = allInformationForTerm(a_wordsQuery[i].second);
        if(dataForTerm) {
            std::pair termPair = std::make_pair(a_wordsQuery[i].first, *dataForTerm);
            termDataSaver.push_back(termPair);
        }
        else if (a_wordsQuery[i].first && !dataForTerm){
            return std::nullopt;
        }
    }
    return comperURLsInVec(termDataSaver) ;
}


}//info_pair
