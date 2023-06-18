#pragma once
#include <SFML/Graphics/Image.hpp>
#include <iterator>
#include <thread>
namespace advcpp {

template <typename Iterator>
double sumVector(Iterator a_begin, Iterator a_end);

double sumVectorWithMultiThreads(std::vector<double> const& a_doublesNumbers, size_t a_threadNum);

void joinAll(std::vector<std::thread>& a_threads);

template<typename UnaryFunc>
sf::Image manipulatImage(sf::Image const& a_image, size_t a_numOfThreads, UnaryFunc a_func);

sf::Color blurColorFunc3X3 (sf::Image& a_image, size_t a_x, size_t a_y);
sf::Color blurColorFunc5X5 (sf::Image& a_image, size_t a_x, size_t a_y);
sf::Color medianColorFunc5X5 (sf::Image& a_image, size_t a_x, size_t a_y);
sf::Color medianColorFunc3X3 (sf::Image& a_image, size_t a_x, size_t a_y);
 sf::Color sharpColorFunc3X3 (sf::Image& a_image, size_t a_x, size_t a_y);

sf::Color grayFunc (sf::Image& a_image, size_t a_x, size_t a_y);
sf::Color reduceBlueFunc (sf::Image& a_image, size_t a_x, size_t a_y);
sf::Color reduceColorFunc (sf::Image& a_image, size_t a_x, size_t a_y);

template <typename Iterator>
double sumVector(Iterator a_begin, Iterator a_end);

}//advcpp

#include "inl/basic_threads.hxx"
