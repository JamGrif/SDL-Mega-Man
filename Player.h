#pragma once
#include "Creature.h"
#include "Camera.h"
class Player :
	public Creature
{
public:
	Player(Camera* camera, Renderer* renderer);
	~Player();

	static void Move(char direction);

	void Update();

private:

	Camera* m_pcamera;

	int speed = 5;

};

