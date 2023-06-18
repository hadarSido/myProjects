#include <string>
#include "game.hpp"
#include "main_screen.hpp"
#include "game_screen.hpp"

namespace arkanoid {

Game::Game(Screen& a_screen)
: m_window(a_screen)
, m_winner({})
{}

void Game::run() 
{
    m_window.run();
}
   
}//arkanoid
