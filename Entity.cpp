#include "Entity.h"

Entity::Entity(Renderer* renderer, int LayerNum)
{
	std::cout << "Created Entity" << std::endl;
	//Store the renderer for future configuring and drawing
	m_prenderer = renderer;

	//Create the object
	m_object = m_prenderer->CreateSprite(LayerNum);

}

Entity::~Entity()
{
	

}

void Entity::UpdateCollisionPosition()
{
	m_Left = m_object->GetX();
	m_Right = m_object->GetX() + m_Width;
	m_Top = m_object->GetY();
	m_Bottom = m_object->GetY() + m_Height;
}

bool Entity::GetMoveable()
{
	return m_Moveable;
}

float Entity::GetTopCol()
{
	return m_Top;
}

float Entity::GetBotCol()
{
	return m_Bottom;
}

float Entity::GetLefCol()
{
	return m_Left;
}

float Entity::GetRigCol()
{
	return m_Right;
}




