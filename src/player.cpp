#include "player.hpp"

namespace arkanoid {

Player::Player() 
: m_padle(PADLE_VELOCITY_X)
, m_points (PADLE_FIRST_POINTES)
, m_life (PLAYER_LIFE_SIZE_Y)
, m_time(sf::Time{})
{}

void Player::draw(sf::RenderTarget& a_target) const
{
    m_padle.draw(a_target);
}

void Player::move(float a_xMove, float a_yMove) 
{
    m_padle.move(a_xMove, a_yMove);
}

float Player::positionX() const noexcept
{
    return m_padle.positionX();
}

float Player::positionY() const noexcept
{
    return m_padle.positionY();
}

void Player::raisePoints(size_t a_pointsToRaise, sf::Color a_color, size_t a_level)
{
    if(a_color == sf::Color(192, 192, 192)) {
        m_points += a_pointsToRaise * a_level; 
    }
    else {
        m_points += a_pointsToRaise;
    }
    
}

void Player::reduceLife()
{
    --m_life;
}

size_t Player::getLife() const noexcept
{
    return m_life;
}

size_t Player::getPointes() const noexcept
{
    return m_points;
}

void Player::setPadelPos(){
    m_padle.setPos();
}

sf::Time Player::getTime() const noexcept
{
    return m_time;
}


void Player::setTime(sf::Time a_time) 
{
    m_time = a_time;
}


}//arkanoid

