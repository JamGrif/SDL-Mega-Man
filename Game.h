#pragma once
#include <SDL.h>
#include "SDL_ttf.h"

#include <iostream>
#include <list>
#include <string>

#include "Input.h"
#include "UI.h"
#include "Player.h"
//#include "Goomba.h"
//#include "Sky.h"
#include "Level.h"
//#include "Coin.h"
#include "Renderer.h"


class Game
{
public:
	Game();
	~Game();

	void GameLoop(); //Main game loop

	void Render(); //Clears and displays the window

	void CheckKeyPressed(); //Checks for keyboard / mouse input

	

private:

	//Size of the window
	int m_ScreenWidth = 1280;
	int m_ScreenHeight = 720;

	//SDL_Window* m_Window;
	//SDL_Renderer* m_Renderer;

	//Game objects in the scene
	Player* m_Player; 

	//Level* level;

	//Coin* m_Coin1;
	//Coin* m_Coin2;
	//Coin* m_Coin3;
	//Coin* m_Coin4;
	//Coin* m_Coin5;

	//Goomba* m_Goomba1;
	//Goomba* m_Goomba2;
	//Goomba* m_Goomba3;

	//Sky* m_Sky;

	UI* m_ui;
	
	Input* input = new Input();

	//std::list<Coin*> ListOfCoins;
	//std::list<Goomba*> ListOfGoombas;

	//Renderer
	Renderer* RendererObj;

};

