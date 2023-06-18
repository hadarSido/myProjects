#include "manager.hpp"

namespace info_pair {
Manager::Manager(std::filesystem::path const& a_source)
: m_ui() 
, m_dataHandler(5000)
, m_crawler(a_source ,m_dataHandler)
, m_search(m_dataHandler)
{}

void Manager::run() {
    m_ui.printTitle();
    for (;;) {
        UserChoice userChoice = static_cast<UserChoice>(m_ui.printFirstMenu());
        size_t exit;
        Query query;
        std::string url;
        std::optional<std::vector<URLdata>> termInfo;
        std::optional<std::vector<std::string>> childrensInfo;
        std::vector<std::string> urls;
        switch (userChoice) {
            case UserChoice::SEARCH_WORD:
                m_ui.printWordSearchMenu();
                query = m_ui.getWordsFromUser();
                termInfo = m_search.allInformationForQuery(query);
                showData(termInfo, query);
                continue;
            case UserChoice::SEARCH_URL:
                m_ui.printConactionsSearchMenu();
                urls = m_search.getAllPagesData();
                showDataForAllUrls(urls);
                url = m_ui.getUrlAdressFromUser();
                childrensInfo = m_search.childrensDataForUrl(url);
                showDataChildrens(childrensInfo, url);
                break;
            case UserChoice::EXIT:
                exit = m_ui.printExitMenu();
                if (exit == 1) {
                    return;
                }
                break;
            default:
                m_ui.printWorngIndex();
                break;
        }
    }
}


void Manager::showData(std::optional<std::vector<URLdata>> a_termInfo, Query const& a_query) 
{
    size_t size = a_query.size();
    for (size_t i=0; i<size; ++i) {
        m_ui.printWord(a_query[i].second);
    }
    
    if(a_termInfo) {
        std::cout << a_termInfo.value().size() << std::endl;
        for(auto const& urlData : *a_termInfo) {
            m_ui.printUrlData(urlData.getTitle(), urlData.getURL(), urlData.getTermCounter());
        }
    }
    else {
        m_ui.noResult();
    }
}


void Manager::showDataChildrens(std::optional<std::vector<std::string>> a_infoChildrens, std::string const& a_url) 
{
    if(a_infoChildrens) {
        for(auto const& child : *a_infoChildrens) {
            m_ui.printUrl(child);
        }
    }
    else {
        m_ui.noResult();
    }
}

void Manager::showDataForAllUrls(std::vector<std::string> const& a_urlIfo) const
{
    m_ui.printAllUrls(a_urlIfo);
}



}//info_pair
