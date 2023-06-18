#include <fstream> //file functions
#include <cassert>//assert
#include <string>
#include <iostream>
#include "file_destination.hpp"

namespace precious_stone {


FileDestination::FileDestination(std::string a_fileName)
: m_fileName(a_fileName)
{}

void FileDestination::sendMessage(const Message& a_message) {
    std::string str = a_message.getStr();
    std::ofstream file;
    file.open(m_fileName, std::ios::app) ;
    assert(file.is_open());
    file << str <<std::endl;
    file.close();
}


}//precious_stone











	