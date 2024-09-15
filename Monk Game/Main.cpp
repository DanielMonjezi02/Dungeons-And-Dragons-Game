#include "Game.h"

int main()
{

	Game* game = Game::getGameInstance();

	while (!game->getQuit() == true)
	{
		game->createGame();
	}

	system("pause");

	return 0; 
}

