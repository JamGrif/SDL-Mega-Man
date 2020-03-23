#pragma once
#include "Creature.h"
class BunbyHeli :
	public Creature
{
public:
	BunbyHeli(Renderer* renderer, int LayerNum);
	~BunbyHeli();

	void Update();


private:


};

