#include "udp_source.hpp"

namespace precious_stone {

UdpSource::UdpSource(int a_port, const std::string& a_ip)
: m_udp(communication::UdpServer(a_port, a_ip))
, m_moreData(true)
{}

Message UdpSource::readMessage() {
    std::string inputStr;
    std::cout << "Enter your message (to stop enter 0): ";
    std::getline(std::cin, inputStr);
    Message newMessage(inputStr);
    this->m_udp.sendTo(newMessage);
    if(newMessage.getStr() == "0") {
        this->m_moreData = false;
    }
    return newMessage;
}

bool UdpSource::hasMoreData() const noexcept {
    return this->m_moreData;
}



}//precious_stone
// ConsoleSource::ConsoleSource(std::ostream& a_output, std::istream& a_input)
// : m_output(a_output)
// , m_input(a_input)
// , m_moreData(true)
// {}

// Message ConsoleSource::readMessage() {
//     std::string str;
//     this->m_output << "Enter your message (to stop enter 0): ";
//     std::getline(this->m_input, str);
//     Message newMessage(str);
//     if(newMessage.getStr() == "0") {
//         this->m_moreData = false;
//     }
//     return newMessage;
// }

// bool ConsoleSource::hasMoreData() const noexcept {
//     return this->m_moreData;
// }
