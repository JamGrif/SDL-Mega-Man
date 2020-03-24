#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include "SDL.h"
#include "SDL_render.h"

#include "EntityManager.h"

#include "Renderer.h"
using namespace NSRenderer;

class LevelManager
{
public:
	LevelManager(Renderer* renderer, EntityManager* entitymanager);
	~LevelManager();

	void LoadLevel();
	void UnloadLevel();

	void RenderLevel();	

private:
	//Size of each block
	const int m_BlockWidth = 32;
	const int m_BlockHeight = 32;

	//Size of the currently loaded level in block amounts
	int m_LevelWidth;
	int m_LevelHeight;

	//This is how many blocks can be shown on the screen at once
	const int MaxBlockWidth = 22;
	const int MaxBlockHeight = 12;

	//Variables used to draw the level 
	int SavedXDrawTo = 0;
	float m_XDrawTo = 0;
	float m_YDrawTo = 0;
	int m_DrawingPosition = 0;


	//Currently loaded level in the vector
	int m_LoadedLevel = 0;

	//Renderer
	Renderer* m_prenderer;

	//Entity manager
	EntityManager* m_pentitymanager;

	//The level vector
	std::vector<std::string> LevelVector;

	//Loading level into vector
	std::string ThingToAdd = "";
	std::string temp = "";
	int ReadingPosition = 0;
	

};

