#ifndef SOURCE_HPP_208
#define SOURCE_HPP_208
#include "message.hpp"

namespace precious_stone {

class Source {
public:                            
    virtual ~Source() = default;
    virtual Message readMessage() = 0;
    virtual bool hasMoreData() const noexcept = 0;

protected:
    Source() = default;
    Source(const Source& a_other) = delete; 
    Source& operator=(const Source &a_other) = delete; 
};


}//precious_stone

#endif //SOURCE_HPP_208