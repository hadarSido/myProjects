#include <fstream> //file functions
#include <cassert>//assert
#include <iostream>
#include <fstream>
#include <string>
#include "file_source.hpp"
namespace precious_stone {
static std::queue<std::string> addLines(std::string a_fileName);

FileSource::FileSource(std::string a_fileName)
: m_fileName(a_fileName)
, m_lines(addLines(a_fileName))
{}

Message FileSource::readMessage() {
    std::string str = this->m_lines.front();
    Message newMessage {str};
    this->m_lines.pop();
    return newMessage;
}

bool FileSource::hasMoreData() const noexcept {
    return !m_lines.empty();
}

static std::queue<std::string> addLines(std::string a_fileName) {
    std::string line;
    std::queue<std::string> linesSaver {};
    std::ifstream file(a_fileName);
    assert(file.is_open());
    while(std::getline(file, line)) {
        linesSaver.push(line);
        if(file.eof()) {
            break;
        }
    }
    if(file.eof() && file.fail()) {
        linesSaver.push("");
    }
    file.close();
    return linesSaver;
}



}//precious_stone






	