#include "console_destination.hpp"


namespace precious_stone {

ConsoleDestination::ConsoleDestination(std::ostream& a_os) 
: m_os(a_os)
{}

void ConsoleDestination::sendMessage(const Message& a_message) {
    std::string str = a_message.getStr();
    this->m_os << str << std::endl;
}


}//precious_stone
