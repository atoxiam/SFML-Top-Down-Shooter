
#include "Game.h"

int main(){
	Game boomy;
	boomy.ChangeState(Game::gameStates::SPLASHSTATE); 

	boomy.Run();

	return 0;
}