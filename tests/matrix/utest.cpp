#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstddef>
#include <climits>

#include "mu_test.h"
#include "matrix.hpp"
#include "color_image.hpp"

BEGIN_TEST(CreateMatrix)
	advcpp::Matrix<int> mat{4,3};
	ASSERT_EQUAL(mat.GetRows(), 4);
	ASSERT_EQUAL(mat.GetColumns(), 3);
	for(unsigned int i = 0; i < mat.GetRows(); ++i){
		for(unsigned int j = 0; j < mat.GetColumns(); ++j) {
			ASSERT_EQUAL(mat(i,j), 0);
		}	
	}
END_TEST

BEGIN_TEST(CopyOperator)
	advcpp::Matrix<int> mat1{4,3};
	advcpp::Matrix<int> mat2{5,2};
	mat2 = mat1;
	ASSERT_EQUAL(mat2.GetRows(), mat1.GetRows());
	ASSERT_EQUAL(mat2.GetColumns(), mat1.GetColumns());
	for(unsigned int i = 0; i < mat2.GetRows(); ++i){
		for(unsigned int j = 0; j < mat2.GetColumns(); ++j) {
			ASSERT_EQUAL(mat2(i,j), 0);
		}
	}
END_TEST

BEGIN_TEST(CopyConst)
	advcpp::Matrix<int> mat1{4,3};
	advcpp::Matrix<int> mat2{mat1};
	ASSERT_EQUAL(mat2.GetRows(), mat1.GetRows());
	ASSERT_EQUAL(mat2.GetColumns(), mat1.GetColumns());
	for(unsigned int i = 0; i < mat2.GetRows(); ++i){
		for(unsigned int j = 0; j < mat2.GetColumns(); ++j) {
			ASSERT_EQUAL(mat2(i,j), 0);
		}
	}
END_TEST


// BEGIN_TEST(IfValueExist)
// 	advcpp::Matrix<unsigned int> mat1{4,3};
// 	for(unsigned int i = 0; i < mat1.GetRows(); ++i){
// 		for(unsigned int j = 0; j < mat1.GetColumns(); ++j) {
// 			mat1.Member(i, j, i + j);
// 			ASSERT_EQUAL(mat1.at(i, j), i + j);
// 		}
// 	}
// END_TEST


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
	TEST(CreateMatrix)
	TEST(CopyOperator)
	TEST(CopyConst)
	//TEST(IfValueExist)
	TEST(CreateColorRGBDefult)
	TEST(CreateColorRGB)

END_SUITE
