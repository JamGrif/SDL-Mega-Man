#pragma once
#include <SDL.h>
#include "SDL_ttf.h"

#include <iostream>
#include <list>
#include <string>

#include "Input.h"
#include "UI.h"
//#include "Player.h"
//#include "Goomba.h"
//#include "Sky.h"
#include "LevelManager.h"
//#include "Coin.h"
#include "EntityManager.h"
#include "Renderer.h"
#include "Camera.h"



class Game
{
public:
	Game();
	~Game();

	void GameLoop(); //Main game loop

	void CheckKeyPressed(); //Checks for keyboard / mouse input

private:

	//Size of the window
	int m_ScreenWidth = 1280;
	int m_ScreenHeight = 720;

	//Camera
	Camera* CameraObj;

	//Renderer
	Renderer* RendererObj;

	//Input
	Input* InputObj;

	//UI
	UI* UIObj;

	//Entity Manager
	EntityManager* EMObj;

	//Level Manager
	LevelManager* LevelObj;

};

