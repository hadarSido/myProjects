#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace arkanoid
{

class Ui {
public:
    Ui() = default;
    ~Ui() = default;
    Ui(const Ui &a_other) = default;
    Ui &operator=(const Ui &a_other) = delete;

    void drawPoints(sf::RenderTarget& a_target, size_t a_points) const;
    void drawLifes(sf::RenderTarget& a_target, size_t a_lifes) const;
    void drawLevelNum(sf::RenderTarget& a_target, size_t a_level) const;
    void drawGameOver(sf::RenderTarget& a_target) const;
    void drawGameName(sf::RenderTarget& a_target) const;
    void drawTop10Titles(sf::RenderTarget& a_target) const;
    void drawWining(sf::RenderTarget& a_target) const;
    std::string getUserName();

    static constexpr float NAME_SCREEN_SIZE_X = 500;
    static constexpr float NAME_SCREEN_SIZE_Y = 300;
    static constexpr size_t FONT_SIZE_NAME = 24;
    const sf::Color AZURE_SCREEN = sf::Color(85,185, 220);
    static constexpr float TEXT_POS_X = 50;
    static constexpr float TEXT_POS_Y = 50;
    static constexpr float INPUT_POS_X = 50;
    static constexpr float INPUT_POS_Y = 100;

    static constexpr size_t FONT_SIZE_HELLO = 24;
    static constexpr size_t FONT_SIZE_DATA = 24;

    static constexpr size_t FONT_SIZE_FINAL_POINTS = 80;
    static constexpr size_t FONT_SIZE_GAME_OVER = 150;

    static constexpr float HELLO_POS_X = 680;
    static constexpr float HELLO_POS_Y = 10;
    static constexpr float POINTS_POS_X = 1350;
    static constexpr float POINTS_POS_Y = 10;

    static constexpr float LEVEL_POS_X = 640;
    static constexpr float LEVEL_POS_Y = 10;

    static constexpr float LIFE_POS_X = 1350;
    static constexpr float LIFE_POS_Y = 36;
    static constexpr float GAME_OVER_POS_X = 400;
    static constexpr float GAME_OVER_POS_Y = 300;
    static constexpr float FINAL_SCORE_POS_X = 500;
    static constexpr float FINAL_SCORE_POS_Y = 200;

};

} // arkanoid
