#ifndef UDP_SOURCE_HPP_208
#define UDP_SOURCE_HPP_208
#include <iostream> //std::ostream , std::istream  members
#include "source.hpp"
#include "udp_server.hpp"

namespace precious_stone {

class UdpSource final : public Source {
public:
    UdpSource(const int a_port, const std::string& a_ip);
    UdpSource(const UdpSource& a_other) = delete;
    UdpSource& operator=(const UdpSource &a_other) = delete;                             
    ~UdpSource() override = default;

    Message readMessage() override;
    bool hasMoreData() const noexcept override;

protected:
    communication::UdpServer m_udp;
    bool m_moreData;
};



}//precious_stone

#endif //FILE_SOURCE_HPP_208