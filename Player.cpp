#include "Player.h"

Player::Player(Renderer* renderer, int xpos, int ypos)
	:Creature(renderer, xpos, ypos)
{
	//Megaman is 48 x 48
	m_Width = 48;
	m_Height = 48;

	//Set the player sprite to the default sprite
	m_object->SetSprite("Assets/PlayerIdle1.bmp");

}


Player::~Player()
{

}

void Player::Move(char Direction)
{
	if (Direction == 'u') //Up
	{
		
	}
	else if (Direction == 'd') //Down
	{
		
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
	std::cout << m_object->GetX() << std::endl;
	std::cout << m_object->GetY() << std::endl;

}












