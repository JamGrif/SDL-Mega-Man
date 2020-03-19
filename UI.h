#pragma once
#include <SDL.h>
#include <string>
#include "SDL_ttf.h"
#include <iostream>
class UI
{
public:
	UI(SDL_Renderer* renderer);
	~UI();

	void PresentUi(int PCoins);

	//TTF_Font* font

private:

	TTF_Font* m_pFont = TTF_OpenFont("Assets/DejaVuSans.ttf", 45);

	SDL_Renderer* m_pRenderer;
	SDL_Surface* surface;
	SDL_Texture* texture;

	int texW = 0;
	int texH = 0;

	SDL_Rect textRect;
	Uint8 R = 255;
	Uint8 G = 255;
	Uint8 B = 255;
	SDL_Color color = { R, G, B };

	//UI
	std::string FirstLine = "        COINS            ";
	std::string SecondLine = "Win by collecting 5 coins and reaching end flag";

	int CoinsCollected = 0;
	std::string SCoinsCollected = "";
	
};

