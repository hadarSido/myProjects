#include "mu_test.h"

#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <iostream>
#include <cassert>
#include <iterator>
#include <random>
#include <functional>

#include <algorithm> // sort function
#include "basic_threads.hpp"


BEGIN_TEST(gray_image_1_threads)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 1, grayFunc);
     if (!newImage.saveToFile("images/out-tiger-gray-1.jpg")) {
        std::cerr << "can't save image";
    }
    
	ASSERT_PASS();

END_TEST

BEGIN_TEST(gray_image_4_threads)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }

    sf::Image newImage = manipulatImage(image , 4, grayFunc);
     if (!newImage.saveToFile("images/out-tiger-gray-4.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(gray_image_8_threads)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }

    sf::Image newImage = manipulatImage(image , 8, grayFunc);
     if (!newImage.saveToFile("images/out-tiger-gray-8.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(gray_image_16_threads)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image, 16, grayFunc);

    if (!newImage.saveToFile("images/out-tiger-gray-16.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(reduce_blue_4_threads_image)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }

    sf::Image newImage = manipulatImage(image , 4, reduceBlueFunc);
     if (!newImage.saveToFile("images/out-tiger-blue-4.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(reduce_color_4_threads_image)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    auto reduceColorFunc = [](sf::Image& a_image, size_t a_x, size_t a_y) -> sf::Color {
		sf::Color pixel = a_image.getPixel(a_x, a_y);
        return sf::Color(pixel.r/2, pixel.g/2, pixel.b/2);
    };
    sf::Image newImage = manipulatImage(image , 4, reduceColorFunc);
     if (!newImage.saveToFile("images/out-tiger-color-4.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST


BEGIN_TEST(reduce_color_to_8_1_threads_image)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 8, reduceColorFunc);
     if (!newImage.saveToFile("images/out-tiger-color-8.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST


BEGIN_TEST(sharpen_image_1_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 1, sharpColorFunc3X3);
     if (!newImage.saveToFile("images/out-tiger-sharp-1-3X3.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(sharpen_image_2_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 2, sharpColorFunc3X3);
     if (!newImage.saveToFile("images/out-tiger-sharp-2-3X3.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(sharpen_image_4_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 4, sharpColorFunc3X3);
     if (!newImage.saveToFile("images/out-tiger-sharp-4-3X3.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST

BEGIN_TEST(blur_image_1_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 1, blurColorFunc3X3);
     if (!newImage.saveToFile("images/out-tiger-blur-1-3X3.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(blur_image_2_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }

    sf::Image newImage = manipulatImage(image , 2, blurColorFunc3X3);
     if (!newImage.saveToFile("images/out-tiger-blur-2-3X3.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST

BEGIN_TEST(blur_image_4_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 4, blurColorFunc3X3);
     if (!newImage.saveToFile("images/out-tiger-blur-4-3X3.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST



BEGIN_TEST(blur_image_1_threads_image_5X5)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 1, blurColorFunc5X5);
    if (!newImage.saveToFile("images/out-tiger-blur-1-5X5.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST

BEGIN_TEST(blur_image_2_threads_image_5X5)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 2, blurColorFunc5X5);
    if (!newImage.saveToFile("images/out-tiger-blur-2-5X5.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST

BEGIN_TEST(blur_image_4_threads_image_5X5)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 4, blurColorFunc5X5);
    if (!newImage.saveToFile("images/out-tiger-blur-4-5X5.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST
///

BEGIN_TEST(median_image_1_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 1, medianColorFunc3X3);
    if (!newImage.saveToFile("images/out-tiger-median-1-3X3.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST

BEGIN_TEST(median_image_2_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 2, medianColorFunc3X3);
    if (!newImage.saveToFile("images/out-tiger-median-2-3X3.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST
BEGIN_TEST(median_image_4_threads_image_3X3)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 4, medianColorFunc3X3);
    if (!newImage.saveToFile("images/out-tiger-median-4-3X3.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST


BEGIN_TEST(median_image_1_threads_image_5X5)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 1, medianColorFunc5X5);
    if (!newImage.saveToFile("images/out-tiger-median-1-5X5.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST

BEGIN_TEST(median_image_2_threads_image_5X5)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
    sf::Image newImage = manipulatImage(image , 2, medianColorFunc5X5);
    if (!newImage.saveToFile("images/out-tiger-median-2-5X5.jpg")) {
        std::cerr << "can't save image";
    }
	ASSERT_PASS();

END_TEST
BEGIN_TEST(median_image_4_threads_image_5X5)
	using namespace advcpp;
    sf::Image image;
    if (!image.loadFromFile("images/tiger.jpg")) {
        std::cerr << "can't open image \n";
    }
     sf::Image newImage = manipulatImage(image , 4, medianColorFunc5X5);
    if (!newImage.saveToFile("images/out-tiger-median-4-5X5.jpg")) {
        std::cerr << "can't save image";
    }

	ASSERT_PASS();

END_TEST
TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
    TEST(gray_image_1_threads)
    TEST(gray_image_4_threads)
    TEST(gray_image_8_threads)
    TEST(gray_image_16_threads)
    TEST(reduce_blue_4_threads_image)
    TEST(reduce_color_4_threads_image)

	TEST(reduce_color_to_8_1_threads_image)
	TEST(reduce_color_to_8_1_threads_image)
    TEST(sharpen_image_1_threads_image_3X3)
    TEST(sharpen_image_2_threads_image_3X3)
    TEST(sharpen_image_4_threads_image_3X3)
    TEST(blur_image_1_threads_image_3X3)
    TEST(blur_image_2_threads_image_3X3)
    TEST(blur_image_4_threads_image_3X3)
    TEST(blur_image_1_threads_image_5X5)
    TEST(blur_image_2_threads_image_5X5)
    TEST(blur_image_4_threads_image_5X5)
    TEST(median_image_1_threads_image_3X3)
    TEST(median_image_2_threads_image_3X3)
    TEST(median_image_4_threads_image_3X3)
    TEST(median_image_1_threads_image_5X5)
    TEST(median_image_2_threads_image_5X5)
    TEST(median_image_4_threads_image_5X5)




END_SUITE
