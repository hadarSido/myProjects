#include "udp_destination.hpp"

namespace precious_stone {

UdpDestination::UdpDestination(int a_port, const std::string& a_ip)
: m_udp(communication::UdpServer(a_port, a_ip))
{}

void ConsoleDestination::sendMessage(const Message& a_message) {
    std::string str = a_message.getStr();
    this->m_udp.sendTo(str);
}


}//precious_stone
