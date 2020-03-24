#include "BunbyHeli.h"

BunbyHeli::BunbyHeli(Renderer* renderer, float x, float y, int LayerNum)
	:Entity(renderer, LayerNum)
{
	m_object->SetSprite("Assets/BunbyHeli1.bmp");

	m_Width = 48;
	m_Height = 48;

	m_object->SetX(x);
	m_object->SetY(y);

	m_Moveable = true;
}

BunbyHeli::~BunbyHeli()
{
}

void BunbyHeli::Update()
{
}
