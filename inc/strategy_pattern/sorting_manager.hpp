#pragma once
#include <vector>

#include "sort.hpp"

namespace strategy_pattern {

class SortingManager {
public:                            
    SortingManager(Sort& a_sort);
    SortingManager(SortingManager const& a_other) = delete; 
    SortingManager& operator=(SortingManager const&a_other) = delete; 
    ~SortingManager() = default;

    void setSort(Sort const& a_sort);
    void runSort(std::vector<int>& a_numbers) const;

private:
    Sort& m_sort;
};


}//strategy_pattern
