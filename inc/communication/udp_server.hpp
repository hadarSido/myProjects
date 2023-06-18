#ifndef UDP_SERVER_HPP_208
#define UDP_SERVER_HPP_208
#include <sys/types.h> //socket, bind
#include <sys/socket.h> //struct sockaddr_in
#include <arpa/inet.h>//htons , struct sockaddr_in
#include <string> //std::string
#include "message.hpp"

namespace communication {

class UdpServer {
public:
    explicit UdpServer(const int a_port, const std::string& a_ip);
    UdpServer(const UdpServer& a_other) = delete;
    UdpServer& operator=(const UdpServer& a_other) = delete;                             
    ~UdpServer();

    void sendTo(const precious_stone::Message& a_message);
    std::string resevFrom();
    int getSock();
    std::string getBuffer();

private:
    int m_socket;
    struct sockaddr_in m_sin;
    std::string m_buffer;
};

}//communication

#endif //UDP_HPP_208

