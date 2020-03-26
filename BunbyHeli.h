#pragma once
#include "Entity.h"
class BunbyHeli :
	public Entity
{
public:
	BunbyHeli(Renderer* renderer, float x, float y, int LayerNum);
	~BunbyHeli();

	void Update();

	void OnCollision();


private:


};

