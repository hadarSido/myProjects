#ifndef FILE_SOURCE_HPP_208
#define FILE_SOURCE_HPP_208
#include <iostream> //std::ostream, std::istream members
#include <queue>
#include "source.hpp"
#include "message.hpp"

namespace precious_stone {

class FileSource final : public Source {
public:
    FileSource(std::string a_fileName);
    FileSource(const FileSource& a_other) = default;
    FileSource& operator=(const FileSource &a_other) = delete;                             
    ~FileSource() override = default;

    Message readMessage() override;
    bool hasMoreData() const noexcept override;

protected:
    std::string m_fileName;
    std::queue<std::string> m_lines;

};

}//precious_stone

#endif //FILE_SOURCE_HPP_208

