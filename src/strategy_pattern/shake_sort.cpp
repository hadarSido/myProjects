#include <cstddef> //size_t
#include <cassert>
#include "shake_sort.hpp"

namespace strategy_pattern {


void ShakeSort::run(std::vector<int>& a_numbers) const 
{
    size_t size = a_numbers.size();
    assert(size > 0);
	size_t begin = 0;
    size_t end = size - 1;
	for(size_t i = 0; i < size - 1; ++i) {
		for(size_t j = begin; j < end; ++j) {
			if (a_numbers[j] > a_numbers[j + 1]) {
				std::swap(a_numbers[j], a_numbers[j+1]);
            }
        }
        for(size_t x = end ; x > begin; --x) {
            if (a_numbers[x - 1] > a_numbers[x]) {
				std::swap(a_numbers[x-1], a_numbers[x]);
            }
		}
        begin += 1;
        end -= 1;
	}
}




}//strategy_pattern
