#include "Game.h"
#undef main

int main() 
{
	Game* game = new Game();

	if (game) 
	{
		game->GameLoop();
		delete game;
		game = nullptr;
	}
	return 0;
}
