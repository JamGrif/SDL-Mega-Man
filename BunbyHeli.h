#pragma once
#include "Entity.h"
class BunbyHeli :
	public Entity
{
public:
	BunbyHeli(Renderer* renderer, int LayerNum);
	~BunbyHeli();

	void Update();


private:


};

