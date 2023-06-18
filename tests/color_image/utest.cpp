#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstddef>
#include <climits>

#include "mu_test.h"
#include "matrix.hpp"
#include "color_image.hpp"


BEGIN_TEST(createImage)
	advcpp::ColorImage newImage{10,10};

	ASSERT_EQUAL(newImage.Height(), 10);
	ASSERT_EQUAL(newImage.Width(), 10);
	ASSERT_EQUAL(newImage.GetSturation(), 255);

	unsigned int rows = newImage.Height();
	unsigned int columns = newImage.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
            ASSERT_EQUAL(newImage.ReadColor(i,j).m_red, 255);
        }
    }
END_TEST

BEGIN_TEST(CopyImage)
	advcpp::ColorImage newImage1{10,10};
	advcpp::ColorImage newImage2 = newImage1;

	ASSERT_EQUAL(newImage2.Height(), 10);
	ASSERT_EQUAL(newImage2.Width(), 10);
	ASSERT_EQUAL(newImage2.GetSturation(), 255);

	unsigned int rows = newImage2.Height();
	unsigned int columns = newImage2.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
            ASSERT_EQUAL(newImage2.ReadColor(i, j).m_red, 255);
        }
    }
END_TEST

BEGIN_TEST(CopyAssiImage)
	advcpp::ColorImage newImage1{10,10};
	advcpp::ColorImage newImage2 {5,5};

	ASSERT_EQUAL(newImage2.Height(), 5);
	ASSERT_EQUAL(newImage2.Width(), 5);

	newImage2 = newImage1;
	ASSERT_EQUAL(newImage2.Height(), 10);
	ASSERT_EQUAL(newImage2.Width(), 10);
	ASSERT_EQUAL(newImage2.GetSturation(), 255);

	unsigned int rows = newImage2.Height();
	unsigned int columns = newImage2.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
            ASSERT_EQUAL(newImage2.ReadColor(i,j).m_red, 255);
        }
    }
END_TEST

BEGIN_TEST(ReadWriteImage)
	advcpp::ColorImage newImage{10,10,250};

	unsigned int rows = newImage.Height();
	unsigned int columns = newImage.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned  int j = 0; j < columns; ++j){
			newImage.WritePixToImage(advcpp::ColorRGB{i + j, i + j, i + j}, i, j);
			ASSERT_EQUAL(newImage.ReadColor(i, j).m_blue, i + j);
			ASSERT_EQUAL(newImage.ReadColor(i, j).m_green, i + j);
			ASSERT_EQUAL(newImage.ReadColor(i, j).m_red, i + j);
		}
	}
END_TEST


BEGIN_TEST(clearImage)
	advcpp::ColorImage newImage{10,10,250};
	newImage.Clear(advcpp::ColorRGB{0, 0, 0});

	unsigned int rows = newImage.Height();
	unsigned int columns = newImage.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_red, 0);
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_green, 0);
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_blue, 0);
		}
	}
END_TEST



TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(createImage)
	TEST(CopyImage)
	TEST(CopyAssiImage)
	TEST(ReadWriteImage)
	TEST(clearImage)
END_SUITE


/*$(CXX)=g++
$(CC)=$(CXX)

CFLAGS = -pedantic -Wall -Werror
CFLAGS += -g
CXXFLAGS = $(CFLAGS) -std=c++17

CPPFLAGS = -DDEBUG
CPPFLAGS = -I$(INCLUDES_DIR)

INCLUDES_DIR = ../../inc
SOURCES_DIR = ../../src


SOURCE := utest.cpp $(SOURCES_DIR)/color_image.cpp
TARGET := utest

all: $(TARGET)
$(TARGET) : $(SOURCE)

$(SOURCES_DIR)/color_image.cpp: $(INCLUDES_DIR)/color_image.hpp

$(SOURCES_DIR)/draw_primitives.cpp: $(INCLUDES_DIR)/draw_primitives.hpp

$(SOURCE) : $(INCLUDES_DIR)/inl/matrix.hxx $(INCLUDES_DIR)/matrix.hpp $(SOURCES_DIR)/draw_primitives.cpp $(SOURCES_DIR)/color_image.cpp

$(TARGET): $(SOURCES_DIR)/draw_primitives.cpp $(SOURCES_DIR)/color_image.cpp


check : $(TARGET) cat.ppm
	@./$(TARGET) -v

recheck: clean check

cat.ppm: img.zip
	unzip -o img.zip

clean:
	@$(RM) -f ./$(TARGET) *.o *.ppm


.PHONY : make clean check recheck all

make:
	@echo 'Attend a maker faire'
	@${TRUE}*/