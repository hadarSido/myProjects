#include "encoder_title.hpp"

namespace precious_stone {

const Message EncoderTitle::messageEncoder(Message& a_message) {
    std::string str = a_message.getStr();
    bool isNewWord = true;
    for(size_t i = 0; i < str.length() ; ++i) {
        if(isNewWord && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            isNewWord = false;
        }
        else if (isspace(str[i])) { // check if it's a whitespace
            isNewWord = true;
        }
    }
    return a_message.changeStr(str);
}

}//precious_stone
