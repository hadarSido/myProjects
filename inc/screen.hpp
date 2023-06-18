#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid
{

class Screen {
public:
    virtual ~Screen() = default;
    
    virtual void run() = 0;

protected:
    Screen() = default;
    Screen(const Screen& a_other) = default;
    Screen& operator=(const Screen &a_other) = default; 
};

} // arkanoid

