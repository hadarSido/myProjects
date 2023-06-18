#pragma once

#include <jsoncpp/json/json.h> //JSON files
#include <fstream> //files
#include <filesystem> //std::filesystem::path

#include "config_file_reader.hpp"

namespace info_pair {

class ConfigJson : public ConfigFileReader
{
public :
    explicit ConfigJson(std::filesystem::path const& a_fileName);
    ~ConfigJson() = default;

    std::vector<std::string> readUrl() override;
    size_t readMaxLimitPages() override;
    size_t readMaxDepth() override;
    Mode readCrawlMode() override;

private:
    std::ifstream m_file;
    Json::Value m_root;
};

} // info_pair
