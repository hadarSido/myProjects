#ifndef ENCODER_CAESAR_HPP_208
#define ENCODER_CAESAR_HPP_208
#include <string> //std:string
#include "message.hpp"
#include "encoder.hpp"

namespace precious_stone {

class EncoderCaesar final : public Encoder {
public:
    EncoderCaesar() = default;
    EncoderCaesar(const EncoderCaesar& a_other) = delete;
    EncoderCaesar& operator=(const EncoderCaesar &a_other) = delete;                             
    ~EncoderCaesar() override = default;

    const Message messageEncoder(Message& a_message) override;
};

}//precious_stone

#endif //ENCODER_CAESAR_HPP_208