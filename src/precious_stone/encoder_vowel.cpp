#include "encoder_vowel.hpp"

namespace precious_stone {

const Message EncoderVowel::messageEncoder(Message& a_message) {
    std::string str = a_message.getStr();
    for(size_t i = 0; i < str.length() ; ++i){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u') {
            str[i] = '*';
        }
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'O' || str[i] == 'I' || str[i] == 'U') {
            str[i] = '*';
        }
    }
    return a_message.changeStr(str);
}

}//precious_stone
