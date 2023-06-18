#include "mu_test.h"
#include "matrix.hpp"
#include "color_image.hpp"
#include "point.hpp"
#include "draw_primitives.hpp"

// BEGIN_TEST(LoadSaveDraw)
// 	// advcpp::ColorImage newImage = advcpp::LoadImageFromFile("cat.ppm");
// 	// advcpp::SaveToFile("my_cat.ppm", newImage);
// 	// advcpp::DrawLine(newImage, advcpp::Point{15, 10}, advcpp::Point{1000, 1000}, advcpp::ColorRGB{200, 0, 0});
// 	// advcpp::DrawLine(newImage, advcpp::Point{150, 100}, advcpp::Point{150, 150}, advcpp::ColorRGB{0, 200, 0});
// 	// advcpp::DrawCircle(newImage, advcpp::Point{400, 400}, 200, advcpp::ColorRGB{0, 0, 200});
// 	// // ASSERT_EQUAL(newImage, 255);
// 	// advcpp::SaveToFile("my_cat.ppm", newImage);

// END_TEST
// BEGIN_TEST(ifPixelColorOk)
// 	advcpp::ColorImage newImage = advcpp::LoadImageFromFile("cat.ppm");
// 	advcpp::Point center{5, 5};
// 	int radius = 2;
// 	advcpp::ColorRGB color{0, 0, 200};
// 	advcpp::DrawCircle(newImage, center, radius, color);
// 	ASSERT_EQUAL(newImage.ReadColor(5, 3), color);
// 	advcpp::SaveToFile("my_cat.ppm", newImage);
// END_TEST

BEGIN_TEST(DrawHorizontalLine)
    advcpp::ColorImage newImage{10, 10};

    int startX = 2;
    int endX = 7;
    int y = 5;
    advcpp::ColorRGB color{255, 0, 0};
    advcpp::ColorRGB whiteColor{255, 255, 255};
    advcpp::DrawLine(newImage, advcpp::Point{15, 10}, advcpp::Point{1000, 1000}, color);
    // for (int x = startX; x <= endX; ++x) {
    //     ASSERT_EQUAL(newImage.ReadColor(y, x), color);
    // }
    for (int x = 0; x < startX; ++x) {
        ASSERT_EQUAL(newImage.ReadColor(y, x), whiteColor);
    }
    // for (int x = endX + 1; x < static_cast<int>(newImage.Width()); ++x) {
    //     ASSERT_EQUAL(newImage.ReadColor(y, x), whiteColor);
    // }
END_TEST



TEST_SUITE(因果応報 [inga ōhō:bad causes bring bad results])
	TEST(DrawHorizontalLine)

END_SUITE
