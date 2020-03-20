#pragma once
#include "Creature.h"

class Player :
	public Creature
{
public:
	Player(Renderer* renderer, int xpos, int ypos, Level* pLevel, bool useTransparency = true);
	~Player();

	void Move(char direction);

	void Update();

	bool HasPlayerWon();

	void SpriteUpdate(); 

	int GetCoinsCollected();
	void IncreaseCoinsCollected();

	void Respawn();

	//Coins
	int Coins = 0;
private:
	std::string SavedCurrentPicture = "";

	//Standing still sprites
	std::string PlayerR = "Assets/PlayerR.bmp";
	std::string PlayerL = "Assets/PlayerL.bmp";

	//Running sprites
	

	std::vector<std::string> PlayerRunL;
	std::vector<std::string> PlayerRunR;

	//Jumping sprite
	std::string PlayerJumpR = "Assets/PlayerJumpR.bmp";
	std::string PlayerJumpL = "Assets/PlayerJumpL.bmp";

	int SpawnPositionX = 640;
	int SpawnPositionY = -64;


};

