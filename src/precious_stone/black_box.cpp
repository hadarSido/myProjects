#include "black_box.hpp"

namespace precious_stone {

BlackBox::BlackBox(Source& a_source, Destination& a_destination, Encoder& a_encoder)
: m_source(a_source)
, m_destination(a_destination)
, m_encoder(a_encoder)
{}


void BlackBox::executer() const {
    while (m_source.hasMoreData()) {
        Message transferMessage = this->m_source.readMessage();
        transferMessage = this->m_encoder.messageEncoder(transferMessage);
        this->m_destination.sendMessage(transferMessage);
    }
}


}//precious_stone
