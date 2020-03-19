#include "UI.h"

UI::UI(SDL_Renderer* renderer)
{
	std::cout << "UI created!" << std::endl;
	m_pRenderer = renderer;



}

UI::~UI()
{
	
}

// Text we want to display, screen X and Y positions, font we want to use, colour of text
void UI::PresentUi(int PCoins)
{
	CoinsCollected = PCoins;
	surface = nullptr;
	texture = nullptr;

	m_pFont = TTF_OpenFont("Assets/DejaVuSans.ttf", 40);

	//First line of Ui
	surface = TTF_RenderText_Solid(m_pFont, FirstLine.c_str(), color);

	texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

	textRect = { 0, 600, texW, texH };

	SDL_RenderCopy(m_pRenderer, texture, NULL, &textRect);

	SDL_DestroyTexture(texture);

	SDL_FreeSurface(surface);
	
	//Second line of Ui
	surface = TTF_RenderText_Solid(m_pFont, SecondLine.c_str(), color);

	texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

	textRect = { 170, 0, texW, texH };

	SDL_RenderCopy(m_pRenderer, texture, NULL, &textRect);

	SDL_DestroyTexture(texture);

	SDL_FreeSurface(surface);

	//Coins collected
	SCoinsCollected = std::to_string(CoinsCollected);
	surface = TTF_RenderText_Solid(m_pFont, SCoinsCollected.c_str(), color);

	texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

	textRect = { 150, 650, texW, texH };

	SDL_RenderCopy(m_pRenderer, texture, NULL, &textRect);
	

	//Cleanup
	SDL_DestroyTexture(texture);
	
	SDL_FreeSurface(surface);
	
	TTF_CloseFont(m_pFont);
}
