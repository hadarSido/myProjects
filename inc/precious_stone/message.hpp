#ifndef MESSAGE_HPP_208
#define MESSAGE_HPP_208
#include <string> // std::string
#include <iostream> //std

namespace precious_stone {

class Message {
public:
    Message() = default;
    explicit Message(std::string a_str);
    Message(const Message& a_other) = default;
    Message& operator=(const Message &a_other) = default;                             
    ~Message() = default;

    std::string getStr() const;
    Message& changeStr(std::string a_str);

private:
    std::string m_str;
};



}//precious_stone

#endif //MESSAGE_HPP_208