#pragma once

#include "Renderer.h"
using namespace NSRenderer;

#include "BunbyHeli.h"

#include "LevelBlock.h"

#include <list>
class EntityManager
{
public:
	EntityManager(Renderer* renderer);
	~EntityManager();

	void UpdateEntities();


	void CreateLevelBlock(float X, float Y, const char* AssetName);
	void CreateBunbyHeli(float X, float Y);

private:

	Renderer* m_prenderer;

	std::list<Entity*> Entities;

	LevelBlock* levelblock;

	BunbyHeli* bunbyheli;

};

