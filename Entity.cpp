#include "Entity.h"

Entity::Entity(Renderer* renderer, int xpos, int ypos, Level* pLevel, bool useTransparency)
{
	//Store the renderer for future configuring and drawing
	m_prenderer = renderer;

	Position.x = xpos;
	Position.y = ypos;

	levelinfo = pLevel;
}

Entity::~Entity()
{
	if (m_pbitmapTexture)
	{
		SDL_DestroyTexture(m_pbitmapTexture);
	}
	if (m_pbitmapSurface)
	{
		SDL_FreeSurface(m_pbitmapSurface);
	}

}



void Entity::draw()
{
	//m_DrawX = Position.x - levelinfo->GetViewPortX();
	if (m_pbitmapTexture)
	{
		SDL_Rect destRect = {Position.x, Position.y, m_pbitmapSurface->w, m_pbitmapSurface->h }; //Where on screen bitmap is drawn to and how big it will appear
		SDL_RenderCopy(m_pRenderer, m_pbitmapTexture, NULL, &destRect);
	}

	
}

void Entity::GetCollisionPosition()
{
	//SpeedModifyer is used for creatures that have a speed above 1. It allows them to get as close to an object as they can
	
	TopLeftPosX = Position.x;
	TopLeftPosY = Position.y;

	TopRightPosX = (Position.x + (m_Width - 1));
	TopRightPosY = Position.y;

	BotLeftPosX = Position.x;
	BotLeftPosY = Position.y + (m_Height - 1);

	BotRightPosX = (Position.x + (m_Width - 1));
	BotRightPosY = Position.y + (m_Height - 1);
}


int Entity::GetX()
{
	return Position.x;
}

int Entity::GetY()
{
	return Position.y;
}
