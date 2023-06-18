#pragma once
#include <vector>

#include "sort.hpp"

namespace strategy_pattern {

class ShakeSort : public Sort {
public:                            
    ShakeSort() = default;
    ShakeSort(ShakeSort const& a_other) = default; 
    ShakeSort& operator=(ShakeSort const& a_other) = default; 
    ~ShakeSort() override = default;

    void run(std::vector<int>& a_numbers) const override;

};


}//strategy_pattern
