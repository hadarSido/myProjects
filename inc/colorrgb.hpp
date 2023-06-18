#ifndef COLORRGB_H_
#define COLORRGB_H_

#include <ostream>

static const int RGB_DEFAULT = 255;

namespace advcpp {
struct ColorRGB {
    ColorRGB();                                                           
    explicit ColorRGB(unsigned int a_red, unsigned int a_green, unsigned int a_blue);

    unsigned int m_red;
    unsigned int m_green;
    unsigned int m_blue;
};

inline ColorRGB::ColorRGB() 
 : m_red(RGB_DEFAULT)
 , m_green(RGB_DEFAULT)
 , m_blue(RGB_DEFAULT) 
 {}


 inline ColorRGB::ColorRGB(unsigned int a_red, unsigned int a_green, unsigned int a_blue) 
 : m_red(a_red)
 , m_green(a_green)
 , m_blue(a_blue) 
 {}
 

inline bool operator==(const ColorRGB& a_first, const ColorRGB& a_sec) {
    return a_first.m_red == a_sec.m_red && a_first.m_green == a_sec.m_green && a_first.m_blue == a_sec.m_blue;
}

inline bool operator!=(const ColorRGB& a_first, const ColorRGB& a_sec) {
    return a_first.m_red != a_sec.m_red && a_first.m_green != a_sec.m_green && a_first.m_blue != a_sec.m_blue;
}

inline std::ostream& operator<<(std::ostream& a_os, const ColorRGB& a_color) {
    a_os << "(" << a_color.m_red << ", " << a_color.m_green << ", " << a_color.m_blue << ")";
    return a_os;
}

}//advcpp
#endif /*COLORRGB_H_*/

