#include "Entity.h"

Entity::Entity(Renderer* renderer, int xpos, int ypos)
{
	//Store the renderer for future configuring and drawing
	m_prenderer = renderer;

	//Create the object
	m_object = m_prenderer->CreateSprite();

}

Entity::~Entity()
{
	

}




