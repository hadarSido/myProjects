#include "color_image.hpp"
// #include <ostream>
//#include <iostream>
#include <cassert>
#include <fstream> //file functions
// #include <cmath> //pow 

namespace advcpp {

ColorImage::ColorImage(unsigned int a_row, unsigned int a_coloum, unsigned int a_sturation)
: m_sturation(a_sturation)
, m_matrixImage(Matrix<ColorRGB>{a_row, a_coloum}) 
{}

ColorImage::ColorImage(const ColorImage &a_other)
: m_sturation(a_other.m_sturation)                                 
, m_matrixImage(a_other.m_matrixImage)
{}

ColorImage& ColorImage::operator=(const ColorImage &a_other) {
    if (this != &a_other) {
        m_sturation = a_other.m_sturation;
        m_matrixImage = a_other.m_matrixImage;
    }
    return *this;
}

ColorRGB const& ColorImage::ReadColor(unsigned int a_row, unsigned int a_coloum) const{
    return this->m_matrixImage(a_row, a_coloum);
}

ColorRGB& ColorImage::ReadColor(unsigned int a_row, unsigned int a_coloum){
    return this->m_matrixImage(a_row, a_coloum);
}


ColorRGB ColorImage::ReadPixFromImage(unsigned int a_row, unsigned int a_coloum)  const {
    return m_matrixImage(a_row, a_coloum);
}


ColorImage LoadImageFromFile(std::string const& a_fileName) {
    std::ifstream reader(a_fileName);
    reader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    std::string format;
    reader >> format;
    assert(format == "P3");
    unsigned int height, width;
    unsigned int range;
    reader >> width;
    reader >> height;
    reader >> range;
    assert(range >=0 && range <=255);
    ColorImage image{width ,height, range};
    for(unsigned int i = 0; i < width; ++i) {
        for(unsigned int j = 0; j < height; ++j) {
            unsigned int r,g,b;
            reader >> r;
            reader >> g;
            reader >> b;
            image.WritePixToImage(ColorRGB(r,g,b),i,j);
        }
    }
    return image;
}

void SaveToFile(std::string a_fileName, ColorImage const& a_image) {
    std::ofstream writer(a_fileName);
    writer.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    writer << "P3" << "\n";
    writer << a_image.Width() << " " << a_image.Height() <<"\n";
    writer << a_image.GetSturation() << "\n";
    for(unsigned int i = 0; i < a_image.Width(); ++i) {
        for(unsigned int j = 0; j < a_image.Height(); ++j) {
            writer << a_image.ReadPixFromImage(i, j).m_red << " " << a_image.ReadPixFromImage(i, j).m_green << " " << a_image.ReadPixFromImage(i,j).m_blue << " ";
        }
        writer <<"\n";
    }
}

void ColorImage::WritePixToImage(ColorRGB const& a_pixel, unsigned int a_row, unsigned int a_coloum) {
    this->m_matrixImage(a_row, a_coloum) = a_pixel;
}

unsigned int ColorImage::Width() const {
    return m_matrixImage.GetColumns();
}

unsigned int ColorImage::Height() const {
    return m_matrixImage.GetRows();
}


unsigned int ColorImage::GetSturation() const {
    return this->m_sturation;
}

void ColorImage::Clear(ColorRGB const& a_backgroundColor){
    for (unsigned int i = 0; i < this->m_matrixImage.GetRows(); ++i) {
        for (unsigned int j = 0; j < this->m_matrixImage.GetColumns(); ++j) {
	        this->m_matrixImage(i, j) = a_backgroundColor;
        }
    }
}


}//advcpp