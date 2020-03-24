#include "EntityManager.h"

EntityManager::EntityManager(Renderer* renderer, Camera* camera)
{

	m_prenderer = renderer;

	m_pcamera = camera;

}

EntityManager::~EntityManager()
{
}

void EntityManager::UpdateEntities()
{
	int x = 0;
	for (Entity* entity : Entities) 
	{
		if (entity->GetMoveable()) 
		{
			//std::cout << "checking collision" << std::endl;
		}
		entity->Update();
		x++;
	}
	//std::cout << x << " entities were updated." << std::endl;
}



void EntityManager::CreatePlayer(float X, float Y)
{
	std::cout << "Adding player to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(player = new Player(m_pcamera, m_prenderer, X, Y, PlayL));
}

void EntityManager::CreateLevelBlock(float X, float Y, const char* AssetName)
{
	std::cout << "Adding levelblock to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(levelblock = new LevelBlock(m_prenderer, X, Y, AssetName, PlayL));
}

void EntityManager::CreateBunbyHeli(float X, float Y)
{
	std::cout << "Adding bunbyheli to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(bunbyheli = new BunbyHeli(m_prenderer, X, Y, PlayL));
}
