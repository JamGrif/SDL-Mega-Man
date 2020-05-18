#include "UI.h"

UI::UI(Renderer* renderer)
{
	std::cout << "Created UIManager" << std::endl;
	m_prenderer = renderer;

}

UI::~UI()
{
	
}

void UI::SetFPS(float fps)
{
	FPS = fps;
}

// Text we want to display, screen X and Y positions, font we want to use, colour of text
void UI::PresentUi()
{
	surface = nullptr;
	texture = nullptr;

	m_pFont = TTF_OpenFont("Assets/DejaVuSans.ttf", 40);

	//"FPS:"
	surface = TTF_RenderText_Solid(m_pFont, FirstLine.c_str(), color);

	texture = SDL_CreateTextureFromSurface(m_prenderer->GetRenderer(), surface);

	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

	textRect = { 0, 1, texW, texH };

	SDL_RenderCopy(m_prenderer->GetRenderer(), texture, NULL, &textRect);

	SDL_DestroyTexture(texture);

	SDL_FreeSurface(surface);

	//Actual fps
	surface = TTF_RenderText_Solid(m_pFont, std::to_string(FPS).c_str(), color);

	texture = SDL_CreateTextureFromSurface(m_prenderer->GetRenderer(), surface);

	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

	textRect = { 85, 1, texW, texH };

	SDL_RenderCopy(m_prenderer->GetRenderer(), texture, NULL, &textRect);

	
	SDL_DestroyTexture(texture);
	
	SDL_FreeSurface(surface);
	
	//Cleanup
	TTF_CloseFont(m_pFont);
}
