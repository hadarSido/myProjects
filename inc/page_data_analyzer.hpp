#pragma once

#include <string>
#include <vector>

#include "page.hpp"
#include "validator.hpp"

struct GumboInternalNode;
using GumboNode = GumboInternalNode;

namespace info_pair {

class PageDataAnalyzer
{
public:
    PageDataAnalyzer() = default;
    ~PageDataAnalyzer() = default;
    
    using StrVec = std::vector<std::string>;
    bool analyzeThat(std::string const& a_data, Page& a_page);

private:
    void searchAndInsertLinks(GumboNode* a_node, Page& a_page);
    void searchParagraphs(GumboNode* a_node, std::vector<std::string>& a_vecParagraphs);
    std::string getTextContent(GumboNode* a_node);
    void insertWords(std::vector<std::string>& a_vecParagraphs, Page& a_page);
    std::string searchTitle(const GumboNode* root);

private:
    Validator m_valid;
};

} // namespace info_pair
