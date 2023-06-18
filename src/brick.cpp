#include "brick.hpp"

namespace arkanoid {

namespace {
sf::RectangleShape createBrick(float a_xPos, float a_yPos, sf::Color a_fillColor, sf::Color a_lineColor)
{
    sf::RectangleShape brick(sf::Vector2f(Brick::BRICK_SIZE_X, Brick::BRICK_SIZE_Y));
    sf::Vector2f brickPosition(Brick::BRICK_POS_X, Brick::BRICK_POS_Y);
    brick.setPosition(a_xPos, a_yPos);
	brick.setOutlineThickness(Brick::BRICK_OUT_LINE_THICK);
	brick.setOutlineColor(a_lineColor);
	brick.setFillColor(a_fillColor);
    return brick;
}
}//namespace

Brick::Brick(float a_xPos, float a_yPos, Brick::Colors a_lineColor, Brick::Colors a_color)
: m_xPos(a_xPos)
, m_yPos(a_yPos)
, m_fillColor(Brick::bricksColorAndPoints[a_color].second)
, m_lineColor(Brick::bricksColorAndPoints[a_lineColor].second)
, m_brick(createBrick(m_xPos, m_yPos, m_fillColor, m_lineColor))
, m_points(Brick::bricksColorAndPoints[a_color].first)
{}


void Brick::draw(sf::RenderTarget& a_target) const
{
    a_target.draw(m_brick);
}

float Brick::getPosX()
{
    return m_xPos;
}

float Brick::getPosY()
{
    return m_yPos;
}

size_t Brick::getPoints()
{
    return m_points;
}

sf::Color Brick::getColor()
{
    return m_fillColor;
}

}//arkanoid

