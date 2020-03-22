#pragma once
#include <string>
#include "SDL.h"
#include "SDL_render.h"
#include <iostream>
#include <vector>

#include "Renderer.h"
using namespace NSRenderer;

class Entity
{
public:
	Entity(Renderer* renderer);
	~Entity();

	virtual void Update() = 0;

protected:
	
	//Renderer
	Renderer* m_prenderer;

	Sprite* m_object;

	struct Vector { int x; int y; };
	//Vector Position = { 0,0 };
	Vector Velocity{ 0, 0 };

	//std::string Filename = "";

	//std::string CurrentPicture = "";

	//Level* levelinfo;

	int TopLeftPosX = 0;
	int TopLeftPosY = 0;
	int TopRightPosX = 0;
	int TopRightPosY = 0;
	int BotLeftPosX = 0;
	int BotLeftPosY = 0;
	int BotRightPosX = 0;
	int BotRightPosY = 0;

	//Size of Entity
	int m_Width = 0;
	int m_Height = 0;


};

