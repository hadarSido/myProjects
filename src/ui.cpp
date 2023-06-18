#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "ui.hpp"

namespace info_pair {

namespace {
bool checkValideWord(std::string& a_word, bool & a_sign) 
{ 
    if (a_word.empty()) {
        return false;
    }
    if (a_word[0] == '-') {
        a_sign = false;
        a_word.erase(0,1);     
    }
    else {
        a_sign = true;
    }
    size_t size = a_word.size();
    if (size < 3) {
        return false;
    }
    for(size_t i = 0; i < size; ++i) {
        if(a_word[i] < 'a' || a_word[i] > 'z') {
            return false;
        }
    }
    return true;

}

bool isInteger(std::string const& a_input) 
{
    std::istringstream iss(a_input);
    int value;
    iss >> std::noskipws >> value;
    return iss.eof() && !iss.fail();
}

int getIntFromUser() {
    std::string input;
    std::getline(std::cin, input);

    while (!isInteger(input)) {
        std::cout << RED + "Invalid input. Please enter an integer: " +RESET;
        std::getline(std::cin, input);
    }

    return std::stoi(input);
}


std::string toLowerCase(std::string const& a_word) 
{
    std::string result;
    result.reserve(a_word.size());
    for(size_t i = 0; i < a_word.size(); ++i) {
        result.push_back(std::tolower(a_word[i]));
    }
    return result;
}
} //namespace

Query Ui::getWordsFromUser() const 
{
    Query query;
    std::string lowerSentence;
    bool invalid = false;
    bool onePositiv = false;
    for(;;) {
        std::string sentence;
        std::cout << BLUE+"Enter words to find: "+RESET;
        std::getline(std::cin, sentence);
        lowerSentence = toLowerCase(sentence);     
        std::istringstream iss(lowerSentence);
        std::string word;
        invalid = false;
        while (iss >> word) {
            bool sign;
            bool res = checkValideWord(word, sign);
            if (!res) {
                std::cout << RED+"Invalid input. Try again.\n"+RESET;
                invalid = true;
                break;
            }
            else {
                query.addWord(word, sign);
                if (sign) {
                    onePositiv = true;
                }
            }
            iss.clear();
        }
        if (!invalid && onePositiv) {
            break;
        }
    }
    return query;
}

std::string Ui::getUrlNameFromUser() const 
{
    std::string name;
    std::cout << BLUE+"Enter name of URL to find: " +RESET;
    std::cin >> name;
    return name;
}

std::string Ui::getUrlAdressFromUser() const 
{
    std::string url;
    std::cout << BLUE+"Enter URL adress to find: "+RESET;
    std::cin >> url;
    std::cout << std::endl;
    return url;
}

int Ui::printFirstMenu() const
{
    std::string choice;
    std::cout << GREEN+"Hello, welcome to InfoPair a Search Engine!"  << std::endl;
    std::cout << "Please select an option:" + RESET<< std::endl << std::endl;
    std::cout << MAGENTA + "1. Search words" << std::endl;
    std::cout << YELLOW + "2. Search a URL conactions" << std::endl;
    std::cout << CYAN + "3. Exit" + RESET << std::endl;
    std::cout << std::endl;
    std::cout << BLUE+ "choice: " + RESET;
    return getIntFromUser();
}



void Ui::printWordSearchMenu() const
{
    std::cout << GREEN + "Please enter words to search," << std::endl;
    std::cout << "you can search a negative term but you must have a positive term too." << std::endl;
     std::cout << "Negative term must have a '-' before the word." << std::endl;
    std::cout << "The terms must be at least 3 characters long, and only contain letters." + RESET << std::endl;
    std::cout << std::endl;
}

void Ui::printConactionsSearchMenu() const
{
    std::cout << GREEN +"Please enter a URL to search," << std::endl;
    std::cout << "the URL must be from the list." + RESET<< std::endl;
    std::cout << std::endl;
}

int Ui::printExitMenu() const
{
    std::cout << GREEN +"Are you sure you want to exit?" + RESET<< std::endl;
    std::cout << YELLOW + "1. Yes" + RESET<< std::endl;
    std::cout << CYAN + "2. No" + RESET<< std::endl;
    std::cout << std::endl;
    std::cout << BLUE + "choice: " + RESET;
    return getIntFromUser();
}

void Ui::printUrlData(std::string const& a_titel, std::string const& a_url, size_t const a_counter) const
{
    std::cout << BLUE + "Title: " << a_titel << std::endl;
    std::cout << "URL: " << a_url << std::endl;
    std::cout << "Counter: " << a_counter << std::endl;
    std::cout << RESET << std::endl;
}

void Ui::printWord(std::string const& a_word) const
{
    std::cout << BLUE + "Term: " <<a_word << std::endl;
    std::cout <<RESET << std::endl;
}

void Ui::printWorngIndex() const
{
    std::cout << RED+ "Worng user choice!" + RESET<< std::endl;
    std::cout << std::endl;
}

void Ui::noResult() const
{
    std::cout << MAGENTA + "No result!"  + RESET<< std::endl;
    std::cout << std::endl;
}

void Ui::printUrl(std::string const& a_url) const
{
    std::cout << GREEN + "URL: " <<a_url << std::endl;
    std::cout << RESET << std::endl;
}

void Ui::printAllUrls(std::vector<std::string> const& a_urlVec) const
{
    size_t i = 1;
    for(auto const& url : a_urlVec) {
        std::cout<< GREEN << i <<". " << url << std::endl;
        std::cout << RESET << std::endl;
        ++i;
    }
}

void Ui::printTitle() const 
{
    std::string asciiArt = R"(
  _____        __                 _____      _         _____                     _       ______             _            
 |_   _|      / _|               |  __ \    (_)       / ____|                   | |     |  ____|           (_)           
   | |  _ __ | |_ ___    ______  | |__) |_ _ _ _ __  | (___   ___  __ _ _ __ ___| |__   | |__   _ __   __ _ _ _ __   ___ 
   | | | '_ \|  _/ _ \  |______| |  ___/ _` | | '__|  \___ \ / _ \/ _` | '__/ __| '_ \  |  __| | '_ \ / _` | | '_ \ / _ \
  _| |_| | | | || (_) |          | |  | (_| | | |     ____) |  __/ (_| | | | (__| | | | | |____| | | | (_| | | | | |  __/
 |_____|_| |_|_| \___/           |_|   \__,_|_|_|    |_____/ \___|\__,_|_|  \___|_| |_| |______|_| |_|\__, |_|_| |_|\___|
                                                                                                       __/ |             
                                                                                                      |___/                     
    )";

    std::string color = GREEN + asciiArt + RESET;
    std::cout << color << std::endl;
}


}//info_pair
