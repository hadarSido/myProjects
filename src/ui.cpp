#include <iostream>
#include "ui.hpp"

namespace arkanoid {
                                                        
void Ui::drawPoints(sf::RenderTarget& a_target, size_t a_points) const
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    std::string pointes = "Points: "+ std::to_string(a_points);
    sf::Text text(pointes, font, FONT_SIZE_DATA);
    text.setPosition(POINTS_POS_X, POINTS_POS_Y);
    a_target.draw(text);
}

void Ui::drawLifes(sf::RenderTarget& a_target, size_t a_lifes) const
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    std::string lifes = "Lifes: " + std::to_string(a_lifes);
    sf::Text text(lifes, font, FONT_SIZE_DATA);
    text.setPosition(LIFE_POS_X, LIFE_POS_Y);
    a_target.draw(text);
}

void Ui::drawLevelNum(sf::RenderTarget& a_target, size_t a_level) const
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    std::string pointes = "Level number "+ std::to_string(a_level);
    sf::Text text(pointes, font, FONT_SIZE_DATA);
    text.setPosition(LEVEL_POS_X, LEVEL_POS_Y);
    a_target.draw(text);
}


void Ui::drawGameOver(sf::RenderTarget& a_target) const
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    std::string gameOver = "Game Over ";
    sf::Text text(gameOver, font, FONT_SIZE_GAME_OVER);
    text.setPosition(GAME_OVER_POS_X, GAME_OVER_POS_Y);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    a_target.draw(text);
}

void Ui::drawGameName(sf::RenderTarget& a_target) const
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/DOTFONT-.TTF")) {
        std::cerr << "Error opening font" << std::endl;
    }
    std::string win = "Arkanoid Game";
    sf::Text text(win, font, 90);
    text.setPosition(20, 80);
    text.setFillColor(sf::Color::Black);
    a_target.draw(text);
}

void Ui::drawTop10Titles(sf::RenderTarget& a_target) const 
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    float xPosPoints = 420;
    float yPos = 200;

    sf::Font font2;
    if (!font2.loadFromFile("../../fonts/DOTFONT-.TTF")) {
        std::cerr << "Error opening font" << std::endl;
    }
    std::string win = "Top 10";
    sf::Text text(win, font2, 90);
    text.setPosition(240, 10);
    text.setFillColor(sf::Color::Black);
    a_target.draw(text);

    sf::Text textNameTitle("Name", font, 24);
    textNameTitle.setPosition(300, yPos - 40);
    textNameTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textNameTitle.setFillColor(sf::Color::Black);

    sf::Text textPointsTitle("Points", font, 24);
    textPointsTitle.setPosition(xPosPoints -20, yPos - 40);
    textPointsTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textPointsTitle.setFillColor(sf::Color::Black);

    sf::Text textTimeTitle("Time(sec)", font, 24);
    textTimeTitle.setPosition(500, yPos - 40);
    textTimeTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textTimeTitle.setFillColor(sf::Color::Black);

    a_target.draw(textPointsTitle);
    a_target.draw(textNameTitle);
    a_target.draw(textTimeTitle);
}

void Ui::drawWining(sf::RenderTarget& a_target) const
{
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    std::string win = "You Won! ";
    sf::Text text(win, font, FONT_SIZE_GAME_OVER);
    text.setPosition(GAME_OVER_POS_X, GAME_OVER_POS_Y);
    text.setFillColor(sf::Color::Blue);
    a_target.draw(text);
}

std::string Ui::getUserName() {
    std::string username;
    sf::RenderWindow window(sf::VideoMode(NAME_SCREEN_SIZE_X, NAME_SCREEN_SIZE_Y), "Enter Username ");
    sf::Font font;
    font.loadFromFile("../../fonts/arial.ttf");

    sf::Text text("Enter username:", font, FONT_SIZE_NAME);
    text.setPosition(TEXT_POS_X, TEXT_POS_Y);

    sf::Text inputText("", font, FONT_SIZE_NAME);
    inputText.setPosition(INPUT_POS_X, INPUT_POS_Y);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == '\b' && !username.empty())
                {
                    username.pop_back();
                    inputText.setString(username);
                }
                else if (event.text.unicode == '\r')
                {
                    window.close();
                }
                else if (event.text.unicode < 128)
                {
                    username += static_cast<char>(event.text.unicode);
                    inputText.setString(username);
                }
            }
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear(AZURE_SCREEN);
        window.draw(text);
        window.draw(inputText);
        window.display();
    }
    return username;
}


}//arkanoid

