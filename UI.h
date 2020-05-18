#pragma once
#include <SDL.h>
#include <string>
#include "SDL_ttf.h"
#include <iostream>

#include "Renderer.h"

using namespace NSRenderer;

class UI
{
public:
	UI(Renderer* renderer);
	~UI();

	void SetFPS(float fps);
	void PresentUi();

	//TTF_Font* font

private:

	Renderer* m_prenderer;

	float FPS = 0;

	TTF_Font* m_pFont = TTF_OpenFont("Assets/DejaVuSans.ttf", 45);

	SDL_Surface* surface;
	SDL_Texture* texture;

	int texW = 0;
	int texH = 0;

	SDL_Rect textRect;
	Uint8 R = 0;
	Uint8 G = 0;
	Uint8 B = 0;
	SDL_Color color = { R, G, B };

	//UI
	std::string FirstLine = "FPS:";

	
};

