#include <SFML/Audio.hpp> // music
#include <iostream>
#include "main_screen.hpp"
#include "ui.hpp"
#include "music.hpp"
#include "icon.hpp"

namespace arkanoid
{

MainScreen::MainScreen()
: m_window(sf::VideoMode(MainScreen::SCREEN_SIZE_X, MainScreen::SCREEN_SIZE_Y),"Main Screen")
, m_quitButton(sf::Color(153, 0, 255), QUIT_BUTTON_SET_POS_X, QUIT_BUTTON_SET_POS_Y ,"Quit")
, m_gameButton(sf::Color(0, 153, 0), GAME_BUTTON_SET_POS_X, GAME_BUTTON_SET_POS_Y ,"Play")
, m_isNextWindow(false)
{}

bool MainScreen::isNextWindow() const
{
    return m_isNextWindow;
}

void MainScreen::run()
{
    Ui ui{};
    Icon sound{"../../icons/volume.png"};
    Icon mute{"../../icons/mute.png"};
    Music music ("../../music/main_music.wav");
    music.play();
    float exitPosXBegin = QUIT_BUTTON_SET_POS_X;
    float exitPosXEnd = QUIT_BUTTON_SET_POS_X + Button::BUTTON_SIZE_X;
    float exitPosYBegin = QUIT_BUTTON_SET_POS_Y;
    float exitPosYEnd = QUIT_BUTTON_SET_POS_Y + Button::BUTTON_SIZE_Y;
    float gamePosXBegin = GAME_BUTTON_SET_POS_X;
    float gamePosXEnd = GAME_BUTTON_SET_POS_X + Button::BUTTON_SIZE_X;
    float gamePosYBegin = GAME_BUTTON_SET_POS_Y;
    float gamePosYEnd = GAME_BUTTON_SET_POS_Y + Button::BUTTON_SIZE_Y;
    m_isNextWindow = false;
    bool stopMusic = false;
    bool isQPressed = false;
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(m_window).x >= exitPosXBegin && sf::Mouse::getPosition(m_window).x <= exitPosXEnd && sf::Mouse::getPosition(m_window).y >= exitPosYBegin && sf::Mouse::getPosition(m_window).y <= exitPosYEnd)
            {
                m_window.close();
            }
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                if (!isQPressed) {
                    stopMusic = !stopMusic;
                    isQPressed = true;
                }
            } 
            else {
                isQPressed = false;
            }
        
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(m_window).x >= gamePosXBegin && sf::Mouse::getPosition(m_window).x <= gamePosXEnd && sf::Mouse::getPosition(m_window).y >= gamePosYBegin && sf::Mouse::getPosition(m_window).y <= gamePosYEnd)
            {
                m_isNextWindow = true ;
            }
        }
        if(m_isNextWindow) {
            music.stop();
            break;
        }
        if(stopMusic) {
            music.stop();
        }
        if(!stopMusic && isQPressed) {
            music.setMusic("../../music/main_music.wav");
            music.play();
        }
        m_window.clear(AZURE);
        ui.drawGameName(m_window);
        m_quitButton.draw(m_window);
        m_gameButton.draw(m_window);
        if(stopMusic){
            mute.draw(m_window);
        }
        else {
            sound.draw(m_window);
        }
        m_window.display();
    }
}

} // arkanoid