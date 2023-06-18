#pragma once
#include <SFML/Graphics.hpp>
#include "screen.hpp"
#include "button.hpp"

namespace arkanoid
{

class MainScreen final : public Screen {
public:
    MainScreen();
    ~MainScreen() override = default;
    MainScreen(const MainScreen &a_other) = default;
    MainScreen &operator=(const MainScreen &a_other) = default;


    bool isNextWindow() const;
    void run() override;
    
    static constexpr float SCREEN_SIZE_X = 1000;
    static constexpr float SCREEN_SIZE_Y = 700;
    const sf::Color AZURE = sf::Color(85,185, 220);

    static constexpr float QUIT_BUTTON_SET_POS_X = 500 - Button::BUTTON_SIZE_X/2;
    static constexpr float QUIT_BUTTON_SET_POS_Y = 350 - Button::BUTTON_SIZE_Y/2;
    static constexpr float GAME_BUTTON_SET_POS_X = 500 - Button::BUTTON_SIZE_X/2;
    static constexpr float GAME_BUTTON_SET_POS_Y = 350 - Button::BUTTON_SIZE_Y - Button::BUTTON_SIZE_Y/2;
    
private:
    sf::RenderWindow m_window;
    Button m_quitButton;
    Button m_gameButton;
    bool m_isNextWindow;
};


} // arkanoid

