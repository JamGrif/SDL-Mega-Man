#pragma once
#include "Entity.h"
#include "Camera.h"
class Player :
	public Entity
{
public:
	Player(Camera* camera, Renderer* renderer, int LayerNum);
	~Player();

	void Move(char direction);

	void Update();

private:

	Camera* m_pcamera;

	int speed = 5;

};

