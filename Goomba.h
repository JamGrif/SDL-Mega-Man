#pragma once
#include "Creature.h"
#include "Player.h"
class Goomba :
	public Creature
{
public:
	Goomba(SDL_Renderer* renderer, int xpos, int ypos, Level* pLevel, Player* pPlayer, bool useTransparency = true);

	void Update();

	bool GoombaHitPlayer();


private:

	int PlayerX = 0;
	int PlayerY = 0;

	bool MovingRight = true;

	bool HitPlayer = false;

	

	std::vector<std::string> GoombaMove;
	std::string GoombaSprite1 = "Assets/Goomba1.bmp";
	std::string GoombaSprite2 = "Assets/Goomba2.bmp";

	Player* playerinfo;
};

