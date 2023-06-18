#include <string>
#include <sstream> //ostringstream
#include <iomanip> // setprecision
#include "winner.hpp"

namespace arkanoid
{

Winner::Winner(size_t a_points, std::string a_name, sf::Time a_time)
: m_points(a_points)
, m_name (a_name)
, m_time (a_time)
{}

std::string Winner::getName() const noexcept
{
    return m_name;
}

std::string Winner::getTimeStr() const noexcept
{
    std::ostringstream timeStream;
    timeStream << std::fixed << std::setprecision(3) << m_time.asSeconds();
    std::string timeString = timeStream.str();
    return timeString;
}


sf::Time Winner::getTime() const noexcept
{
    return m_time;
}

size_t Winner::getPointes() const noexcept
{
    return m_points;
}


void Winner::setName(std::string a_name)
{
    m_name = a_name;
}

void Winner::setTime(sf::Time a_time)
{
    m_time = a_time;
}

void Winner::setPoints(size_t a_points)
{
    m_points = a_points;
} 

bool Winner::operator>(const Winner& a_other) const {
    if (m_points != a_other.m_points) {
        return m_points > a_other.m_points;
    } 
    else {
        return m_time < a_other.m_time;
    }
}


} // arkanoid

