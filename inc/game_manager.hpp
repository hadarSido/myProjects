#include "game.hpp"
namespace arkanoid {
class GameManager {
public:                                                            
    GameManager() = default;  
    ~GameManager() = default;
    GameManager(const GameManager &a_other) = default;                                      
    GameManager& operator=(const GameManager &a_other) = delete;  

    void executer();

};
} // arkanoid

