#ifndef ENCODER_TITLE_HPP_208
#define ENCODER_TITLE_HPP_208
#include <string> //std:string
#include "message.hpp"
#include "encoder.hpp"

namespace precious_stone {

class EncoderTitle final : public Encoder {
public:
    EncoderTitle() = default;
    EncoderTitle(const EncoderTitle& a_other) = delete;
    EncoderTitle& operator=(const EncoderTitle &a_other) = delete;                             
    ~EncoderTitle() override = default;

    const Message messageEncoder(Message& a_message) override;
};

}//precious_stone

#endif //ENCODER_TITLE_HPP_208