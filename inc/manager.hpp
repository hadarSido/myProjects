#pragma once

#include <optional>
#include <vector>
#include <filesystem> //std::filesystem::path

#include "search.hpp"
#include "data_handler.hpp"
#include "crawler.hpp"
#include "ui.hpp"
#include "url_data.hpp"
#include "query.hpp"

namespace info_pair {
    
enum class UserChoice {
    SEARCH_WORD = 1,
    SEARCH_URL,
    EXIT
};

class Manager {
public:
    explicit Manager(std::filesystem::path const& a_source);
    ~Manager() = default; 
    Manager(const Manager &a_other) = delete;                                      
    Manager& operator=(const Manager &a_other) = delete; 

    void run();

private:
    void showData(std::optional<std::vector<URLdata>> a_termInfo, Query const& a_query);
    void showDataChildrens(std::optional<std::vector<std::string>> a_infoChildrens, std::string const& a_url);
    void showDataForAllUrls(std::vector<std::string> const& a_urlIfo) const;

private:
    Ui m_ui;
    DataHandler m_dataHandler;
    Crawler m_crawler;
    Search m_search;
   

};

}//info_pair
