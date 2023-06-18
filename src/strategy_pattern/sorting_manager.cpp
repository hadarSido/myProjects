#include "shake_sort.hpp"
#include "sorting_manager.hpp"

namespace strategy_pattern {

SortingManager::SortingManager(Sort& a_sort) 
: m_sort(a_sort)
{}

void SortingManager::setSort(Sort const& a_sort) 
{
    m_sort = a_sort;
}

void SortingManager::runSort(std::vector<int>& a_numbers) const
{
    m_sort.run(a_numbers);
}




}//strategy_pattern
