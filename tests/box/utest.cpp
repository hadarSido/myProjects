#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstddef>
#include <cmath>
#include <vector>

struct Circle {
    sf::CircleShape m_circle;
    float m_xVelocity;
    float m_yVelocity;
};

Circle createCircle();

int main() 
{
	std::vector<Circle> ciclesSaver;
    sf::RenderWindow window(sf::VideoMode(1500, 800), "screen");
    while (window.isOpen()) {
		sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                ciclesSaver.push_back(createCircle());
            }
        }
        window.clear(sf::Color(85,185, 220));
        for(size_t i = 0; i < ciclesSaver.size(); ++i) {
            size_t j = 0;
            float distance = std::sqrt(std::pow(ciclesSaver[i].m_circle.getPosition().x - ciclesSaver[j].m_circle.getPosition().x, 2) + std::pow(ciclesSaver[i].m_circle.getPosition().y - ciclesSaver[j].m_circle.getPosition().y, 2));
            if(distance < ciclesSaver[i].m_circle.getRadius() + ciclesSaver[j].m_circle.getRadius()) {
                float tempXVelocity = ciclesSaver[i].m_xVelocity;
                float tempYVelocity = ciclesSaver[i].m_yVelocity;
                ciclesSaver[i].m_xVelocity = ciclesSaver[j].m_xVelocity;
                ciclesSaver[i].m_yVelocity = ciclesSaver[j].m_yVelocity;
                ciclesSaver[j].m_xVelocity = tempXVelocity;
                ciclesSaver[j].m_yVelocity = tempYVelocity;
                ++j;
            }
            ciclesSaver[i].m_circle.setPosition(ciclesSaver[i].m_circle.getPosition().x + ciclesSaver[i].m_xVelocity, ciclesSaver[i].m_circle.getPosition().y + ciclesSaver[i].m_yVelocity);
            if(ciclesSaver[i].m_circle.getPosition().x < 0 || ciclesSaver[i].m_circle.getPosition().x > 1500 -80) {
                ciclesSaver[i].m_xVelocity *= -1;
            }
            if(ciclesSaver[i].m_circle.getPosition().y < 0 || ciclesSaver[i].m_circle.getPosition().y > 800 -80) {
                ciclesSaver[i].m_yVelocity *= -1;
            }
            window.draw(ciclesSaver[i].m_circle);
        }
        window.display();
    }
    return 0;
}

Circle createCircle()
{
    Circle newCircle;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    float xPosition = static_cast<float>(rand() % (1500 - 50) + 10);
    float yPosition = static_cast<float>(rand() % (800 - 50) + 10);
    sf::CircleShape circle(20.f);
    circle.setPosition(xPosition, yPosition);
	circle.setOutlineThickness(2.f);
	circle.setOutlineColor(sf::Color(165, 0, 225));
	circle.setFillColor(sf::Color(225,155,215));
    newCircle.m_circle = circle;
    newCircle.m_xVelocity = 2;
    newCircle.m_yVelocity = 2;
    return newCircle;
}

