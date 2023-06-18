#pragma once
#include "padle.hpp"

namespace arkanoid {

class Player {
public:                                                            
    Player();  
    ~Player() = default;
    Player(const Player &a_other) = delete;                                      
    Player& operator=(const Player &a_other) = delete; 

    void draw(sf::RenderTarget& a_target) const;
    void move(float a_xMove, float a_yMove);
    float positionX() const noexcept;
    float positionY() const noexcept;
    void raisePoints(size_t a_pointsToRaise, sf::Color a_color, size_t a_level);
    void reduceLife();
    size_t getLife() const noexcept;
    size_t getPointes() const noexcept;
    void setPadelPos();
    void setTime(sf::Time a_time);
    sf::Time getTime() const noexcept;

    static constexpr float PADLE_VELOCITY_X = 3;
    static constexpr size_t PLAYER_LIFE_SIZE_Y = 3;
    static constexpr size_t PADLE_FIRST_POINTES = 0;
  
private:
    Padle m_padle;
    size_t m_points;
    size_t m_life;
    sf::Time m_time;

};

}//arkanoid

