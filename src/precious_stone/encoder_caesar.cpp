#include "encoder_caesar.hpp"

static const size_t CAESAR_SHIFT = 13;

namespace precious_stone {

const Message EncoderCaesar::messageEncoder(Message& a_message) {
    std::string str = a_message.getStr();
    for(size_t i = 0; i < str.length() ; ++i) {
        if(isalpha(str[i])) {
            if(isupper(str[i])) {
                str[i] = (str[i] - 'A' + CAESAR_SHIFT) % 26 + 'A';
            }
            else {
                str[i] = (str[i] - 'a' + CAESAR_SHIFT) % 26 + 'a';
            }
        }
    }
    return a_message.changeStr(str);
}

}//precious_stone