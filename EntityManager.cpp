#include "EntityManager.h"

EntityManager::EntityManager(Renderer* renderer, Camera* camera, Input* input)
{

	m_prenderer = renderer;

	m_pcamera = camera;

	m_pinput = input;

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
			if (CheckCollision(entity)) 
			{
				//std::cout << entity << std::endl;
				//entity->OnCollision();
			}
			
		}
		entity->Update();
		x++;
	}
	//std::cout << x << " entities were updated." << std::endl;
}

bool EntityManager::CheckCollision(Entity*& EntityToCheck)
{
	EntityToCheck->UpdateCollisionPosition();
	for (Entity* entity : Entities) //Loop through all entities
	{
		entity->UpdateCollisionPosition();
		if (EntityToCheck != entity) //Ensures entity doesnt check for collision against itself
		{
			if ((EntityToCheck->GetRigCol() <= entity->GetLefCol() || EntityToCheck->GetLefCol() >= entity->GetRigCol()) && (EntityToCheck->GetTopCol() <= entity->GetBotCol() || EntityToCheck->GetBotCol() >= entity->GetTopCol()))
			{
				return true;
			}
		}
	}

	return false;
}



void EntityManager::CreatePlayer(float X, float Y)
{
	std::cout << "Adding player to entity list with x cord of " << X << " and y cord of " << Y << std::endl;
	Entities.push_back(player = new Player(m_pcamera, m_prenderer, m_pinput, X, Y, PlayL));
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
