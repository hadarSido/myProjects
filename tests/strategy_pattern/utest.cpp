#include <vector>
#include <iostream>
#include <random>

#include "selection_sort.hpp"
#include "shake_sort.hpp"
#include "quick_sort.hpp"
#include "sorting_manager.hpp"

int main() {
	using namespace strategy_pattern;
	size_t size = 1000;
	std::vector<int> vec1;
	std::vector<int> vec2;
	std::vector<int> vec3;
	vec1.reserve(size);
	vec2.reserve(size);
	vec3.reserve(size);
	std::random_device rd; 
    std::mt19937 gen(rd());
	for(size_t i = 0; i < size; ++i) {
		std::uniform_int_distribution<> dis(10, 1000);
        int randomNumber = dis(gen);
        vec1.push_back(randomNumber);
		vec2.push_back(randomNumber);
		vec3.push_back(randomNumber);
	}
	SelectionSort selction;
	SortingManager manag(selction);
	manag.runSort(vec1);
	ShakeSort shake;
	manag.setSort(shake);
	manag.runSort(vec2);
	QuickSort quick;
	manag.setSort(quick);
	manag.runSort(vec3);
	return 0;
}






