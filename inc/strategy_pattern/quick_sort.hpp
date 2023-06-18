#pragma once
#include <vector>

#include "sort.hpp"

namespace strategy_pattern {

class QuickSort : public Sort {
public:                            
    QuickSort() = default;
    QuickSort(QuickSort const& a_other) = default; 
    QuickSort& operator=(QuickSort const&a_other) = default; 
    ~QuickSort() override = default;

    void run(std::vector<int>& a_numbers) const override;

};


}//strategy_pattern
