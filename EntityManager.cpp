#include "EntityManager.h"

EntityManager::EntityManager(Renderer* renderer, Camera* camera, Input* input, LevelManager* levelmanager)
{
	std::cout << "Created EntityManager" << std::endl;
	m_prenderer = renderer;

	m_pcamera = camera;

	m_pinput = input;

	m_plevelmanager = levelmanager;

}

EntityManager::~EntityManager()
{
}

void EntityManager::UpdateEntities()
{
	for (Entity* entity : Entities) 
	{
		entity->UpdateCollisionPosition();
		entity->Update();
	}
	//std::cout << x << " entities were updated." << std::endl;
}


void EntityManager::CreatePlayer(float X, float Y)
{
	//std::cout << "Adding player to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(player = new Player(m_pcamera, m_prenderer, m_pinput, m_plevelmanager, X, Y, PlayL));
}

void EntityManager::CreateBunbyHeli(float X, float Y)
{
	//std::cout << "Adding bunbyheli to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(bunbyheli = new BunbyHeli(m_prenderer, m_plevelmanager, X, Y, PlayL));
}
