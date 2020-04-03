#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include "SDL.h"
#include "SDL_render.h"

#include "LevelBlock.h"

#include "Renderer.h"
using namespace NSRenderer;

class LevelManager
{
public:
	LevelManager(Renderer* renderer);
	~LevelManager();

	void LoadLevel();
	void UnloadLevel();

	void RenderLevel();	

	void CreateLevelBlock(float X, float Y, const char* AssetName);

	//For entities
	bool CheckForWall(float EntityTop, float EntityBottom, float EntityLeft, float EntityRight);
	bool CheckBlock(LevelBlock* lb, float EntityTop, float EntityBottom, float EntityLeft, float EntityRight);


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

	//The level vector
	std::vector<std::string> LevelVector;

	//Level blocks list
	LevelBlock* levelblock;
	std::list<LevelBlock*> LevelBlocks;

	//Loading level into vector
	std::string ThingToAdd = "";
	std::string temp = "";
	int ReadingPosition = 0;
	

};

