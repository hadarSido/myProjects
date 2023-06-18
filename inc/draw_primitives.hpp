#ifndef DROW_PRIMITIVES_HPP_
#define DROW_PRIMITIVES_HPP_
#include "color_image.hpp"
#include "point.hpp"
#include "colorrgb.hpp"

namespace advcpp {

void DrawLine(ColorImage& a_image, Point a_start , Point a_end, const ColorRGB& a_color);
void DrawCircle(ColorImage& a_image, Point a_center, unsigned int a_radius, const ColorRGB a_color);



}//advcpp

#endif /*DROW_PRIMITIVES_HPP_*/

