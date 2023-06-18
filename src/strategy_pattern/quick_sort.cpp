#include <cstddef> //size_t
#include <cassert>
#include "quick_sort.hpp"

namespace strategy_pattern {
namespace{
size_t partition(std::vector<int>& a_numbers, size_t a_low, size_t a_high) {
    int pivot = a_numbers[a_high];
    size_t i = a_low - 1;

    for (size_t j = a_low; j <= a_high - 1; ++j) {
        if (a_numbers[j] < pivot) {
            ++i;
            std::swap(a_numbers[i], a_numbers[j]);
        }
    }

    std::swap(a_numbers[i + 1], a_numbers[a_high]);
    return i + 1;
}

void quickSort(std::vector<int>& a_numbers, size_t a_low, size_t a_high) {
    if (a_low < a_high) {
        size_t pivot = partition(a_numbers, a_low, a_high);
        quickSort(a_numbers, a_low, pivot - 1);
        quickSort(a_numbers, pivot + 1, a_high);
    }
}

}//namespace

void QuickSort::run(std::vector<int>& a_numbers) const 
{
    size_t size = a_numbers.size();
    assert(size > 0);
    quickSort(a_numbers, 0, a_numbers.size() - 1);
}


}//strategy_pattern
