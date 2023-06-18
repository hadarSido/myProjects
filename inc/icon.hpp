#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid
{

class Icon {
public:
    ~Icon() = default;
    explicit Icon(std::string a_iconName);
    Icon(const Icon& a_other) = delete;
    Icon& operator=(const Icon &a_other) = delete;

    void draw(sf::RenderWindow& a_target) const;

private:
    sf::Texture m_iconTexture;
    sf::Sprite m_iconSprite;


};

} // arkanoid




