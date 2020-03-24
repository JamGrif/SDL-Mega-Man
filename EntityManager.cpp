#include "EntityManager.h"

EntityManager::EntityManager(Renderer* renderer)
{

	m_prenderer = renderer;

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



void EntityManager::CreateLevelBlock(float X, float Y, const char* AssetName)
{
	std::cout << "Adding levelblock to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(levelblock = new LevelBlock(m_prenderer, X, Y, AssetName, 2));
}

void EntityManager::CreateBunbyHeli(float X, float Y)
{
	std::cout << "Adding bunbyheli to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(bunbyheli = new BunbyHeli(m_prenderer, X, Y, 2));
}
