#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstddef>
#include <climits>

#include "mu_test.h"
#include "matrix.hpp"
#include "color_image.hpp"


//ColorRgb
BEGIN_TEST(CreateColorRGBDefult)
	advcpp::ColorRGB colorPixel{};
	ASSERT_EQUAL(colorPixel.m_red, 255);
	ASSERT_EQUAL(colorPixel.m_blue, 255);
	ASSERT_EQUAL(colorPixel.m_green, 255);
	
END_TEST

BEGIN_TEST(CreateColorRGB)
	advcpp::ColorRGB colorPixel{15, 150, 250};
	ASSERT_EQUAL(colorPixel.m_red, 15);
	ASSERT_EQUAL(colorPixel.m_blue, 250);
	ASSERT_EQUAL(colorPixel.m_green, 150);
	
END_TEST



TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(CreateColorRGBDefult)
	TEST(CreateColorRGB)

END_SUITE
