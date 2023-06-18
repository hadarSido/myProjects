#ifndef ENCODER_VOWEL_HPP_208
#define ENCODER_VOWEL_HPP_208
#include <string> //std:string
#include "message.hpp"
#include "encoder.hpp"

namespace precious_stone {

class EncoderVowel final : public Encoder {
public:
    EncoderVowel() = default;
    EncoderVowel(const EncoderVowel& a_other) = delete;
    EncoderVowel& operator=(const EncoderVowel &a_other) = delete;                             
    ~EncoderVowel() override = default;

    const Message messageEncoder(Message& a_message) override;
};

}//precious_stone

#endif //ENCODER_VOWEL_HPP_208