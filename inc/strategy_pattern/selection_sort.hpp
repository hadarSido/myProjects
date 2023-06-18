#pragma once
#include <vector>

#include "sort.hpp"

namespace strategy_pattern {

class SelectionSort : public Sort {
public:                            
    SelectionSort() = default;
    SelectionSort(SelectionSort const& a_other) = default; 
    SelectionSort& operator=(SelectionSort const& a_other) = default; 
    ~SelectionSort() override = default;

    void run(std::vector<int>& a_numbers) const override;

};


}//strategy_pattern
