#ifndef POINT_HPP_
#define POINT_HPP_

namespace advcpp {

struct Point {
    explicit Point();                                                           
    explicit Point(int a_x, int a_y); 
    Point(const Point &a_other)= default;                                     
    Point& operator=(const Point &a_other) = default;                             
    ~Point() = default;

    int m_x;
    int m_y;
};

inline Point::Point() 
 : m_x(0)
 , m_y(0)
 {}

 inline Point::Point(int a_x, int a_y)
 : m_x(a_x)
 , m_y(a_y)
 {}

}//advcpp

#endif /*POINT_HPP_*/