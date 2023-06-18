#pragma once

#include <string>
#include <vector>

namespace info_pair {

enum class Mode {
    UNKNOWN,
    BFS,
    DFS
};

class ConfigFileReader 
{
public:
    virtual ~ConfigFileReader() = default;

    virtual std::vector<std::string> readUrl() = 0;
    virtual size_t readMaxLimitPages() = 0;
    virtual size_t readMaxDepth() = 0;
    virtual Mode readCrawlMode() = 0; 

protected:
    ConfigFileReader() = default;
};

} // info_pair
