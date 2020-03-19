#include "Coin.h"

Coin::Coin(SDL_Renderer* renderer, int xpos, int ypos, Level* pLevel, Player* pPlayer, bool useTransparency)
	:Entity(renderer, xpos, ypos, pLevel, useTransparency)
{
	CurrentPicture = "Assets/Coin.bmp";
	UpdateBitmap(CurrentPicture, useTransparency);

	m_Width = 32;
	m_Height = 32;

	playerinfo = pPlayer;

}

void Coin::Update()
{

	//Check for collision with player
	GetCollisionPosition();

	PlayerX = playerinfo->GetX();
	PlayerY = playerinfo->GetY();
	
	if (PlayerX > TopLeftPosX-m_Width && PlayerX < TopRightPosX+m_Width && PlayerY > TopLeftPosY && PlayerY < BotRightPosY)
	{
		//std::cout << "Player collided with coin" << std::endl;
		CoinCollected = true;
		Position.y = -50;
	}



}

int Coin::IsCoinCollected()
{
	if (CoinCollected && !AppliedCoinAddition) 
	{
		AppliedCoinAddition = true;
		return CoinCollected;
	}
	
}
