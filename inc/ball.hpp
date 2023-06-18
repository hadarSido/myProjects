#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid {
    //static constexpr


class Ball {
public:                                                            
    explicit Ball(float a_xVelocity, float a_yVelocity);  
    ~Ball() = default;
    Ball(const Ball &a_other) = default;                                      
    Ball& operator=(const Ball &a_other) = delete;         

    void move (float a_xPadlePosition, float a_yPadlePosition);
    void draw(sf::RenderTarget& a_target) const;
    void moveWithPadle(float a_xMove, float a_yMove, int a_halfPale);
    
    float getPosX() const;
    float getPosY() const;
    float getVelocityX() const;
    float getVelocityY() const;
    void setVelocityY(float a_newVelocityY);
    void setVelocityX(float a_newVelocityX);
    void setPos();

    static constexpr float CIRCLE_RADIUS = 10;
    static constexpr float CIRCLE_FIRST_POS_X = 0;
    static constexpr float CIRCLE_FIRST_POS_Y = 0;
    static constexpr float CIRCLE_SET_POS_X = 710;
    static constexpr float CIRCLE_SET_POS_Y = 677;
    static constexpr float CIRCLE_OUT_LINE_THICK = 2;
    const sf::Color PURPUL;
    const sf::Color PINK;

private:
    sf::CircleShape m_circle;
    float m_xVelocity;
    float m_yVelocity;

};

const sf::Color PURPUL = sf::Color(165, 0, 225);
const sf::Color PINK = sf::Color(225, 155, 215);

}//arkanoid

