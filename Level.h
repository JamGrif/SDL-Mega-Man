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

class Level
{
public:
	Level(Renderer* renderer);
	~Level();

	void LoadLevel();
	void UnloadLevel();

	void RenderLevel();

	void CreateBlock(float X, float Y, const char* AssetName);
	void DeleteBlocks();
	

private:
	//Size of each block
	const int m_BlockWidth = 64;
	const int m_BlockHeight = 64;

	//Size of the currently loaded level in block amounts
	int m_LevelWidth;
	int m_LevelHeight;

	//This is how many blocks can be shown on the screen at once
	const int MaxBlockWidth = 22;
	const int MaxBlockHeight = 12;

	//Variables used to draw the level 
	int SavedXDrawTo = 0;
	int m_XDrawTo = 0;
	int m_YDrawTo = 0;
	int m_DrawingPosition;


	//Currently loaded level in the vector
	int m_LoadedLevel = 0;

	//Renderer
	Renderer* m_prenderer;

	//Blocks to draw
	/*std::string GrassBlock = "Assets/GrassBlock.bmp";
	std::string DirtBlock = "Assets/DirtBlock.bmp";
	std::string StoneBlock = "Assets/StoneBlock.bmp";
	std::string PlayerSpawn = "Assets/PlayerSpawn.bmp";
	std::string CoalBlock = "Assets/CoalBlock.bmp";
	std::string BackStoneBlock = "Assets/StoneBlockBack.bmp";
	std::string BackDirtBlock = "Assets/DirtBlockBack.bmp";
	*/


	//The level vector
	std::vector<std::string> LevelVector;

	//Level blocks
	//std::list<LevelBlock*> ListOfBlocks;
	LevelBlock* levelblock;

	//Loading level into vector
	std::string ThingToAdd = "";
	std::string temp = "";
	int ReadingPosition = 0;
	

};

