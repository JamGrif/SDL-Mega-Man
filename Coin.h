#pragma once
#include "Entity.h"
#include "Player.h"
class Coin :
	public Entity
{
public:
	Coin(SDL_Renderer* renderer, int xpos, int ypos, Level* pLevel, Player* pPlayer, bool useTransparency = true);

	void Update();

	bool IsCoinCollected(); //returns the coin that has been collected

private:

	bool CoinCollected = false;
	bool AppliedCoinAddition = false;

	int PlayerX = 0;
	int PlayerY = 0;

	Player* playerinfo;

};

