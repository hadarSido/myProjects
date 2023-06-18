#include <fstream>
#include <sstream>
#include <iostream>//cerr
#include <algorithm> // itr
#include <iterator>
#include "top10_screen.hpp"
#include "ui.hpp"
#include "music.hpp" // play music
#include "icon.hpp" 

namespace arkanoid {
namespace{
std::vector<Winner> readFromFile(){
    std::ifstream file("../../data/top_ten.txt");
    if (!file) {
        std::cerr << "Error opening file" << std::endl;
    }
    std::vector<Winner> winners;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream str(line);
        std::string name;
        size_t points;
        float time;
        str >> name >> points >> time;
        sf::Time sfTime = sf::seconds(time);
        winners.push_back(Winner(points, name, sfTime));
    }
    file.close();
    return winners;
}

} //namespace

Top10Screen::Top10Screen(Winner a_winner)
: m_window(sf::VideoMode(Top10Screen::SCREEN_SIZE_X, Top10Screen::SCREEN_SIZE_Y), "Top10 Screen")
, m_top10(readFromFile())
, m_isMainWindow(false)
, m_winner(a_winner)
{}

void Top10Screen::drawTopTen(sf::RenderTarget& a_target) const {
    sf::Font font;
    if (!font.loadFromFile("../../fonts/arial.ttf")) {
        std::cerr << "Error opening font" << std::endl;
    }
    float xPosName = 280;
    float xPosPoints = 420;
    float xPosTime = 520;
    float yPos = 200;
    Ui ui{};
    ui.drawTop10Titles(a_target);
    for(size_t i = 0; i < m_top10.size(); ++i) {
        std::string name = std::to_string(i + 1) + ") " + m_top10[i].getName();
        sf::Text textName(name, font, 24);
        textName.setPosition(xPosName, yPos);
        textName.setFillColor(sf::Color::Black);
        a_target.draw(textName);

        std::string pointes = std::to_string(m_top10[i].getPointes());
        sf::Text textPoints(pointes, font, 24);
        textPoints.setPosition(xPosPoints, yPos);
        textPoints.setFillColor(sf::Color::Black);
        a_target.draw(textPoints);
        
        std::string time = m_top10[i].getTimeStr();
        sf::Text textTime(time, font, 24);
        textTime.setPosition(xPosTime, yPos);
        textTime.setFillColor(sf::Color::Black);
        a_target.draw(textTime);
        yPos += 40;
    }
}

void Top10Screen::run()
{
    m_isMainWindow = false;
    bool isWinnerInTable = false;
    Music music("../../music/top10_music.wav");
    Icon sound{"../../icons/volume.png"};
    Icon mute{"../../icons/mute.png"};
    music.play();
    bool stopMusic = false;
    bool isQPressed = false;
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                if (!isQPressed) {
                    stopMusic = !stopMusic;
                    isQPressed = true;
                }
            } 
            else if (event.type == sf::Event::KeyPressed) {
                m_window.close();
            }
            else {
                isQPressed = false;
            }
        }
        if(m_isMainWindow) {
            music.stop();
            break;
        }
        if(stopMusic) {
            music.stop();
        }
        if(!stopMusic && isQPressed) {
            music.setMusic("../../music/top10_music.wav");
            music.play();
        }
        m_window.clear(AZURE);
        if(!isWinnerInTable) {
            enterWinnerToTable();
            isWinnerInTable = true;
        }
        saveToFile();
        drawTopTen(m_window);
        if(stopMusic){
            mute.draw(m_window);
        }
        else {
            sound.draw(m_window);
        }
        m_window.display();
    }
}

                                    
bool Top10Screen::isMainWindow() const
{
    return m_isMainWindow;
}

void Top10Screen::enterWinnerToTable() {
    size_t size = m_top10.size();
    for (size_t i = 0; i < size ; ++i) {
        if (m_winner > m_top10[i]) {
            m_top10.insert(m_top10.begin() + i, m_winner);
            break;
        }
    }
    if (m_top10.size() > 10) {
        m_top10.resize(10);
    }
}


void Top10Screen::saveToFile() const {
    std::ofstream file("../../data/top_ten.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
    }
    for (size_t i = 0; i < m_top10.size(); ++i) {
        file << m_top10[i].getName() << " " << m_top10[i].getPointes() << " " << m_top10[i].getTimeStr() << "\n";
    }
    file.close();
}

}//arkanoid







