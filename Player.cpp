#include "Player.h"

Player::Player(Renderer* renderer, int xpos, int ypos)
	:Creature(renderer, xpos, ypos)
{
	//player is 64 pixels wide and 128 pixels tall
	m_Width = 53;
	m_Height = 51;

	m_object = m_prenderer->CreateMesh();
	m_object->SetSprite("Assets/PlayerR.bmp");

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












