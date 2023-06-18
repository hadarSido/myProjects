#ifndef FILE_DESTINATION_HPP_208
#define FILE_DESTINATION_HPP_208
#include <iostream> //std::ostream, std::istream members
#include "destination.hpp"
#include "message.hpp"

namespace precious_stone {


class FileDestination final : public Destination {
public:
    explicit FileDestination(std::string a_fileName);
    FileDestination(const FileDestination& a_other) = default;
    FileDestination& operator=(const FileDestination &a_other) = default;                             
    ~FileDestination() override = default;

    void sendMessage(const Message& a_message) override;

private:
    std::string m_fileName;
};


}//precious_stone

#endif //FILE_DESTINATION_HPP_208

