#include <cassert>//assert
#include <cstring>//memset
#include <unistd.h>//close
#include "udp_server.hpp"
namespace communication {
    
static int createSocket();
static struct sockaddr_in createSin(int a_sock,int a_port, const std::string& a_ip);
static std::string createStr(int a_size);

UdpServer::UdpServer(const int a_port, const std::string& a_ip)
: m_socket(createSocket())
, m_sin(createSin(m_socket, a_port, a_ip))
, m_buffer(createStr(30))
{}

UdpServer::~UdpServer() {
    close(this->m_socket);
}

std::string UdpServer::resevFrom() {
    socklen_t sinSize = sizeof(this->m_sin);
    int readBytes = recvfrom(this->m_socket, &this->m_buffer[0], this->m_buffer.size(), 0 , (struct sockaddr *) &this->m_sin, &sinSize);
    assert(readBytes > 0);
    return this->m_buffer;
}

void UdpServer::sendTo(const precious_stone::Message& a_message) {
    int sentBytes = sendto(this->m_socket, a_message.getStr().c_str(), a_message.getStr().size() + 1, 0, (struct sockaddr *) &this->m_sin, sizeof(this->m_sin));
    assert(sentBytes > 0);
}

static int createSocket() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    assert(sock > 0);
    return sock;
}

static struct sockaddr_in createSin(int a_sock,int a_port, const std::string& a_ip) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(a_ip.c_str());
    sin.sin_port = htons(a_port);
    assert(bind(a_sock, (struct sockaddr*) &sin, sizeof(sin)) >= 0);
    return sin;
}

static std::string createStr(int a_size) {
    std::string str(a_size, ' ');
    return str;
}

int UdpServer::getSock() {
    return this->m_socket;
}

std::string UdpServer::getBuffer() {
    return this->m_buffer;
}




}//communication
