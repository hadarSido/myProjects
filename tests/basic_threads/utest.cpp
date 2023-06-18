#include "mu_test.h"

#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <iostream>
#include <cassert>
#include <iterator>
#include <random>
#include <functional>

#include "basic_threads.hpp"


const size_t VECTOR_SIZE = 10'000'000;

void initRandVec(std::vector<double>& a_vec, size_t a_size)
{
    std::vector<double> numbers{};
    numbers.reserve(VECTOR_SIZE);
    for (size_t i = 0; i < VECTOR_SIZE; ++i) {
        numbers.push_back((static_cast<double>(std::rand()% (VECTOR_SIZE + 1))) / VECTOR_SIZE);
    }
}

std::vector<double> rVec;
size_t size = 100'000'000;
double expected_result;
double epsilon = 1e-4;

#undef TRACE
#define TRACE(x)


void test_transform(const char* input, const char* output, unsigned int n, std::function<sf::Color(sf::Color)> pixel_transform)
{
	advcpp::manipulatImage(input, output, n, pixel_transform);
}

BEGIN_TEST(prep_vector)
    initRandVec(rVec, size);
    ASSERT_PASS();
END_TEST

BEGIN_TEST(calc_threaded_sin_1)
    double result = advcpp::sumVectorWithMultiThreads(rVec, 1);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST

BEGIN_TEST(calc_threaded_sin_2)
    double result = advcpp::sumVectorWithMultiThreads(rVec, 2);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST

BEGIN_TEST(calc_threaded_sin_4)
    double result = advcpp::sumVectorWithMultiThreads(rVec, 4);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST

BEGIN_TEST(calc_threaded_sin_8)
    double result = advcpp::sumVectorWithMultiThreads(rVec, 8);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST


BEGIN_TEST(gray_image_1_threads)
	using namespace advcpp;
    auto grayFunc = [](sf::Color a_pixelColor) -> sf::Color {
        const size_t average = (a_pixelColor.r + a_pixelColor.g + a_pixelColor.b) / 3;
        return sf::Color(average, average, average);
    };
	manipulatImage("tt.jpg", "tt-gray.jpg" , 1, grayFunc);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(gray_image_4_threads)
	using namespace advcpp;
    auto grayFunc = [](sf::Color a_pixelColor) -> sf::Color {
        const size_t average = (a_pixelColor.r + a_pixelColor.g + a_pixelColor.b) / 3;
        return sf::Color(average, average, average);
    };
	manipulatImage("tt.jpg", "tt-gray.jpg" , 4, grayFunc);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(gray_image_8_threads)
	using namespace advcpp;
    auto grayFunc = [](sf::Color a_pixelColor) -> sf::Color {
        const size_t average = (a_pixelColor.r + a_pixelColor.g + a_pixelColor.b) / 3;
        return sf::Color(average, average, average);
    };
	manipulatImage("tt.jpg", "tt-gray.jpg" , 4, grayFunc);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(gray_image_16_threads)
	using namespace advcpp;
    auto grayFunc = [](sf::Color a_pixelColor) -> sf::Color {
        const size_t average = (a_pixelColor.r + a_pixelColor.g + a_pixelColor.b) / 3;
        return sf::Color(average, average, average);
    };
	manipulatImage("tt.jpg", "tt-gray.jpg" , 4, grayFunc);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(reduce_blue_4_threads_image)
	using namespace advcpp;

    auto reduceBlueFunc = [](sf::Color a_pixelColor) -> sf::Color {
        return sf::Color(a_pixelColor.r, a_pixelColor.g, a_pixelColor.b/2);
    };

    manipulatImage("tt.jpg", "tt-blue.jpg" , 4, reduceBlueFunc);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(reduce_color_4_threads_image)
	using namespace advcpp;

    auto reduceColorFunc = [](sf::Color a_pixelColor) -> sf::Color {
        return sf::Color(a_pixelColor.r/2, a_pixelColor.g/2, a_pixelColor.b/2);
    };

    manipulatImage("tt.jpg", "tt-color.jpg" , 4, reduceColorFunc);
	ASSERT_PASS();

END_TEST


BEGIN_TEST(reduce_color_to_8_1_threads_image)
	using namespace advcpp;

    auto reduceColorFunc = [](sf::Color a_pixelColor) -> sf::Color {
		auto [r,g,b, _] = a_pixelColor;
		r = r >= 128 ? 128 : 0;
		g = g >= 128 ? 128 : 0;
		b = b >= 128 ? 128 : 0;
        return sf::Color(r, g, b);
    };

    test_transform("tt.jpg", "tiger-color-1.jpg" , 1, reduceColorFunc);
	ASSERT_PASS();

END_TEST

BEGIN_TEST(reduce_color_to_8_4_threads_image)
	using namespace advcpp;

    auto reduceColorFunc = [](sf::Color a_pixelColor) -> sf::Color {
		auto [r,g,b, _] = a_pixelColor;
		r = r >= 128 ? 128 : 0;
		g = g >= 128 ? 128 : 0;
		b = b >= 128 ? 128 : 0;
        return sf::Color(r, g, b);
    };

    test_transform("tt.jpg", "tiger-color-4.jpg" , 1, reduceColorFunc);
	ASSERT_PASS();
END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
    TEST(prep_vector)

	TEST(calc_threaded_sin_1)
    TEST(calc_threaded_sin_2)
	TEST(calc_threaded_sin_4)
	TEST(calc_threaded_sin_8)
    TEST(gray_image_1_threads)
    TEST(gray_image_4_threads)
    TEST(gray_image_8_threads)
    TEST(gray_image_16_threads)
    TEST(reduce_blue_4_threads_image)
    TEST(reduce_color_4_threads_image)

	TEST(reduce_color_to_8_1_threads_image)
	TEST(reduce_color_to_8_4_threads_image)



END_SUITE
