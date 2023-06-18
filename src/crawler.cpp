#include <stdexcept>

#include "url_data_download.hpp"
#include "page_data_analyzer.hpp"
#include "page.hpp"
#include "crawler.hpp"

namespace info_pair {
namespace {

URLdata fromPageToURLdata(Page const& a_page) {
    std::string url = a_page.url();
    std::string title = a_page.title();
    URLdata dataForUrl(title, url);
    return dataForUrl;
}

Term fromStrToTerm(std::string const& a_str) {
    Term t{a_str};
    return t;
}

} // namespace
Crawler::Crawler(std::filesystem::path const& a_fileInfo, Updater& a_updater)
: m_pages()
, m_configInfo(a_fileInfo)
, m_downloader()
, m_analyzer()
, m_updater(a_updater)
{
    try {
        crawlData();

    } catch (std::exception const& e){
        throw std::runtime_error("crawler: " + static_cast<std::string>(e.what()));
    } catch (...) {
        throw std::runtime_error("crawler: Unknown Error \n");
    }
}

std::vector<Page> Crawler::crawlingInformation() const
{
    return m_pages;
}

void Crawler::crawlData()
{   
    std::unordered_set<std::string> visited;
    if (m_configInfo.crawlMode() == Mode::DFS) {
        for (auto& url : m_configInfo.urls()) {
            depthFirstCrawl(url, 0, visited);
        }
    }
    else {
        // NOTE: need to implement bfs here <----------
    }

}

void Crawler::depthFirstCrawl(std::string const& a_url, size_t a_currentDepth, std::unordered_set<std::string>& a_visited)
{
    if (a_currentDepth >= m_configInfo.maxDepth()) {
        m_pages.back().increaseIgnoredLinks();
        return;
    }
    if (m_pages.size() >= m_configInfo.maxLimitPages()) {
        return;
    }
    if (a_visited.count(a_url) > 0) {
        return;
    }
    try {
        std::string data = m_downloader.download(a_url);
        Page page(a_url, a_currentDepth);
        if (m_analyzer.analyzeThat(data, page)) {
            updateTermAndUrl(page);
            updateCountIgnore(page);
            updateCountUniqe(page);
            updateUrlConections(page);
            m_pages.emplace_back(page);
            std::vector<std::string> links = page.links();
            a_visited.insert(a_url);
            for (auto const& l : links) {
                depthFirstCrawl(l, a_currentDepth+1, a_visited);
            }
        }
    }
    catch(...) {
        return;
    }
}

void Crawler::updateTermAndUrl(Page const& a_page) 
{
    URLdata data = fromPageToURLdata(a_page);
    for(auto const& word : a_page.words()) {
        Term term = fromStrToTerm(word);
        m_updater.addTermUrlData(term, data);
    }
}

void Crawler::updateCountIgnore(Page const& a_page) 
{
    m_updater.addTermCountIgnore(a_page.ignoredLinks());
}

void Crawler::updateCountUniqe(Page const& a_page) 
{
    m_updater.addTermCountUniqe(a_page.irrelevantLinks()); 
}

void Crawler::updateUrlConections(Page const& a_page) 
{
    std::string data = a_page.url();
    m_updater.addPagesConnection(data, a_page.links());
}


} // info_pair
