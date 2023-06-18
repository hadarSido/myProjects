#ifndef DESTINATION_HPP_208
#define DESTINATION_HPP_208
#include "message.hpp"

namespace precious_stone {

class Destination {
public:
    virtual ~Destination() = default;
    virtual void sendMessage(const Message& a_message) = 0;

protected:
    Destination() = default;
    Destination(const Destination& a_other) = delete;
    Destination& operator=(const Destination &a_other) = delete;


};



}//precious_stone

#endif //DESTINATION_HPP_208