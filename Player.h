#pragma once
#include "Creature.h"

class Player :
	public Creature
{
public:
	Player(Renderer* renderer, int xpos, int ypos);
	~Player();

	void Move(char direction);

	void Update();

private:

	int speed = 5;



};

