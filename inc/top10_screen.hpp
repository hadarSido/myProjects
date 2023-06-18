#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "player.hpp"
#include "screen.hpp"
#include "winner.hpp"
namespace arkanoid
{

class Top10Screen final : public Screen {
public:
    Top10Screen(Winner a_winner);
    ~Top10Screen() override = default;
    Top10Screen(const Top10Screen &a_other) = default;
    Top10Screen &operator=(const Top10Screen &a_other) = default;

    void run();
    void drawTopTen(sf::RenderTarget& a_target) const;
    bool isMainWindow() const;
    void enterWinnerToTable();
    void saveToFile() const;

    static constexpr float SCREEN_SIZE_X = 1000;
    static constexpr float SCREEN_SIZE_Y = 700;
    const sf::Color AZURE = sf::Color(85,185, 220);


private:
    sf::RenderWindow m_window;
    std::vector<Winner> m_top10;
    bool m_isMainWindow;
    Winner m_winner;
    

};

} // arkanoid

