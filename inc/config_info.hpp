#pragma once

#include <string>
#include <vector>

#include <filesystem> //std::filesystem::path
#include "config_file_reader.hpp"

namespace info_pair {

class ConfigInfo
{
public:
    explicit ConfigInfo(std::filesystem::path const& a_fileName);
    ~ConfigInfo() = default;

    std::vector<std::string> urls() const noexcept;
    size_t maxLimitPages() const noexcept;
    size_t maxDepth() const noexcept;
    Mode crawlMode() const noexcept;

private:
    void initailizeData();

private:
    std::vector<std::string> m_urls;
    size_t m_maxLimitPages;
    size_t m_maxDepth;
    Mode m_crawlMode;

    ConfigFileReader* m_reader;
};

} // info_pair
