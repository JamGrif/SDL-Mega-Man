#include "Player.h"

Player::Player(Camera* camera, Renderer* renderer, Input* input, LevelManager* levelmanager, float X, float Y, int LayerNum)
	:MoveableEntity(renderer, levelmanager, LayerNum)
{

	m_pcamera = camera;

	m_pinput = input;

	//Megaman is 48 x 48
	m_Width = 48;
	m_Height = 48;

	//Set the player sprite to the default sprite
	m_object->SetSprite("Assets/PlayerIdle1.bmp");

	m_object->SetX(X);
	m_object->SetY(Y);

	m_Moveable = true;

	m_Acceleration = 4;


}

Player::~Player()
{

}

void Player::Update()
{
	/*
		Input to move
	*/
	if (m_pinput->KeyIsPressed(KEY_D) || m_pinput->ControllerIsPressed(DPAD_RIGHT))
	{
		Right();
		//std::cout << "right" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_A) || m_pinput->ControllerIsPressed(DPAD_LEFT))
	{
		Left();
		//std::cout << "left" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_W))
	{
		Up();
		//std::cout << "up" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_S))
	{
		Down();
		//std::cout << "down" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_SPACE) || m_pinput->ControllerIsPressed(BUTTON_A))
	{
		std::cout << "jumped" << std::endl;
	}

	/*
		Air Resistance
	*/

	//Apply air resistance to horizontal velocity
	if (m_HorizontalMoving) //Object moving horizontally
	{
		if (Velocity.x > 0) //Object moving right
		{
			Velocity.x -= m_AirResistance;
			if (0 - Velocity.x > Velocity.x) { Velocity.x = 0; }
		}
		else if (Velocity.x < 0) //Object moving left
		{
			Velocity.x += m_AirResistance;
			if (0 - Velocity.x < Velocity.x) { Velocity.x = 0; }
		}
	}
	
	
	if (m_VerticalMoving) 
	{
		if (Velocity.y != 0)
		{
			if (Velocity.y > 0)
			{
				Velocity.y -= m_AirResistance;
				if (0 - Velocity.y > Velocity.y) { Velocity.y = 0; }
			}
			else if (Velocity.y < 0)
			{
				Velocity.y += m_AirResistance;
				if (0 - Velocity.y < Velocity.y) { Velocity.y = 0; }
			}
		}
	}

	/*
		Gravity
	*/

	//

	/*
		Collision check and movement
	*/

	//Check for collision and move object horizontally
	if (m_HorizontalMoving) 
	{
		m_object->SetX(m_object->GetX() + Velocity.x);
		
		UpdateCollisionPosition();
		//Check collision with level 
		//if there is wall then keep checking until there is no wall. this allows the object to be right against the wall as opposed to a few pixels away from it
		//-------------------------------------------------------------------------
		if (m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right))
		{
		/*	int LeftOffset = 0;
			int RightOffset = 0;
			//Player is about to collide with wall so find players new position by reducing left/right face until there is no collision
			while (m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left+(LeftOffset), m_Right+(RightOffset)))
			{
				std::cout << "in while loop" << std::endl;
				//velocity going right
				if (Velocity.x > 0) { RightOffset--; }
				else { LeftOffset++; }
				//Velocity.x + 1;
			}
			*/
			//std::cout << "needs to move " << RightOffset << " to the right" << std::endl;
			//std::cout << "l is " << l << std::endl;
			
			//std::cout << "vx is " << (Velocity.x + LeftOffset + RightOffset) << std::endl;
			m_object->SetX(m_object->GetX() - Velocity.x); //------------------ need to change velocity.x to a different number
			Velocity.x = 0;
		}
	}
	
	//Check for collision and move object vertically
	if (m_VerticalMoving)
	{
		m_object->SetY(m_object->GetY() + Velocity.y);

		UpdateCollisionPosition();
		//Check collision with level 
		if (m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right))
		{
			m_object->SetY(m_object->GetY() - Velocity.y);
			Velocity.y = 0;
		}
	}

	if (Velocity.x == 0) { m_HorizontalMoving = false; }
	if (Velocity.y == 0) { m_VerticalMoving = false; }

	//Centers the camera on the player
	m_pcamera->CenterCamera(m_object->GetX(), m_object->GetY());
}












