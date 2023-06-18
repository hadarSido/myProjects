#ifndef CONSOLE_SOURCE_HPP_208
#define CONSOLE_SOURCE_HPP_208
#include <iostream> //std::ostream , std::istream  members
#include <queue> //queue functions
#include "source.hpp"
#include "message.hpp"

namespace precious_stone {

class ConsoleSource final : public Source {
public:
    explicit ConsoleSource(std::ostream& a_output, std::istream& a_input);
    ConsoleSource(const ConsoleSource& a_other) = default;
    ConsoleSource& operator=(const ConsoleSource &a_other) = delete;                             
    ~ConsoleSource() override = default;

    Message readMessage() override;
    bool hasMoreData() const noexcept override;

private:
    std::ostream& m_output;
    std::istream& m_input;
    bool m_moreData;
};


}//precious_stone

#endif //CONSOLE_SOURCE_HPP_208