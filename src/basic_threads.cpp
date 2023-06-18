#include <vector> //std::vector
#include <cmath> //sin
#include <numeric>
#include "basic_threads.hpp"

namespace advcpp {
namespace {

bool compareColor(const sf::Color& c1, const sf::Color& c2) {
    return (c1.r + c1.g + c1.b)/3   < (c2.r + c2.g + c2.b)/3;
}

} //namespce

void joinAll(std::vector<std::thread>& a_threads) {
    for (auto& thread : a_threads) {
        thread.join();
    }
}


double sumVectorWithMultiThreads(std::vector<double> const& a_doublesNumbers, size_t a_threadNum)  
{
    std::vector<std::thread> threads;
    threads.reserve(a_threadNum - 1);

    std::vector<double> results(a_threadNum * 16);
	auto f = [&results](auto a_begin, auto a_end, auto a_index){
		results[a_index] = sumVector(a_begin, a_end);
	};

    auto segment = a_doublesNumbers.size() / a_threadNum;
	auto start = a_doublesNumbers.begin();

    auto i = 0;
    while(a_threadNum-- > 1) {
		auto end = start + segment;
		auto slot = i++ * 16;
		threads.emplace_back(f, start, end, slot);
		start = end;
    }
    
    f(start, a_doublesNumbers.end(),  i * 16); //last segmant
    joinAll(threads);

    return std::accumulate(results.begin(), results.end(), 0.0);
}

sf::Color blurColorFunc3X3 (sf::Image& a_image, size_t a_x, size_t a_y) {
    float newRed = 0;
    float newGreen = 0;
    float newBlue = 0;
    float kernel[3][3] = {{1/16.0f, 2/16.0f, 1/16.0f}, {2/16.0f, 4/16.0f, 2/16.0f}, {1/16.0f, 2/16.0f, 1/16.0f}};
    for (int i = -1; i <=1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            float x = static_cast<float>(a_x + i);
            float y = static_cast<float>(a_y + j);
            if(x < 0 || y < 0 || x >= static_cast<float>(a_image.getSize().x) || y >= static_cast<float>(a_image.getSize().y)) { //out of bunderies
                continue;
            }
            sf::Color pixel = a_image.getPixel(static_cast<size_t>(x), static_cast<size_t>(y));
            newRed += pixel.r * kernel[i+1][j+1];
            newGreen += pixel.g * kernel[i+1][j+1];
            newBlue += pixel.b * kernel[i+1][j+1];
        }
    }
    return sf::Color(static_cast<size_t>(newRed), static_cast<size_t>(newGreen), static_cast<size_t>(newBlue));
}


sf::Color blurColorFunc5X5 (sf::Image& a_image, size_t a_x, size_t a_y) {
    float newRed = 0;
    float newGreen = 0;
    float newBlue = 0;
    float sharpen[5][5] = {{1, 4, 6, 4, 1}, {4, 16, 24, 16, 4}, {6, 24, 36, 24, 6}, {4, 16, 24, 16, 4}, {1, 4, 6, 4, 1}};
    for (int i = -2; i <=2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            float x = static_cast<float>(a_x);
            float y = static_cast<float>(a_y);
            if(x < 0 || y < 0 || x >= static_cast<float>(a_image.getSize().x) || y >= static_cast<float>(a_image.getSize().y)) { //out of bunderies
                continue;
            }
            sf::Color pixel = a_image.getPixel(x, y);
            newRed += pixel.r * sharpen[i+2][j+2] / 256;
            newGreen += pixel.g * sharpen[i+2][j+2] / 256;
            newBlue += pixel.b * sharpen[i+2][j+2] / 256 ;
        }
    }
    return sf::Color(static_cast<size_t>(newRed), static_cast<size_t>(newGreen), static_cast<size_t>(newBlue));
}

sf::Color medianColorFunc3X3 (sf::Image& a_image, size_t a_x, size_t a_y) {
    size_t size = 9;
    std::vector<sf::Color> medianFinder;
    medianFinder.reserve(size);
    for (int i = -1; i <=1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            float x = static_cast<float>(a_x);
            float y = static_cast<float>(a_y);
            if(x < 0 || y < 0 || x >= static_cast<float>(a_image.getSize().x) || y >= static_cast<float>(a_image.getSize().y)) { //out of bunderies
                continue;
            }
            sf::Color pixel = a_image.getPixel(x, y);
            medianFinder.push_back(pixel);
        }
    }
    std::sort(medianFinder.begin(), medianFinder.end(), compareColor);
    sf::Color newPixel = medianFinder.at(size/2 + 1);
    return newPixel;
}


sf::Color medianColorFunc5X5 (sf::Image& a_image, size_t a_x, size_t a_y)  {
    size_t size = 25;
    std::vector<sf::Color> medianFinder;
    medianFinder.reserve(size);
    for (int i = -2; i <=2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            float x = static_cast<float>(a_x);
            float y = static_cast<float>(a_y);
            if(x < 0 || y < 0 || x >= static_cast<float>(a_image.getSize().x) || y >= static_cast<float>(a_image.getSize().y)) { //out of bunderies
                continue;
            }
            sf::Color pixel = a_image.getPixel(x, y);
            medianFinder.push_back(pixel);
        }
    }
    std::sort(medianFinder.begin(), medianFinder.end(), compareColor);
    sf::Color newPixel = medianFinder.at(size/2 + 1);
    return newPixel;
}

 sf::Color sharpColorFunc3X3 (sf::Image& a_image, size_t a_x, size_t a_y) {
    int newRed = 0;
    int newGreen = 0;
    int newBlue = 0;
    int sharpen[3][3] = {{0,-1, 0}, {-1, 5,-1}, {0,-1,0}};
    for (int i = -1; i <=1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int x = static_cast<int>(a_x);
            int y = static_cast<int>(a_y);
            if(x < 0 || y < 0 || x >= static_cast<int>(a_image.getSize().x) || y >= static_cast<int>(a_image.getSize().y)) { //out of bunderies
                continue;
            }
            sf::Color pixel = a_image.getPixel(x, y);
            newRed += pixel.r * sharpen[i+1][j+1];
            newGreen += pixel.g * sharpen[i+1][j+1];
            newBlue += pixel.b * sharpen[i+1][j+1];
        }
    }
        newRed = (newRed < 0) ? 0 : ((newRed > 255) ? 255 : newRed);
        newGreen = (newGreen < 0) ? 0 : ((newGreen > 255) ? 255 : newGreen);
        newBlue = (newBlue < 0) ? 0 : ((newBlue > 255) ? 255 : newBlue);

    return sf::Color(static_cast<size_t>(newRed), static_cast<size_t>(newGreen), static_cast<size_t>(newBlue));
}

sf::Color grayFunc (sf::Image& a_image, size_t a_x, size_t a_y) {
    sf::Color pixel = a_image.getPixel(a_x, a_y);
    const size_t average = (pixel.r + pixel.g + pixel.b) / 3;
    return sf::Color(average, average, average);
}

sf::Color reduceBlueFunc (sf::Image& a_image, size_t a_x, size_t a_y) {
    sf::Color pixel = a_image.getPixel(a_x, a_y);
    return sf::Color(pixel.r, pixel.g, pixel.b/2);
}

sf::Color reduceColorFunc (sf::Image& a_image, size_t a_x, size_t a_y) {
    sf::Color pixel = a_image.getPixel(a_x, a_y);
    auto [r,g,b, _] = pixel;
    r = r >= 128 ? 128 : 0;
    g = g >= 128 ? 128 : 0;
    b = b >= 128 ? 128 : 0;
    return sf::Color(r, g, b);
}
    
} //advcpp
