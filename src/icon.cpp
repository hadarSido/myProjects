#include <iostream> //cerr
#include "icon.hpp"

namespace arkanoid {
                                    
namespace {

}//namespace


Icon::Icon(std::string a_iconName) 
{
    sf::Image iconImage;
    iconImage.loadFromFile(a_iconName);

    m_iconTexture.loadFromImage(iconImage);
    m_iconSprite.setTexture(m_iconTexture);

    m_iconSprite.setScale(0.05f, 0.05f);
    m_iconSprite.setPosition(5.f, 5.f);}

void Icon::draw(sf::RenderWindow& a_window) const {
    a_window.draw(m_iconSprite);
}

  

}//arkanoid