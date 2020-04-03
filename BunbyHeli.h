#pragma once
#include "MoveableEntity.h"
class BunbyHeli :
	public MoveableEntity
{
public:
	BunbyHeli(Renderer* renderer, LevelManager* levelmanager, float x, float y, int LayerNum);
	~BunbyHeli();

	void Update();


private:


};

