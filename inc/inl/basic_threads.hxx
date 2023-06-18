#include <thread> //thread, joine
#include <iostream>
#include <vector>
#include "basic_threads.hpp"


namespace advcpp {
namespace {

template<typename UnaryFunc>
void changePixelInImageSharpen(sf::Image& a_image, size_t a_heightBegin, size_t a_heightEnd, size_t a_widthBegin, size_t a_widthEnd, UnaryFunc a_func) {
    for (size_t y = a_heightBegin; y < a_heightEnd; ++y) {
        for (size_t x = a_widthBegin; x < a_widthEnd; ++x) {
            sf::Color newColor = a_func(a_image, x, y);
            a_image.setPixel(x, y, newColor);
        }
    }
}

} //namespace

template <typename Iterator>
double sumVector(Iterator a_begin, Iterator a_end) 
{
    double result = 0;
	while(a_begin != a_end) {
		auto x = *a_begin;
		double s = 0.0;
		auto sinc = 1;
		if(x != 0) {
			s = sin(x);
			sinc = s/x;
		}
		result += s*s + sinc;
		++a_begin;
	}
	return result;
}

 
template<typename UnaryFunc>
sf::Image manipulatImage(sf::Image const& a_image, size_t a_numOfThreads, UnaryFunc a_func) {
    sf::Image image = a_image;
  
    size_t height = a_image.getSize().y;
    size_t sectionHeight = height / a_numOfThreads;
    size_t start = 0;

    size_t width = a_image.getSize().x;
    size_t a_widthBegin = 0;
    size_t a_widthEnd = width;

    std::vector<std::thread> threads;
    threads.reserve(a_numOfThreads);

    for (size_t i = 0; i < a_numOfThreads - 1; ++i) {
        auto activeFunc = [&a_image, &image, a_func, a_widthBegin, a_widthEnd](size_t a_heightBegin, size_t a_heightEnd, size_t a_index){
            changePixelInImageSharpen(image, a_heightBegin, a_heightEnd, a_widthBegin, a_widthEnd, a_func);
        };
        threads.emplace_back(activeFunc, start, start + sectionHeight, i);
        start += sectionHeight;
    }

    auto activeFunc = [&a_image, &image, a_func, a_widthBegin, a_widthEnd](size_t a_heightBegin, size_t a_heightEnd, size_t a_index){
        changePixelInImageSharpen(image, a_heightBegin, a_heightEnd, a_widthBegin, a_widthEnd, a_func);
    };

    activeFunc(start, height,  a_numOfThreads - 1); //last segmen

    joinAll(threads);
    return image;
}


}//advcpp
