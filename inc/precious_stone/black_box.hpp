#ifndef BLACK_BOX_HPP_208
#define BLACK_BOX_HPP_208
#include "destination.hpp"
#include "source.hpp"
#include "encoder.hpp"

#include "console_destination.hpp"
#include "console_source.hpp"
#include "encoder_vowel.hpp"

namespace precious_stone {

class BlackBox {
public:
    BlackBox() = default;
    explicit BlackBox(Source& a_source, Destination& a_destination, Encoder& a_encoder);
    BlackBox(const BlackBox& a_other) = delete;
    BlackBox& operator=(const BlackBox& ) = delete;                           
    ~BlackBox() = default;

    void executer() const;

private:
    Source& m_source;
    Destination& m_destination;
    Encoder& m_encoder;

};


}//precious_stone

#endif //BLACK_BOX_HPP_208