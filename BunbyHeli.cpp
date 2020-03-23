#include "BunbyHeli.h"

BunbyHeli::BunbyHeli(Renderer* renderer, int LayerNum)
	:Creature(renderer, LayerNum)
{
	m_object->SetSprite("Assets/BunbyHeli1.bmp");

	m_Width = 48;
	m_Height = 48;

	m_object->SetX(100);
	m_object->SetY(100);
}

BunbyHeli::~BunbyHeli()
{
}

void BunbyHeli::Update()
{
}
