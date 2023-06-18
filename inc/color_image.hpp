#ifndef COLOR_IMAGE_HPP_
#define COLOR_IMAGE_HPP_
#include "colorrgb.hpp"
#include "matrix.hpp"

namespace advcpp {

class ColorImage {
public:                                                           
    explicit ColorImage(unsigned int a_row, unsigned  int a_coloum, unsigned int a_sturation = 255); 
    ColorImage(const ColorImage &a_other);                                     
    ColorImage& operator=(const ColorImage &a_other);                             
    ~ColorImage() = default;

    ColorRGB const& ReadColor(unsigned  int a_row, unsigned int a_coloum) const;

    ColorRGB& ReadColor(unsigned int a_row, unsigned int a_coloum);

    void WritePixel(unsigned int a_row,  unsigned int a_coloum, const ColorRGB& a_color);

    void WritePixToImage(ColorRGB const& a_pixel, unsigned int a_row, unsigned int a_coloum);
    ColorRGB ReadPixFromImage(unsigned int a_row, unsigned int a_coloum)  const;

    void ReduceColorDepth( unsigned int a_factor);
    void ScaleDownSize(unsigned int a_factor);

    void Clear(ColorRGB const& a_backgroundColor);

    unsigned int GetSturation() const;
    unsigned int Width() const;
    unsigned int Height() const;

private:
    unsigned int m_sturation;
    Matrix<ColorRGB> m_matrixImage;
};

ColorImage LoadImageFromFile(std::string const& a_fileName);
void SaveToFile(std::string a_fileName, ColorImage const& a_image);

}//advcpp

#endif /*COLOR_IMAGE_HPP_*/

