#include "config_json.hpp"


namespace info_pair {

ConfigJson::ConfigJson(std::filesystem::path const& a_fileName)
: m_file(a_fileName) 
{
    m_file >> m_root;
}

std::vector<std::string> ConfigJson::readUrl()
{
    std::vector<std::string> vecUrl;
    Json::Value const& links = m_root["links"];
    if (links.isArray()){
        for (auto const& l : links) {
            if (l.isString()) {
                vecUrl.emplace_back(l.asString());
            }
        }
    } else {
        throw std::invalid_argument("config json: invalid urls\n");
    }
    return vecUrl;
}

size_t ConfigJson::readMaxLimitPages()
{
    size_t maxPages;
    Json::Value const& pages = m_root["pages"];
    if (pages.isUInt()) {
        maxPages = std::max(pages.asUInt(), static_cast<unsigned int>(1));
    } else {
        throw std::invalid_argument("config json: invalid max limit pages\n");
    }
    return maxPages;
}

size_t ConfigJson::readMaxDepth()
{
    size_t maxDepth;
    Json::Value const& depth = m_root["depth"];
    if (depth.isUInt()) {
        maxDepth = std::max(depth.asUInt(), static_cast<unsigned int>(1));
    } else {
        throw std::invalid_argument("config json: invalid max depth\n");
    }
    return maxDepth;
}

Mode ConfigJson::readCrawlMode() 
{
    Mode crawlMode;
    Json::Value const& mode = m_root["mode"];
    if (mode.isString()) {
        std::string modeStr = mode.asString();
        if (modeStr == "DFS") {
            crawlMode = Mode::DFS;
        } else if (modeStr == "BFS") {
            crawlMode = Mode::BFS;
        } else {
            crawlMode = Mode::UNKNOWN;
        }
    } else {
        throw std::invalid_argument("config json: invalid crawl mode\n");
    }
    return crawlMode;
}

} // info_pair
