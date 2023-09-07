#include "mu_test.h"
#include "ball.hpp"
#include "padle.hpp"
#include "game_manager.hpp"
#include "player.hpp"
#include "ui.hpp"
#include "main_screen.hpp"
#include "game_screen.hpp"
#include "brick.hpp"
#include "game.hpp"
#include "button.hpp"
#include "winner.hpp"
#include "top10_screen.hpp"


/*
BEGIN_TEST(ball_data)
	arkanoid::Ball ball(0.5, 3);
	ASSERT_EQUAL(ball.getPosX(), 710);
	ASSERT_EQUAL(ball.getPosY(), 677);
	
END_TEST


BEGIN_TEST(padle_data)
	arkanoid::Padle padle(3);
	ASSERT_EQUAL(padle.positionX(), 650);
	ASSERT_EQUAL(padle.positionY(), 700);
	
END_TEST

BEGIN_TEST(player_data)
	arkanoid::Player player;
	ASSERT_EQUAL(player.getLife(), 3);
	ASSERT_EQUAL(player.getPointes(), 0);
	
END_TEST

BEGIN_TEST(brick_data)
	sf::Color red(165, 0, 33);
	arkanoid::Brick brick {80, 20, red, red};
	ASSERT_EQUAL(brick.getPosX(), 80);
	ASSERT_EQUAL(brick.getPosY(), 20);
	
END_TEST

BEGIN_TEST(move_the_ball)
	using namespace arkanoid;
    Ball ball(10.0f, 5.0f);

    ball.move(0, 0);
    ASSERT_EQUAL(ball.getPosX(), Ball::CIRCLE_SET_POS_X + 10.0f);
    ASSERT_EQUAL(ball.getPosY(), Ball::CIRCLE_SET_POS_Y - 5.0f);

END_TEST

BEGIN_TEST(set_ball_velocity)
	
	using namespace arkanoid;
	Ball ball(10.0f, 5.0f);

    ball.setVelocityX();
    ASSERT_EQUAL(ball.getPosX(), Ball::CIRCLE_SET_POS_X );
    ASSERT_EQUAL(ball.getPosY(), Ball::CIRCLE_SET_POS_Y);

    ball.setVelocityY();
    ASSERT_EQUAL(ball.getPosX(), Ball::CIRCLE_SET_POS_X);
    ASSERT_EQUAL(ball.getPosY(), Ball::CIRCLE_SET_POS_Y);

END_TEST

BEGIN_TEST(padle_set_position)
	
	using namespace arkanoid;
	Padle padle(5.f);
    ASSERT_EQUAL(padle.positionX(), Padle::PADLE_SET_POS_X);
    ASSERT_EQUAL(padle.positionY(), Padle::PADLE_SET_POS_Y);

END_TEST

BEGIN_TEST(padle_move)
	
	using namespace arkanoid;
	Padle padle(5.f);
    ASSERT_EQUAL(padle.positionX(), Padle::PADLE_SET_POS_X);
    ASSERT_EQUAL(padle.positionY(), Padle::PADLE_SET_POS_Y);

END_TEST

BEGIN_TEST(padle_set_position_again)
	
	using namespace arkanoid;
	Padle padle(5.f);
    padle.setPos();
    ASSERT_EQUAL(padle.positionX(), Padle::PADLE_SET_POS_X);
    ASSERT_EQUAL(padle.positionY(), Padle::PADLE_SET_POS_Y);

END_TEST

BEGIN_TEST(player_initilaz)
	
	using namespace arkanoid;
	Player player;
    ASSERT_EQUAL(player.getLife(), 3);
    ASSERT_EQUAL(player.getPointes(), 0);
    ASSERT_EQUAL(player.positionX(), 650.0f);
    ASSERT_EQUAL(player.positionY(), 700.0f);

END_TEST

BEGIN_TEST(player_move_padle)
	
	using namespace arkanoid;
	Player player;
    player.move(10.0f, -5.0f);
    ASSERT_EQUAL(player.positionX(), 660.0f);
    ASSERT_EQUAL(player.positionY(), 695.0f);

END_TEST


BEGIN_TEST(player_reduce_life_and_raise_points)
	
	using namespace arkanoid;
	Player player;
    player.raisePoints();
    player.raisePoints();
    player.raisePoints();
    ASSERT_EQUAL(player.getPointes(), 120);

    player.reduceLife();
    ASSERT_EQUAL(player.getLife(), 2);

    player.reduceLife();
    player.reduceLife();
    ASSERT_EQUAL(player.getLife(), 0);

END_TEST

BEGIN_TEST(brick_initliz)
	
	using namespace arkanoid;
	Brick brick(10.0f, 20.0f, sf::Color::Red, sf::Color::White);
    ASSERT_EQUAL(brick.getPosX(), 10.0f);
    ASSERT_EQUAL(brick.getPosY(), 20.0f);

END_TEST

BEGIN_TEST(brick_draw)
	
	using namespace arkanoid;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Brick Test Window");
    window.clear(sf::Color::Black);

    Brick brick(100.0f, 50.0f, sf::Color::Yellow, sf::Color::Green);
    brick.draw(window);

    window.display();

    sf::sleep(sf::seconds(1));
	ASSERT_PASS();

END_TEST

BEGIN_TEST(is_next_screen_returns_false_initially)
	
	using namespace arkanoid;
	GameScreen gameScreen;
    ASSERT_EQUAL(gameScreen.isNextWindow(), false);

END_TEST

BEGIN_TEST(is_prev_screen_returns_false_initially)
	
	using namespace arkanoid;
	GameScreen gameScreen;
    ASSERT_EQUAL(gameScreen.isPrevWindow(), false);

END_TEST

BEGIN_TEST(create_bricks)
	
	using namespace arkanoid;
	GameScreen gameScreen;
    ASSERT_EQUAL(gameScreen.getBricks().size(), GameScreen::NUM_OF_BRICKS);

END_TEST


BEGIN_TEST(break_bricks)
	
	using namespace arkanoid;
	GameScreen gameScreen;
    gameScreen.getBall().setPos();
    gameScreen.breakBrick();
    ASSERT_EQUAL(gameScreen.getBricks().size(), GameScreen::NUM_OF_BRICKS);

END_TEST

BEGIN_TEST(create_main_screen_next_false)
	
	using namespace arkanoid;
	MainScreen mainScreen;
    mainScreen.run();
    ASSERT_EQUAL(mainScreen.isNextWindow(), false);

END_TEST
*/



TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	/*TEST(ball_data)
	TEST(padle_data)
	TEST(player_data)
	TEST(brick_data)
	TEST(move_the_ball)
	TEST(set_ball_velocity)
	TEST(padle_set_position)
	TEST(padle_move)
	TEST(padle_set_position_again)
	TEST(player_initilaz)
	TEST(player_move_padle)
	TEST(player_reduce_life_and_raise_points)
	TEST(brick_initliz)
	TEST(brick_draw)
	TEST(is_next_screen_returns_false_initially)
	TEST(is_prev_screen_returns_false_initially)
	TEST(create_bricks)
	TEST(break_bricks)
	TEST(create_main_screen_next_false)*/

END_SUITE
