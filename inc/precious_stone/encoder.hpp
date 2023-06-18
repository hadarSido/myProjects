#ifndef ENCODER_HPP_208
#define ENCODER_HPP_208
#include "message.hpp"

namespace precious_stone {

class Encoder {
public:                            
    virtual ~Encoder() = default;
    virtual const Message messageEncoder(Message& a_message) = 0;

protected:
    Encoder() = default;
    Encoder(const Encoder& a_other) = delete;
    Encoder& operator=(const Encoder &a_other) = delete; 

};


}//precious_stone

#endif //ENCODER_HPP_208