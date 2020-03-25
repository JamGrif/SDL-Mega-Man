#include "Player.h"

Player::Player(Camera* camera, Renderer* renderer, Input* input, float X, float Y, int LayerNum)
	:Entity(renderer, LayerNum)
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

}


Player::~Player()
{

}

void Player::Update()
{
	

	if (m_pinput->KeyIsPressed(KEY_D))
	{
		//std::cout << "D" << std::endl;
		m_object->SetX(m_object->GetX() + speed);
	}
	if (m_pinput->KeyIsPressed(KEY_A))
	{
		//std::cout << "A" << std::endl;
		m_object->SetX(m_object->GetX() - speed);
	}
	if (m_pinput->KeyIsPressed(KEY_W))
	{
		m_object->SetY(m_object->GetY() - speed);
	}
	if (m_pinput->KeyIsPressed(KEY_S))
	{
		m_object->SetY(m_object->GetY() + speed);
	}
	if (m_pinput->KeyIsPressed(KEY_SPACE))
	{
		
	}

	//Centers the camera on the player
	m_pcamera->CenterCamera(m_object->GetX(), m_object->GetY());
}












