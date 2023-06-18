#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid
{

class Winner {
public:
    Winner() = default;
    explicit Winner(size_t a_points, std::string a_name, sf::Time a_time);
    Winner(const Winner& a_other) = default;
    Winner& operator=(const Winner &a_other) = default; 
    ~Winner() = default;

    std::string getName() const noexcept;
    std::string getTimeStr() const noexcept;
    size_t getPointes() const noexcept;
    sf::Time getTime() const noexcept;

    void setName(std::string a_name);
    void setTime(sf::Time a_time);
    void setPoints(size_t a_points);

    //bool operator<(const Winner& a_other) const;
    bool operator>(const Winner& a_other) const;
    // bool operator<=(const Winner& a_other) const;
    // bool operator>=(const Winner& a_other) const;
    // bool operator==(const Winner& a_other) const;
    // friend std::ostream& operator<<(std::ostream& os, const Winner& winner);
    
private:
    size_t m_points;
    std::string m_name;
    sf::Time m_time;
    
};

} // arkanoid

