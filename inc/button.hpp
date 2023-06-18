#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid
{

class Button {
public:
    ~Button() = default;
    explicit Button(sf::Color a_buttonColor, float a_bottonPosX, float a_bottonPosY, std::string a_text);
    Button(const Button& a_other) = delete;
    Button& operator=(const Button &a_other) = delete;

    void draw(sf::RenderTarget& a_target) const; 

    static constexpr float BUTTON_SIZE_X = 200;
    static constexpr float BUTTON_SIZE_Y = 50;
    static constexpr float BUTTON_FIRST_POS_X = 50;
    static constexpr float BUTTON_FIRST_POS_Y = 50;
    static constexpr float BUTTON_OUT_LINE_THICK = 5;

private:
    sf::RectangleShape m_button;
    std::string m_text;
    sf::Color m_color;
    float m_xPos;
    float m_yPos;
};
//const sf::Color QUIT_PURPEL = sf::Color(153, 0, 255);
} // arkanoid




