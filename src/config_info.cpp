#include <stdexcept>
		
#include "config_file_reader.hpp"
#include "config_json.hpp"
#include "config_info.hpp"


namespace info_pair {

ConfigInfo::ConfigInfo(std::filesystem::path const& a_fileName)
: m_reader(new ConfigJson(a_fileName))
{
    try {
        initailizeData();

    } catch (std::exception const& e){
        throw std::runtime_error("config info: " + static_cast<std::string>(e.what()));
    } catch (...) {
        throw std::runtime_error("config info: Unknown Error \n");
    }
}

std::vector<std::string> ConfigInfo::urls() const noexcept
{
    return m_urls;
}

size_t ConfigInfo::maxLimitPages() const noexcept
{
    return m_maxLimitPages;
}

size_t ConfigInfo::maxDepth() const noexcept
{
    return m_maxDepth;
}

Mode ConfigInfo::crawlMode() const noexcept
{
    return m_crawlMode;
}

void ConfigInfo::initailizeData()
{
    m_urls = m_reader->readUrl();
    m_maxLimitPages = m_reader->readMaxLimitPages();
    m_maxDepth = m_reader->readMaxDepth();
    m_crawlMode = m_reader->readCrawlMode();
}

} // info_pair
