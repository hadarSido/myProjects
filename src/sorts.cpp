#include <iostream>
#include "sorts.hpp"
namespace advcpp {

void bubbleSort(std::vector<int>& a_vec) {
    size_t size = a_vec.size();
    if(size == 0){
        throw std::runtime_error("The vector is empty.");
    }
	int flag = 0;
	for(size_t i = 0; i < size - 1; ++i) {
		for(size_t j = 0; j < size - i - 1; ++j) {
			if (a_vec[j] > a_vec[j + 1]) {
				std::swap (a_vec[j], a_vec[j+1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		else {
			flag = 0;
		}
	}
}

void shakeSort(std::vector<int>& a_vec) {
    size_t size = a_vec.size();
    if(size == 0){
        throw std::runtime_error("The vector is empty.");
    }
	size_t begin = 0;
    size_t end = size - 1;
	for(size_t i = 0; i < size - 1; ++i) {
		for(size_t j = begin; j < end; ++j) {
			if (a_vec[j] > a_vec[j + 1]) {
				std::swap(a_vec[j], a_vec[j+1]);
            }
        }
        for(size_t x = end ; x > begin; --x) {
            if (a_vec[x - 1] > a_vec[x]) {
				std::swap(a_vec[x-1], a_vec[x]);
            }
		}
        begin += 1;
        end -= 1;
	}
}

void selectionSort(std::vector<int>& a_vec) {
    size_t size = a_vec.size();
    if(size == 0) { 
        throw std::runtime_error("The vector is empty.");
    }
	for(size_t i = 0 ; i < size - 1 ; ++i) {
        size_t minIndex = i;
        for(size_t j = i + 1; j < size; ++j) {
            if(a_vec[j] < a_vec[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            std::swap(a_vec[i], a_vec[minIndex]);
        }
	}
}



bool isSortOK(std::vector<int>& a_vec) {
    size_t size = a_vec.size();
    if(size == 0){
        return true;
    }
    for(size_t i = 0; i < size - 1 ; ++i) {
        if(a_vec[i] > a_vec[i + 1]) {
            return false;
        }
    }
    return true;
}

void printVector(std::vector<int>& a_vec) {
    size_t size = a_vec.size();
    if(size == 0){
        throw std::runtime_error("The vector is empty.");
    }
    for (size_t i = 0; i < a_vec.size(); ++i) {
        std::cout << a_vec[i] << " ";
    }
    std::cout << std::endl;
}


}//advcpp