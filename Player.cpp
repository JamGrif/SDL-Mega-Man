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

	m_Acceleration = 1;



}


Player::~Player()
{

}

void Player::Update()
{
	if (m_pinput->KeyIsPressed(KEY_D))
	{
		Right();
		std::cout << "right" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_A))
	{
		Left();
		std::cout << "left" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_W))
	{
		Up();
		std::cout << "up" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_S))
	{
		Down();
		std::cout << "down" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_SPACE))
	{
		
	}

	m_object->SetX(m_object->GetX() + Velocity.x);

	m_object->SetY(m_object->GetY() + Velocity.y);


	//if (Velocity.x != 0) { Velocity.x -= m_AirResistance; if (0 - Velocity.x > Velocity.x) { Velocity.x = 0; } }
	//if (Velocity.y != 0) { Velocity.y -= m_AirResistance; if (0 - Velocity.y > Velocity.y) { Velocity.y = 0; } }

	//Apply air resistance to velocity
	/*
	if (!m_HorizontalMoving)
	{
		if (Velocity.x != 0)
		{
			if (Velocity.x > 0)
			{
				Velocity.x -= m_AirResistance;
				if (0 - Velocity.x > Velocity.x) { Velocity.x = 0; }
			}
			else if (Velocity.x < 0)
			{
				Velocity.x += m_AirResistance;
				if (0 - Velocity.x < Velocity.x) { Velocity.x = 0; }
			}
		}
	}

	if (!m_VerticalMoving) 
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
				if (0 - Velocity.y < Velocity.x) { Velocity.y = 0; }
			}
		}
	}
		
	m_HorizontalMoving = false;
	m_VerticalMoving = false;
	*/

	//std::cout << "x velocity is " << Velocity.x << std::endl;
	//std::cout << "y velocity is " << Velocity.y << std::endl;

	//Centers the camera on the player
	m_pcamera->CenterCamera(m_object->GetX(), m_object->GetY());
}












