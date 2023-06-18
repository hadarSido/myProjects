#include <cmath>
#include "ball.hpp"

namespace arkanoid
{

namespace
{
    sf::CircleShape createBall()
    {
        sf::CircleShape circle(Ball::CIRCLE_RADIUS);
        sf::Vector2f circlePosition(Ball::CIRCLE_FIRST_POS_X, Ball::CIRCLE_FIRST_POS_Y);
        circle.setPosition(Ball::CIRCLE_SET_POS_X, Ball::CIRCLE_SET_POS_Y);
        circle.setOutlineThickness(Ball::CIRCLE_OUT_LINE_THICK);
        circle.setOutlineColor(PURPUL);
        circle.setFillColor(PINK);
        return circle;
    }
} // namespace

Ball::Ball(float a_xVelocity, float a_yVelocity)
: m_circle(createBall())
, m_xVelocity(a_xVelocity)
, m_yVelocity(a_yVelocity)
{}

void Ball::draw(sf::RenderTarget& a_target) const
{
    a_target.draw(m_circle);
}


void Ball::move(float a_xPadlePosition, float a_yPadlePosition)
{
    m_circle.setPosition(m_circle.getPosition().x + m_xVelocity, m_circle.getPosition().y -m_yVelocity );
    if (m_circle.getPosition().x < 0 || m_circle.getPosition().x > 1500 - 80)
    {
        m_xVelocity *= -1;
    }
    if (m_circle.getPosition().y < 0)
    {
        m_yVelocity *= -1;
    }
    if (m_circle.getPosition().x >= a_xPadlePosition && m_circle.getPosition().x <= a_xPadlePosition + 150 && m_circle.getPosition().y + 10 >= a_yPadlePosition && m_circle.getPosition().y <= a_yPadlePosition + 20)
    {
        m_yVelocity *= -1;
    }
}

void Ball::moveWithPadle(float a_xMove, float a_yMove, int a_halfPale)
{
    if (m_circle.getPosition().x + a_xMove >= 0 + a_halfPale && m_circle.getPosition().x + a_xMove <= 1500 - a_halfPale)
    {
        m_circle.move(a_xMove, a_yMove);
    }
}

float Ball::getPosX() const
{
    return m_circle.getPosition().x;
}

float Ball::getPosY() const
{
    return m_circle.getPosition().y;
}

float Ball::getVelocityX() const 
{
    return m_xVelocity;
}

float Ball::getVelocityY() const 
{
    return m_yVelocity;
}

void Ball::setVelocityY(float a_newVelocityY)
{
    m_yVelocity = a_newVelocityY;
}

void Ball::setVelocityX(float a_newVelocityX)
{
    m_xVelocity = a_newVelocityX;
}

void Ball::setPos(){
    m_circle.setPosition(CIRCLE_SET_POS_X, CIRCLE_SET_POS_Y);
}

} // arkanoid
