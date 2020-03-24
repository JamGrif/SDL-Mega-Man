#include "Player.h"

Player::Player(Camera* camera, Renderer* renderer, int LayerNum)
	:Entity(renderer, LayerNum)
{

	m_pcamera = camera;

	//Megaman is 48 x 48
	m_Width = 48;
	m_Height = 48;

	//Set the player sprite to the default sprite
	m_object->SetSprite("Assets/PlayerIdle1.bmp");

	m_object->SetX(200);
	m_object->SetY(100);

	m_Moveable = true;

}


Player::~Player()
{

}

void Player::Move(char Direction)
{
	
	if (Direction == 'u') //Up
	{
		m_object->SetY(m_object->GetY() - speed);
	}
	else if (Direction == 'd') //Down
	{
		m_object->SetY(m_object->GetY() + speed);
	}
	else if (Direction == 'l') //Left
	{
		m_object->SetX(m_object->GetX() - speed);
	}
	else if (Direction == 'r') //Right
	{
		m_object->SetX(m_object->GetX() + speed);
	}
	
}

void Player::Update()
{
	//Centers the camera on the player
	m_pcamera->CenterCamera(m_object->GetX(), m_object->GetY());

	//std::cout << "X is " << m_object->GetX() << std::endl;
	//std::cout << "Y is " << m_object->GetY() << std::endl;

}












