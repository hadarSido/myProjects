#pragma once

#include <vector>
#include <string>
#include <unordered_set>
#include <filesystem>

#include "url_data_download.hpp"
#include "page_data_analyzer.hpp"
#include "page.hpp"
#include "config_info.hpp"
#include "updater.hpp"

namespace info_pair {

class Crawler
{
public:
    explicit Crawler(std::filesystem::path const& a_fileInfo, Updater& a_updater);
    ~Crawler() = default;

    std::vector<Page> crawlingInformation() const;

private:
    void crawlData();
    void depthFirstCrawl(std::string const& a_url, size_t a_currentDepth, std::unordered_set<std::string>& a_visited);

    void updateTermAndUrl(Page const& a_page);
    void updateCountIgnore(Page const& a_page);
    void updateCountUniqe(Page const& a_page);
    void updateUrlConections(Page const& a_page);

private:
    std::vector<Page> m_pages;
    ConfigInfo m_configInfo;
    UrlDataDownload m_downloader;
    PageDataAnalyzer m_analyzer;
    Updater& m_updater;
};

} // info_pair
