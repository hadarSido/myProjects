#include "console_source.hpp"

namespace precious_stone {

ConsoleSource::ConsoleSource(std::ostream& a_output, std::istream& a_input)
: m_output(a_output)
, m_input(a_input)
, m_moreData(true)
{}

Message ConsoleSource::readMessage() {
    std::string str;
    this->m_output << "Enter your message (to stop enter 0): ";
    std::getline(this->m_input, str);
    Message newMessage(str);
    if(newMessage.getStr() == "0") {
        this->m_moreData = false;
    }
    return newMessage;
}

bool ConsoleSource::hasMoreData() const noexcept {
    return this->m_moreData;
}


}//precious_stone
