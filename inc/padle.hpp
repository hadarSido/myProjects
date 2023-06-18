#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid {
class Padle {
public:                                                            
    explicit Padle(float a_xVelocity);  
    ~Padle() = default;
    Padle(const Padle &a_other) = delete;                                      
    Padle& operator=(const Padle &a_other) = delete; 

    void move(float a_xMove, float a_yMove); 
    void draw(sf::RenderTarget& a_target) const;
    float positionX() const noexcept;
    float positionY() const noexcept;
    void setPos();

    static constexpr float PADLE_SIZE_X = 150;
    static constexpr float PADLE_SIZE_Y = 15;
    static constexpr float PADLE_FIRST_POS_X = 50;
    static constexpr float PADLE_FIRST_POS_Y = 50;
    static constexpr float PADLE_SET_POS_X = 650;
    static constexpr float PADLE_SET_POS_Y = 700;
    static constexpr float PADLE_OUT_LINE_THICK = 2;
    const sf::Color BROWN;
  
private:
    sf::RectangleShape m_padle;
    float m_xVelocity;
    float m_yVelocity;

};

const sf::Color BROWN = sf::Color(102, 51, 0);
}//arkanoid

