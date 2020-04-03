#pragma once

#include "Renderer.h"
using namespace NSRenderer;

#include "Camera.h"
#include "Input.h"
#include "LevelManager.h"

#include "Player.h"
#include "BunbyHeli.h"

#include <list>
class EntityManager
{
public:
	EntityManager(Renderer* renderer, Camera* camera, Input* input, LevelManager* levelmanager);
	~EntityManager();

	void UpdateEntities();

	void CreatePlayer(float X, float Y);

	void CreateBunbyHeli(float X, float Y);

private:

	Renderer* m_prenderer;

	Camera* m_pcamera;

	Input* m_pinput;

	LevelManager* m_plevelmanager;

	std::list<Entity*> Entities;

	Player* player;

	BunbyHeli* bunbyheli;

};

