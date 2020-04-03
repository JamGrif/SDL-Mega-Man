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

private:

	Input* m_pinput;
	Camera* m_pcamera;


};

