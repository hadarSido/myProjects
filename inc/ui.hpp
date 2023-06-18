#pragma once
#include <string>
#include <vector>

#include "query.hpp"

namespace info_pair {
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

class Ui {
public:
    Ui() = default;
    ~Ui() = default; 
    Ui(const Ui &a_other) = delete;                                      
    Ui& operator=(const Ui &a_other) = delete; 

    Query getWordsFromUser() const ;
    std::string getUrlNameFromUser() const;
    std::string getUrlAdressFromUser() const;

    int printFirstMenu() const;
    void printWordSearchMenu() const;
    void printConactionsSearchMenu() const;
    int printExitMenu() const;

    void printUrlData(std::string const& a_titel, std::string const& a_url, size_t const a_counter) const;
    void printWord(std::string const& a_word) const;
    void printWorngIndex() const;
    void printUrl(std::string const& a_url) const;
    void noResult() const;

    void printAllUrls(std::vector<std::string> const& a_urlVec) const;

    void printTitle() const;
};

}//info_pair
