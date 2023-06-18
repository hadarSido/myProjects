#include "draw_primitives.hpp"

namespace advcpp {
void DrawHorizLine(ColorImage & a_image, ColorRGB a_color ,int a_y, int a_xStart, int a_xEnd);
void DrawVerticalLine(ColorImage& a_image ,ColorRGB a_color ,int a_x, int a_yStart, int a_yEnd);
static void IsPointInPictureForCicel(ColorImage& a_image, int a_x, int a_y, ColorRGB a_color);
static bool IsPointInPicture(ColorImage& a_image, int a_x, int a_y);

void DrawLine(ColorImage& a_image, Point a_start , Point a_end, const ColorRGB& a_color) {
    int xStart = a_start.m_x;
    int yStart = a_start.m_y;
    int xEnd = a_end.m_x;
    int yEnd = a_end.m_y;
    if (xStart > xEnd) {
        std::swap(yStart, yEnd);
        std::swap(xStart, xEnd);
    }
    if(xStart == xEnd) {
        DrawVerticalLine(a_image ,a_color , xStart , yStart , yEnd );
    }
    else if(yStart == yEnd) {
        DrawHorizLine(a_image, a_color ,yStart, xStart , xEnd);
    }
    else {
        int dy = yEnd - yStart;
        int dx = xEnd - xStart;
        int diff = 2 * dy - dx;
        int y = yStart;
        for(int i = xStart ; i < xEnd ; ++i) {
            if(IsPointInPicture(a_image, i, y)) {
                a_image.WritePixToImage(a_color, i, y);
                if(diff > 0){
                    y += 1;
                    diff -= 2 * dx;
                }
                else {
                    diff += 2 * dx;
                }
            }
        }
    }
}

void DrawCircle(ColorImage& a_image, Point a_center, unsigned int a_radius, const ColorRGB a_color) {  
    int xLocation = a_radius;
    int radiusError = 1 - xLocation;
    int row = a_center.m_x;
    int column = a_center.m_y;
    for(int yLocation = 0;  xLocation >= yLocation; ++yLocation) {
        IsPointInPictureForCicel(a_image, row + yLocation, column - xLocation, a_color);
        IsPointInPictureForCicel(a_image, row - yLocation, column - xLocation, a_color);
        IsPointInPictureForCicel(a_image, row + xLocation, column - yLocation, a_color);
        IsPointInPictureForCicel(a_image, row - xLocation, column - yLocation, a_color);
        IsPointInPictureForCicel(a_image, row + yLocation, column + xLocation, a_color);
        IsPointInPictureForCicel(a_image, row - yLocation, column + xLocation, a_color);
        IsPointInPictureForCicel(a_image, row + xLocation, column + yLocation, a_color);
        IsPointInPictureForCicel(a_image, row - xLocation, column + yLocation, a_color);
        if (radiusError < 0) {
            radiusError += 2 * yLocation + 1;
        }
        else {
            --xLocation;
            radiusError += 2 * (yLocation - xLocation) + 1;
        }
    }
}


void DrawVerticalLine(ColorImage& a_image ,ColorRGB a_color ,int a_x, int a_yStart, int a_yEnd) {
    for(int i = a_yStart;i <= a_yEnd; ++i) {
        a_image.WritePixToImage(a_color, i ,a_x);
    }
}

void DrawHorizLine(ColorImage & a_image, ColorRGB a_color ,int a_y, int a_xStart, int a_xEnd) {
    for(int i = a_xStart;i <= a_xEnd; ++i) {
        a_image.WritePixToImage(a_color, a_y, i);
    }
}

static bool IsPointInPicture(ColorImage& a_image, int a_x, int a_y) {
    if(a_x < 0 || a_y < 0) {
        return false;
    }
    return (a_x < static_cast<int>(a_image.Width()) && a_y < static_cast<int>(a_image.Height()));
}

static void IsPointInPictureForCicel(ColorImage& a_image, int a_x, int a_y, ColorRGB a_color) {
    if(IsPointInPicture(a_image, a_x, a_y)) {
        a_image.WritePixToImage(a_color, a_x, a_y);
    }
}


}//advcpp



