#include "MoveableEntity.h"

MoveableEntity::MoveableEntity(Renderer* renderer, LevelManager* levelmanager, int LayerNum)
	:Entity(renderer, LayerNum)
{

	m_plevelmanager = levelmanager;

	m_Moveable = true;
}


void MoveableEntity::Up()
{
	if (!m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right)) 
	{
		Velocity.y -= m_Acceleration;
		m_VerticalMoving = true;
		if (Velocity.y < -m_MaxVelocity) { Velocity.y = -m_MaxVelocity; }
	}
	else 
	{
		
		Velocity.y = 0;
	}
}

void MoveableEntity::Down()
{
	Velocity.y += m_Acceleration;
	if (Velocity.y > m_MaxVelocity) { Velocity.y = m_MaxVelocity; }

	if (m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right))
	{
		m_object->SetY(m_object->GetY() - Velocity.y);
		Velocity.y = 0;
	}
}

void MoveableEntity::Left()
{
	if (!m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right))
	{
		Velocity.x -= m_Acceleration;
		m_HorizontalMoving = true;
		if (Velocity.x < -m_MaxVelocity) { Velocity.x = -m_MaxVelocity; }
	}
	else
	{
		//m_object->SetX((m_object->GetX() + Velocity.x)+1);
		Velocity.x = 0;
	}
}

void MoveableEntity::Right()
{
	if (!m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right))
	{
		Velocity.x += m_Acceleration;
		m_HorizontalMoving = true;
		if (Velocity.x > m_MaxVelocity) { Velocity.x = m_MaxVelocity; }
	}
	else
	{
		//m_object->SetX((m_object->GetX() - Velocity.x)-1);
		Velocity.x = 0;
	}
}


