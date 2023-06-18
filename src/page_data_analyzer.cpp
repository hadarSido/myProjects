#include <string>
#include <vector>
#include <assert.h>
#include <gumbo.h>

#include "page.hpp"
#include "validator.hpp"
#include "page_data_analyzer.hpp"

namespace info_pair {

bool PageDataAnalyzer::analyzeThat(std::string const& a_htmlData, Page& a_page)
{
    if (m_valid.html(a_htmlData)) {
        GumboOutput* output = gumbo_parse(a_htmlData.c_str());
        if (output) {
            searchAndInsertLinks(output->root, a_page);

            std::vector<std::string> vecParagraphs;
            searchParagraphs(output->root, vecParagraphs);

            insertWords(vecParagraphs, a_page);

            std::string title = searchTitle(output->root);
            a_page.updateTitle(title);
            
            gumbo_destroy_output(&kGumboDefaultOptions, output);
            return true;
        }
    }
    return false;
}

// https://github.com/google/gumbo-parser/blob/master/examples/find_links.cc
void PageDataAnalyzer::searchAndInsertLinks(GumboNode* a_node, Page& a_page)
{
    if (a_node == nullptr || a_node->type != GUMBO_NODE_ELEMENT) {
        return;
    }
    GumboAttribute* href;
    if (a_node->v.element.tag == GUMBO_TAG_A &&
        (href = gumbo_get_attribute(&a_node->v.element.attributes, "href"))) {
        a_page.addLink(href->value);
    }
    GumboVector* children = &a_node->v.element.children;
    if (children == nullptr) {
        return;
    }
    for (unsigned int i = 0; i < children->length; ++i) {
        searchAndInsertLinks(static_cast<GumboNode*>(children->data[i]), a_page);
    }
}

void PageDataAnalyzer::searchParagraphs(GumboNode* a_node, std::vector<std::string>& a_vecParagraphs)
{
    if (a_node->type != GUMBO_NODE_ELEMENT) {
        return;
    }
    if (a_node->v.element.tag == GUMBO_TAG_P) {
        std::string paragraphText = getTextContent(a_node);
        a_vecParagraphs.emplace_back(paragraphText);
    }
    GumboVector* children = &a_node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        searchParagraphs(static_cast<GumboNode*>(children->data[i]), a_vecParagraphs);
    }
}

std::string PageDataAnalyzer::getTextContent(GumboNode* a_node)
{
    std::string textContent;
    if (a_node->type == GUMBO_NODE_TEXT) {
        textContent = a_node->v.text.text;
    } else if (a_node->type == GUMBO_NODE_ELEMENT && a_node->v.element.tag != GUMBO_TAG_SCRIPT &&
               a_node->v.element.tag != GUMBO_TAG_STYLE) {
        GumboVector* children = &a_node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i) {
            const std::string childText = getTextContent(static_cast<GumboNode*>(children->data[i]));
            textContent += childText;
        }
    }
    return textContent;
}

void PageDataAnalyzer::insertWords(std::vector<std::string>& a_vecParagraphs, Page& a_page)
{
    for (auto& paragraph : a_vecParagraphs) {
        std::stringstream ss(paragraph);
        std::string word;
        while (ss >> word) {
            if (m_valid.word(word)) {
                a_page.addWord(word);
            }
        }
    }
}

// https://github.com/google/gumbo-parser/blob/master/examples/get_title.c
std::string PageDataAnalyzer::searchTitle(const GumboNode* root) 
{
    assert(root->type == GUMBO_NODE_ELEMENT);
    assert(root->v.element.children.length >= 2);

    const GumboVector* root_children = &root->v.element.children;
    GumboNode* head = nullptr;
    for (unsigned int i = 0; i < root_children->length; ++i) {
        GumboNode* child = static_cast<GumboNode*>(root_children->data[i]);
        if (child->type == GUMBO_NODE_ELEMENT &&
            child->v.element.tag == GUMBO_TAG_HEAD) {
            head = child;
            break;
        }
    }
    assert(head != nullptr);

    GumboVector* head_children = &head->v.element.children;
    for (unsigned int i = 0; i < head_children->length; ++i) {
        GumboNode* child = static_cast<GumboNode*>(head_children->data[i]);
        if (child->type == GUMBO_NODE_ELEMENT &&
            child->v.element.tag == GUMBO_TAG_TITLE) {
            if (child->v.element.children.length != 1) {
                return "<empty title>";
            }
            GumboNode* title_text = static_cast<GumboNode*>(child->v.element.children.data[0]);
            assert(title_text->type == GUMBO_NODE_TEXT || title_text->type == GUMBO_NODE_WHITESPACE);
            return title_text->v.text.text;
        }
    }
    return "<no title found>";
}


} // namespace info_pair
