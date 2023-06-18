#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid {
class Brick {
public:           
    enum Colors {
        PINK,
        WHITE,
        AZURE,
        SALMON,
        ORENGE,
        GRAY,
        RED,
        BLUE,
        GREEN,
        YELLOW,
        AZURE_SCREEN,
        BLACK
    };

    std::map<Brick::Colors, std::pair<size_t, sf::Color>> bricksColorAndPoints {
        {Colors::PINK, {110, sf::Color(204, 102, 255)}},
        {Colors::WHITE, {50, sf::Color(255, 255, 255)}},
        {Colors::AZURE, {70, sf::Color(102, 255, 255)}},
        {Colors::SALMON, {60, sf::Color(255, 153, 153)}},
        {Colors::ORENGE, {120, sf::Color(255, 153, 0)}},
        {Colors::GRAY, {50, sf::Color(192, 192, 192)}},
        {Colors::RED, {90, sf::Color(165, 0, 33)}},
        {Colors::BLUE, {100, sf::Color(0, 51, 204)}},
        {Colors::GREEN, {80, sf::Color(0, 153, 0)}},
        {Colors::YELLOW, {0, sf::Color(209, 204, 0)}},
        {Colors::AZURE_SCREEN, {0,sf::Color(85,185, 220)}},
        {Colors::BLACK, {0,sf::Color(0,0, 0)}}
    };                                                   

    explicit Brick(float a_xPos, float a_yPos, Colors a_lineColor, Colors a_color);
    ~Brick() = default;
    Brick(const Brick &a_other) = default;                                      
    Brick& operator=(const Brick &a_other) = default; 

    void draw(sf::RenderTarget& a_target) const;
    float getPosX();
    float getPosY();
    size_t getPoints();
    sf::Color getColor();

    static constexpr float BRICK_OUT_LINE_THICK = 2;
    static constexpr float BRICK_SIZE_X = 80;
    static constexpr float BRICK_SIZE_Y = 30;
    static constexpr float BRICK_POS_X = 50;
    static constexpr float BRICK_POS_Y = 50;



private:
    float m_xPos;
    float m_yPos;
    sf::Color m_fillColor;
    sf::Color m_lineColor;
    sf::RectangleShape m_brick;
    size_t m_points;
    

};

}//arkanoid

