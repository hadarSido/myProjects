#ifndef CONSOLE_DESTINATION_HPP_208
#define CONSOLE_DESTINATION_HPP_208
#include <iostream> //std::ostream& member
#include "destination.hpp"
#include "message.hpp"

namespace precious_stone {

class ConsoleDestination final : public Destination {
public:
    explicit ConsoleDestination(std::ostream& a_os);
    ConsoleDestination(const ConsoleDestination& a_other) = default;
    ConsoleDestination& operator=(const ConsoleDestination &a_other) = default;                             
    ~ConsoleDestination() override = default;

    void sendMessage(const Message& a_message) override;

private:
    std::ostream& m_os;
};

}//precious_stone

#endif //CONSOLE_DESTINATION_HPP_208