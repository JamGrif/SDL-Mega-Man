#pragma once
#include "Entity.h"
#include "LevelManager.h"
class MoveableEntity :
	public Entity
{
public:
	MoveableEntity(Renderer* renderer, LevelManager* levelmanager, int LayerNum);

	//Changes velocity depending on multiple factors
	void PhysicsUpdate();

	void Up();
	void Down();
	void Left();
	void Right();

protected:

	struct Vector2 { float x; float y; };
	Vector2 Velocity{ 0,0 };


	float m_Acceleration = 0;

	const float m_MaxVelocity = 8;
	const float m_AirResistance = 1;
	const float m_Gravity = 3;

	bool m_VerticalMoving = false;
	bool m_HorizontalMoving = false;

	bool IsGrounded = false;
	bool AppliedGravity = false;

	bool IsJumping = false;
	bool CanJump = false;
	const float m_JumpSpeed = 40;
	const float m_JumpMaxTick = 40;
	float m_JumpCurrentTick = 0;

	LevelManager* m_plevelmanager;

};

