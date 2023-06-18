#include <cstddef> //size_t
#include <cassert>
#include "selection_sort.hpp"

namespace strategy_pattern {

void SelectionSort::run(std::vector<int>& a_numbers) const
{
    size_t size = a_numbers.size();
    assert(size > 0);
	for(size_t i = 0 ; i < size - 1 ; ++i) {
        size_t minIndex = i;
        for(size_t j = i + 1; j < size; ++j) {
            if(a_numbers[j] < a_numbers[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            std::swap(a_numbers[i], a_numbers[minIndex]);
        }
	}

}

}//strategy_pattern
