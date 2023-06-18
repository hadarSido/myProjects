#include "message.hpp"
namespace precious_stone {

Message::Message(std::string a_str)
: m_str(a_str)
{}

std::string Message::getStr() const {
    return this->m_str;
}

Message& Message::changeStr(std::string a_str) {
    this->m_str = a_str;
    return *this;
}

}//precious_stone
