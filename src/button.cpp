#include <iostream> //cerr
#include "button.hpp"

namespace arkanoid {
                                    
namespace {
sf::RectangleShape createQuitButton(sf::Color a_buttonColor, float a_bottonPosX, float a_bottonPosY)
{
    sf::RectangleShape button(sf::Vector2f(Button::BUTTON_SIZE_X, Button::BUTTON_SIZE_Y));
    sf::Vector2f padlePosition(Button::BUTTON_FIRST_POS_X, Button::BUTTON_FIRST_POS_Y);
    button.setPosition(a_bottonPosX, a_bottonPosY);
	button.setOutlineThickness(Button::BUTTON_OUT_LINE_THICK);
	button.setOutlineColor(sf::Color::Black);
	button.setFillColor(a_buttonColor);
    return button;
}
}//namespace


Button::Button(sf::Color a_buttonColor, float a_bottonPosX, float a_bottonPosY, std::string a_text) 
: m_button(createQuitButton(a_buttonColor, a_bottonPosX, a_bottonPosY))
, m_text(a_text)
, m_color(a_buttonColor)
, m_xPos(a_bottonPosX)
, m_yPos(a_bottonPosY)
{}

void Button::draw(sf::RenderTarget& a_target) const
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    sf::Text text(m_text, font, 26);
    text.setPosition(m_xPos + 75, m_yPos + 10);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    a_target.draw(m_button);
    a_target.draw(text);
}

  

}//arkanoid