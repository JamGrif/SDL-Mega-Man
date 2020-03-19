#include "Goomba.h"

Goomba::Goomba(SDL_Renderer* renderer, int xpos, int ypos, Level* pLevel, Player* pPlayer, bool useTransparency)
	:Creature(renderer, xpos, ypos, pLevel, useTransparency)
{
	m_Width = 48;
	m_Height = 48;

	UpdateBitmap(GoombaSprite1, true);
	
	playerinfo = pPlayer;

	m_Acceleration = 1;

	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite1);
	GoombaMove.push_back(GoombaSprite2);
	GoombaMove.push_back(GoombaSprite2);
	GoombaMove.push_back(GoombaSprite2);
	GoombaMove.push_back(GoombaSprite2);
	GoombaMove.push_back(GoombaSprite2);
	GoombaMove.push_back(GoombaSprite2);
	GoombaMove.push_back(GoombaSprite2);
	GoombaMove.push_back(GoombaSprite2);



}

void Goomba::Update()
{
	PlayerX = playerinfo->GetX();
	PlayerY = playerinfo->GetY();

	if (HitPlayer) { HitPlayer = false; }

	//Only updates Goomba if within range of player
	if (PlayerX < Position.x + 1000 && PlayerX > Position.x - 1000) 
	{
		//Check if goomba can move in direction
		GetCollisionPosition();

		if (MovingRight) //Check to the right of the goomba for a wall
		{
			MovingRight = levelinfo->IsWall(TopRightPosX, TopRightPosY, BotRightPosX, BotRightPosY - 2) == true ? false : true;
		}
		else //Check to the left of the goomba for a wall
		{
			MovingRight = levelinfo->IsWall(TopLeftPosX, TopLeftPosY, BotLeftPosX, BotLeftPosY - 2) == true ? true : false;
		}

		//Move goomba in a direction
		if (MovingRight) //Move the goomba to the right
		{
			Position.x += 1;
		}
		else //Move the goomba to the left
		{
			Position.x -= 1;
		}

		//Check if the goomba has collided with player
		if (PlayerX < Position.x + m_Width && PlayerX > Position.x - m_Width && PlayerY < Position.y + m_Height && PlayerY > Position.y - m_Height) 
		{
			HitPlayer = true;
		}


		m_CurrentFrame++;
		if (m_CurrentFrame > 15) { m_CurrentFrame = 0; }
		CurrentPicture = GoombaMove.at(m_CurrentFrame);
		UpdateBitmap(CurrentPicture, true);


	}
	


}

bool Goomba::GoombaHitPlayer()
{
	return HitPlayer;
}

