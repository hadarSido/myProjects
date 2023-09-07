#include <iostream>
#include <thread> // thread
#include <chrono> // sleep
#include <map> //string to int colors
#include <jsoncpp/json/json.h> //JSON files
#include <fstream> //files
#include <cmath> // atan2, sqrt, cos, sin
#include "game_screen.hpp"
#include "icon.hpp"


namespace arkanoid {
namespace {
std::map<std::string, Brick::Colors> stringToColor {
    {"PINK", Brick::Colors::PINK},
    {"WHITE", Brick::Colors::WHITE},
    {"AZURE", Brick::Colors::AZURE},
    {"SALMON", Brick::Colors::SALMON},
    {"ORENGE", Brick::Colors::ORENGE},
    {"GRAY", Brick::Colors::GRAY},
    {"RED", Brick::Colors::RED},
    {"BLUE", Brick::Colors::BLUE},
    {"GREEN", Brick::Colors::GREEN},
    {"YELLOW", Brick::Colors::YELLOW},
    {"AZURE_SCREEN", Brick::Colors::AZURE_SCREEN},
    {"BLACK", Brick::Colors::BLACK}
};
std::vector<Brick> readBricksFromFile(const std::string& a_fileName) {
    std::vector<Brick> brickSaver;
    std::ifstream file(a_fileName);
    if (file.is_open()) {
        Json::Value root;
        file >> root;
        const Json::Value bricks = root["bricks"];
        for (const auto& brickData : bricks) {
            float xPos = brickData["xPos"].asFloat();
            float yPos = brickData["yPos"].asFloat();
            Brick::Colors color1 = stringToColor[brickData["color1"].asString()];
            Brick::Colors color2 = stringToColor[brickData["color2"].asString()];
            Brick brick {xPos, yPos, color1, color2};
            brickSaver.push_back(brick);
        }
    }
    else {
        Brick brick {GameScreen::BRICK_POS_X_NEW, GameScreen::BRICK_POS_Y_NEW, Brick::Colors::AZURE_SCREEN, Brick::Colors::AZURE_SCREEN};
        brickSaver.push_back(brick);
    }
    return brickSaver;
}

size_t countUnbreakableBrick(std::vector<Brick> a_bricks) {
    size_t counter = 0;
    for(size_t i = 0; i < a_bricks.size(); ++i) {
        if(a_bricks[i].getPoints() == 0) {
            ++counter;
        }
    }
    return counter;
}
} // namespace


GameScreen::GameScreen()
: m_window(sf::VideoMode(GameScreen::SCREEN_SIZE_X, GameScreen::SCREEN_SIZE_Y), "Game Screen")
, m_player()
, m_ball(GameScreen::BALL_VELOCITY_X, GameScreen::BALL_VELOCITY_Y)
, m_levelNum(1)
, m_jsonFile("../../levels/level-" + std::to_string(m_levelNum) + ".json")
, m_bricks(readBricksFromFile(m_jsonFile))
, m_isNextWindow(false)
, m_isPrevWindow(false)
, m_isNextLevel(false)
, m_winner({})
, m_numOfBricks(countUnbreakableBrick(m_bricks))
{}

bool GameScreen::isNextWindow() const
{
    return m_isNextWindow;
}

bool GameScreen::isPrevWindow() const
{
    return m_isPrevWindow;
}

bool GameScreen::isBallMeetingBrick(Brick a_brick) {
    float ballPosX = m_ball.getPosX() + Ball::CIRCLE_RADIUS + Ball::CIRCLE_OUT_LINE_THICK;
    float ballPosY = m_ball.getPosY() + Ball::CIRCLE_RADIUS +  Ball::CIRCLE_OUT_LINE_THICK;
    float ballFirstPosX = m_ball.getPosX();
    float ballFirstPosY = m_ball.getPosY();
    float brickPosX = a_brick.getPosX();
    float brickPosY = a_brick.getPosY();
    float brickWidth = Brick::BRICK_SIZE_X +  Brick::BRICK_OUT_LINE_THICK ;
    float brickHeight = Brick::BRICK_SIZE_Y +  Brick::BRICK_OUT_LINE_THICK ;
    if (ballPosX >= brickPosX && ballPosX <= brickPosX + brickWidth &&
        ballPosY >= brickPosY && ballPosY <= brickPosY + brickHeight) {
        return true;
    }
    if(ballFirstPosX >= brickPosX && ballFirstPosX <= brickPosX + brickWidth &&
       ballFirstPosY >= brickPosY && ballFirstPosY <= brickPosY + brickHeight) {
        return true;
    }

    return false;
}
void GameScreen::breakBrick() 
{
    for(size_t i = 0; i < m_bricks.size(); ++i) {
        if(isBallMeetingBrick(m_bricks[i])) {
            if(m_bricks[i].getPoints() == 0) {
                changeVelocity(m_bricks[i]);
            }
            else {
                m_player.raisePoints(m_bricks[i].getPoints(), m_bricks[i].getColor(), m_levelNum);
                m_bricks.erase(m_bricks.begin() + i);                                                                                                                                   
                Brick brick {BRICK_POS_X_NEW, BRICK_POS_Y_NEW, Brick::Colors::AZURE_SCREEN, Brick::Colors::AZURE_SCREEN};
                m_bricks.insert(m_bricks.begin() + i, brick);
                changeVelocity(m_bricks[i]);
                ++m_numOfBricks;
            }
        }
    }
}
void GameScreen::changeVelocity(Brick a_brick){
    float ballCenterX = m_ball.getPosX() + Ball::CIRCLE_RADIUS;
    float ballCenterY = m_ball.getPosY() + Ball::CIRCLE_RADIUS;
    float brickCenterX = (a_brick.getPosX() + Brick::BRICK_SIZE_X) / 2.0f;
    float brickCenterY = (a_brick.getPosY() + Brick::BRICK_SIZE_Y) / 2.0f;
    float angle = std::atan2(ballCenterY - brickCenterY, ballCenterX - brickCenterX);
    float newVelocityX = 1.5 * BALL_VELOCITY_Y * (1 - angle);
    float newVelocityY = 1.5 * BALL_VELOCITY_Y * angle;
    if(m_ball.getVelocityY() < 0) {
        m_ball.setVelocityY(newVelocityY);
    }
    else {
        m_ball.setVelocityY(-newVelocityY);
    }

    if(m_ball.getVelocityX() < 0) {
        m_ball.setVelocityX(-newVelocityX);
    }
    else {
        m_ball.setVelocityX(newVelocityX);
        if(m_ball.getVelocityX() >= 0 && m_ball.getVelocityX() < 0.5) {
            m_ball.setVelocityX(1);
        }
    }
}

void GameScreen::run() 
{
    Ui ui{};
    
    Music music("../../music/level" + std::to_string(m_levelNum) + ".wav");
    music.play();
    Music musicBall;
    sf::Clock clock;
    m_isPrevWindow  = false;
    bool moveBall = false;
    bool stopMusic = false;
    bool isQPressed = false;
    while(m_window.isOpen()) {
		m_isNextLevel = false;
        m_isNextWindow = false;
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || m_player.getLife() == 0) {
                m_isPrevWindow = true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                moveBall = true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                if (!isQPressed) {
                    stopMusic = !stopMusic;
                    isQPressed = true;
                }
            } 
            else {
                isQPressed = false;
            }
            
            if (m_numOfBricks == m_bricks.size() && m_player.getLife() >= 0 && m_levelNum < 3) {
                m_isNextLevel = true;
            }
            if (m_numOfBricks == m_bricks.size() && m_player.getLife() >= 0 && m_levelNum == 3) {
                m_isNextWindow = true;
            }
        }
        if(m_isPrevWindow || m_isNextWindow) {
            music.stop();
            break;            
        }
        if(stopMusic) {
            music.stop();            
        }
        if(!stopMusic && isQPressed) {
            music.setMusic("../../music/level" + std::to_string(m_levelNum) + ".wav");
            music.play();
        }
        if(moveBall) {
            m_ball.move(m_player.positionX(), m_player.positionY());
            breakBrick();
            movePadle();
            if(m_ball.getPosY() >= 1000 && m_player.getLife() > 0) { 
                moveBall = false;
                lostBall();
                continue;
            }
        }
        else {
            movePadleWithBall();
        }
        if(m_player.getLife() == 0) {
            moveBall = false;
            music.stop();
            finishGameWithLost(ui);
            break;
        }
        if(m_isNextLevel && m_numOfBricks == m_bricks.size() && m_levelNum < 3) {
            moveBall = false;
            goToNextLevel();
            music.setMusic("../../music/level" + std::to_string(m_levelNum) + ".wav");
            music.play();
            continue;
        }
        if(m_numOfBricks == m_bricks.size() && m_levelNum == 3 && m_isNextWindow) {
            moveBall = false;
            music.stop();
            finishGameWithWin(ui, clock);
            break;
        }
        else {
            drawGameScreen(ui, stopMusic);
        }
   }
}

void GameScreen::goToNextLevel() {
    m_ball.setPos();
    m_player.setPadelPos();
    ++m_levelNum;
    m_jsonFile = "../../levels/level-" + std::to_string(m_levelNum) + ".json";
    m_bricks = readBricksFromFile(m_jsonFile);
    m_numOfBricks = countUnbreakableBrick(m_bricks);
    
}

void GameScreen::lostBall() {
    m_player.reduceLife();
    m_ball.setPos();
    m_player.setPadelPos();
}


void GameScreen::movePadleWithBall() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
        m_player.move(-5, 0);
        m_ball.moveWithPadle(-5, 0 ,75); 
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_player.move(5, 0);
        m_ball.moveWithPadle(5, 0 ,75); 
    }
}

void GameScreen::movePadle() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
        m_player.move(-5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_player.move(5, 0);
    }
}


void GameScreen::finishGameWithLost(Ui& a_ui) {
    m_window.clear(AZURE);
    a_ui.drawGameOver(m_window);
    m_window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void GameScreen::finishGameWithWin(Ui& a_ui, sf::Clock a_clock){
    m_window.clear(AZURE);
    a_ui.drawWining(m_window);
    m_window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    sf::Time elapsedTime = a_clock.getElapsedTime();
    m_player.setTime(elapsedTime);
    std::string name = a_ui.getUserName();
    setWinnerData(name);
}


void GameScreen::drawGameScreen(Ui& a_ui, bool a_flag) {
    Icon sound{"../../icons/volume.png"};
    Icon mute{"../../icons/mute.png"};
    m_window.clear(AZURE);
    m_ball.draw(m_window);
    m_player.draw(m_window);
    a_ui.drawPoints(m_window, m_player.getPointes());
    a_ui.drawLifes(m_window, m_player.getLife());
    a_ui.drawLevelNum(m_window, m_levelNum);
    for(size_t i = 0; i < m_bricks.size(); ++i) {
        Brick brick = m_bricks[i];
        brick.draw(m_window);
    }
    if(a_flag){
        mute.draw(m_window);
    }
    else {
        sound.draw(m_window);
    }
    m_window.display();
}

void GameScreen::setWinnerData(std::string a_name) {
    Winner winner{m_player.getPointes(), a_name, m_player.getTime()};
    m_winner = winner;
}

Winner GameScreen::getWinner() {
    return m_winner;
}

std::vector<Brick> GameScreen::getBricks() {
    return m_bricks;
}

Ball GameScreen::getBall() {
    return m_ball;
}



  

}//arkanoid