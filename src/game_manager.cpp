#include "game_manager.hpp"
#include "main_screen.hpp"
#include "game_screen.hpp"
#include "top10_screen.hpp"

namespace arkanoid {

void GameManager::executer() 
{
	while(true) {
		MainScreen mainS{};
		Game gameMain{mainS};
		gameMain.run();
		if(mainS.isNextWindow()) {
			GameScreen gameS{};
			Game gamePlay{gameS};
			gamePlay.run();
			if(gameS.isPrevWindow()){
				continue;
			}
			if(gameS.isNextWindow()){				
				Top10Screen ten{gameS.getWinner()};
				Game gameTop10{ten};
				gameTop10.run();
				if(ten.isMainWindow()) {
					continue;
				}
			}
		}
		else {
			break;
		}
	}	
}

}//arkanoid
