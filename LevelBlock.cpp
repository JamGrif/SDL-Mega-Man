#include "LevelBlock.h"
LevelBlock::LevelBlock(Renderer* renderer, float x, float y, const char* AssetName, int LayerNum)
	:Entity(renderer, LayerNum)
{

	m_object->SetSprite(AssetName);

	m_object->SetX(x);
	m_object->SetY(y);

	m_Width = 32;
	m_Height = 32;

	UpdateCollisionPosition();

	//Collider.x = m_Width;
	//Collider.y = m_Height;

}

LevelBlock::~LevelBlock()
{
}

void LevelBlock::Update()
{
}
