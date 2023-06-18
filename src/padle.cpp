#include "padle.hpp"

namespace arkanoid {

namespace {
sf::RectangleShape createPadle()
{
    sf::RectangleShape padle(sf::Vector2f(Padle::PADLE_SIZE_X, Padle::PADLE_SIZE_Y));
    sf::Vector2f padlePosition(Padle::PADLE_FIRST_POS_X, Padle::PADLE_FIRST_POS_Y);
    padle.setPosition(Padle::PADLE_SET_POS_X, Padle::PADLE_SET_POS_Y);
	padle.setOutlineThickness(Padle::PADLE_OUT_LINE_THICK);
	padle.setOutlineColor(BROWN);
	padle.setFillColor(BROWN);
    return padle;
}
}//namespace


Padle::Padle(float a_xVelocity) 
: m_padle(createPadle())
, m_xVelocity (a_xVelocity)
, m_yVelocity (0)
{}

void Padle::draw(sf::RenderTarget& a_target) const
{
    a_target.draw(m_padle);
}

void Padle::move(float a_xMove, float a_yMove) 
{
    if (m_padle.getPosition().x + a_xMove >= 0 && m_padle.getPosition().x + a_xMove <= 1500 - m_padle.getSize().x) {
        m_padle.move(a_xMove, a_yMove);
    }
}

float Padle::positionX() const noexcept
{
    return m_padle.getPosition().x;
}

float Padle::positionY() const noexcept
{
    return m_padle.getPosition().y;
}

void Padle::setPos(){
    m_padle.setPosition(Padle::PADLE_SET_POS_X, Padle::PADLE_SET_POS_Y);
}

}//arkanoid

