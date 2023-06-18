#pragma once
#include <SFML/Graphics.hpp>
#include "winner.hpp"
#include "screen.hpp"

namespace arkanoid {
class Game {
public:                                                            
    Game() = default;  
    explicit Game(Screen& a_screen);
    ~Game() = default;
    Game(const Game &a_other) = default;                                      
    Game& operator=(const Game &a_other) = delete;  

    void run();

    static constexpr size_t NUM_OF_BRIKS = 24;
    static constexpr size_t NUM_OF_LINES = 4;
    static constexpr float BRIK_FIRST_POS_X = 500;
    static constexpr float BRIK_FIRST_POS_Y = 200;
    static constexpr float BALL_VELOCITY_X = 0.5;
    static constexpr float BALL_VELOCITY_Y = 3;

    static constexpr float BRIK_POS_X_NEW = -10;
    static constexpr float BRIK_POS_Y_NEW = -10;

private:
    Screen& m_window;
    Winner m_winner;
};

}//arkanoid

