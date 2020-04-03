#pragma once
#include "Entity.h"

class LevelBlock :
	public Entity
{
public:
	LevelBlock(Renderer* renderer, float x, float y, const char* AssetName, int LayerNum);
	~LevelBlock();

	void Update();


private:



};

