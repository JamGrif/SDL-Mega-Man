#pragma once
#include "MoveableEntity.h"
#include "Camera.h"
#include "Input.h"
class Player :
	public MoveableEntity
{
public:
	Player(Camera* camera, Renderer* renderer, Input* input, LevelManager* levelmanager, float X, float Y, int LayerNum);
	~Player();

	void Update();

	void SpriteUpdate();


private:

	Input* m_pinput;
	Camera* m_pcamera;

	//Idle sprite
	std::string PlayerIdle1L = "Assets/PlayerIdle1L.bmp";
	std::string PlayerIdle1R = "Assets/PlayerIdle1R.bmp";

	//Running sprite
	std::string PlayerRun1R = "Assets/PlayerRun1R.bmp";
	std::string PlayerRun2R = "Assets/PlayerRun2R.bmp";
	std::string PlayerRun3R = "Assets/PlayerRun3R.bmp";

	std::string PlayerRun1L = "Assets/PlayerRun1L.bmp";
	std::string PlayerRun2L = "Assets/PlayerRun2L.bmp";
	std::string PlayerRun3L = "Assets/PlayerRun3L.bmp";

	std::vector<std::string> PlayerRunL;
	std::vector<std::string> PlayerRunR;


	std::string SpriteToUse = "";
	int m_CurrentFrame = 0;

	bool FacingRight = true;

};

