#pragma once
#include "Entity.h"

class Creature :
	public Entity
{
public:
	Creature(Renderer* renderer, int xpos, int ypos, Level* plevel, bool useTransparency);

	void DisplayPosition();


protected:
	//Movement
	int m_Acceleration = 0;

	const int m_MaxVelocity = 10;
	const int m_AirResistance = 1;
	const int m_Gravity = 3;

	int m_MaxJumpTick = 0;
	int m_CurrentJumpTick = 0;
	int m_CurrentJumpSpeed = 0;
	int m_JumpSpeed = 0;

	bool CanMove = true;
	bool IsGrounded = false;
	bool IsJumping = false;
	bool JustJumped = false;
	bool AppliedGravity = false;
	bool Moving = false;

	bool TouchingRight = false;
	bool TouchingLeft = false;
	bool TouchingUp = false;
	bool TouchingDown = false;

	int m_CurrentFrame = 0;
	
	
	int TempSpeed = 0;

	//Collision
	int VectorPosition = 0;

	

	//Drawing sprites
	bool FacingRight = true;

};

