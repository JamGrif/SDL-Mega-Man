#include "Entity.h"

Entity::Entity(Renderer* renderer, int LayerNum)
{
	//Store the renderer for future configuring and drawing
	m_prenderer = renderer;

	//Create the object
	m_object = m_prenderer->CreateSprite(LayerNum);

}

Entity::~Entity()
{
	

}

bool Entity::GetMoveable()
{
	return m_Moveable;
}




