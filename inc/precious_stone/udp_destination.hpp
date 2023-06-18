#ifndef UDP_SOURCE_HPP_208
#define UDP_SOURCE_HPP_208
#include <iostream> //std::ostream , std::istream  members
#include "source.hpp"
#include "udp_server.hpp"

namespace precious_stone {

class UdpDestination final : public Source {
public:
    UdpDestination(const int a_port, const std::string& a_ip);
    UdpDestination(const UdpDestination& a_other) = delete;
    UdpDestination& operator=(const UdpDestination &a_other) = delete;                             
    ~UdpDestination() override = default;

    void sendMessage(const Message& a_message) override;


protected:
    const communication::UdpServer& m_udp;
    
};



}//precious_stone

#endif //FILE_SOURCE_HPP_208