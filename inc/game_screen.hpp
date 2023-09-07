#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "player.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "screen.hpp"
#include "winner.hpp"
#include "ui.hpp"
#include "music.hpp" // play music


namespace arkanoid
{

class GameScreen final : public Screen {
public:
    GameScreen();
    ~GameScreen() override = default;
    GameScreen(const GameScreen &a_other) = default;
    GameScreen &operator=(const GameScreen &a_other) = default;

    bool isBallMeetingBrick(Brick a_brick);
    void breakBrick();
    bool isNextWindow() const;
    bool isPrevWindow() const;

    void run() override;
    void setWinnerData(std::string a_name);
    Winner getWinner();
    std::vector<Brick> getBricks();
    Ball getBall();
    void drawGameScreen(Ui& a_ui, bool a_flag);
    void finishGameWithWin(Ui& a_ui, sf::Clock a_clock);
    void finishGameWithLost(Ui& a_ui);
    void movePadleWithBall();
    void movePadle();
    void lostBall();
    void goToNextLevel();
    void changeVelocity(Brick a_brick);

    static constexpr size_t NUM_OF_BRICKS = 2;
    static constexpr size_t NUM_OF_LINES = 4;
    static constexpr float BRICK_FIRST_POS_X = 500;
    static constexpr float BRICK_FIRST_POS_Y = 200;
    static constexpr float BALL_VELOCITY_X = 2;
    static constexpr float BALL_VELOCITY_Y = 4;

    static constexpr float BRICK_POS_X_NEW = -100;
    static constexpr float BRICK_POS_Y_NEW = -100;

    static constexpr float SCREEN_SIZE_X = 1500;
    static constexpr float SCREEN_SIZE_Y = 800;
    const sf::Color AZURE = sf::Color(85,185, 220);
  

private:
    sf::RenderWindow m_window;
    Player m_player;
    Ball m_ball;
    size_t m_levelNum;
    std::string m_jsonFile;
    std::vector<Brick> m_bricks;
    bool m_isNextWindow;
    bool m_isPrevWindow;
    bool m_isNextLevel;
    Winner m_winner;
    size_t m_numOfBricks;
};

} // arkanoid

