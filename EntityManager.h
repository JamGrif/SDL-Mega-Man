#pragma once

#include "Renderer.h"
using namespace NSRenderer;

#include "Camera.h"

#include "Player.h"
#include "BunbyHeli.h"

#include "LevelBlock.h"

#include <list>
class EntityManager
{
public:
	EntityManager(Renderer* renderer, Camera* camera);
	~EntityManager();

	void UpdateEntities();

	void CreatePlayer(float X, float Y);
	void CreateLevelBlock(float X, float Y, const char* AssetName);
	void CreateBunbyHeli(float X, float Y);

private:

	Renderer* m_prenderer;

	Camera* m_pcamera;

	std::list<Entity*> Entities;

	Player* player;

	LevelBlock* levelblock;

	BunbyHeli* bunbyheli;

};

