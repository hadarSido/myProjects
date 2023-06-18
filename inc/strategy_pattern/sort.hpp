#pragma once
#include <vector>

namespace strategy_pattern {

class Sort {
public:                            
    virtual ~Sort() = default;
    virtual void run(std::vector<int>& a_numbers) const = 0;
    Sort& operator=(Sort const& a_other) = default; 

protected:
    Sort() = default;
    Sort(Sort const& a_other) = default; 
};


}//strategy_pattern
