#include "MoveableEntity.h"

MoveableEntity::MoveableEntity(Renderer* renderer, LevelManager* levelmanager, int LayerNum)
	:Entity(renderer, LayerNum)
{

	m_plevelmanager = levelmanager;

	m_Moveable = true;
}


void MoveableEntity::Up()
{
	Velocity.y -= m_Acceleration;
	if (Velocity.y < -m_MaxVelocity) { Velocity.y = -m_MaxVelocity; }
	m_VerticalMoving = true;
}

void MoveableEntity::Down()
{
	Velocity.y += m_Acceleration;
	if (Velocity.y > m_MaxVelocity) { Velocity.y = m_MaxVelocity; }
	m_VerticalMoving = true;
}

void MoveableEntity::Left()
{
	Velocity.x -= m_Acceleration;
	if (Velocity.x < -m_MaxVelocity) { Velocity.x = -m_MaxVelocity; }
	m_HorizontalMoving = true;
	
}

void MoveableEntity::Right()
{
	Velocity.x += m_Acceleration;
	if (Velocity.x > m_MaxVelocity) { Velocity.x = m_MaxVelocity; }
	m_HorizontalMoving = true;
	
}


