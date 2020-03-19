#include "Sky.h"


Sky::Sky(SDL_Renderer* renderer, int xpos, int ypos, Level* pLevel, bool useTransparency)
	:Entity(renderer, xpos, ypos, pLevel, useTransparency)
{
	std::cout << "Sky created" << std::endl;

	UpdateBitmap(SkyBitmap, true);

}

void Sky::Update()
{

}

void Sky::draw()
{
	m_DrawX = (Position.x - levelinfo->GetViewPortX())/10;
	if (m_pbitmapTexture)
	{
		SDL_Rect destRect = { m_DrawX, Position.y, m_pbitmapSurface->w, m_pbitmapSurface->h }; //Where on screen bitmap is drawn to and how big it will appear
		SDL_RenderCopy(m_pRenderer, m_pbitmapTexture, NULL, &destRect);
	}
}
