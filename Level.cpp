#include "Level.h"

Level::Level(SDL_Renderer* renderer, int ScreenWidth, int ScreenHeight)
{
	//Screen resoultion fits a width of 20 blocks and a height of 12 blocks
	m_pRenderer = renderer;
	m_ScreenWidth = ScreenWidth;
	m_ScreenHeight = ScreenHeight;

	//By default, the program loads level 1 first
	LoadLevel();
	CreateTextures();
	
}

Level::~Level()
{
	FrontLevelVector.clear();
	BackLevelVector.clear();
}


void Level::LoadLevel()
{

	//Load front level into vector
#pragma region LoadFrontLevel

	std::ifstream SaveLevelFromText;
	SaveLevelFromText.open("Assets/Level1.txt");

	if (SaveLevelFromText.fail())
	{
		std::cout << "Failed to open text file, reset program." << std::endl;
		exit(0);
	}

	//Get level width. Get first line of level and count characters
	SaveLevelFromText.seekg(0) >> temp;
	m_LevelWidth = temp.length();

	m_LevelHeight = 12;

	//Goes through the level text file and adds that character into a vector which is used for drawing
	for (int j = 0; j < m_LevelHeight; j++)
	{
		for (int i = 0; i < m_LevelWidth; i++)
		{
			SaveLevelFromText.seekg(ReadingPosition) >> ThingToAdd;
			if (ThingToAdd.at(0) == 'G')
			{
				FrontLevelVector.push_back("G");
			}
			else if (ThingToAdd.at(0) == 'D')
			{
				FrontLevelVector.push_back("D");
			}
			else if (ThingToAdd.at(0) == 'S')
			{
				FrontLevelVector.push_back("S");
			}
			else if (ThingToAdd.at(0) == 'P')
			{
				FrontLevelVector.push_back("P");
			}
			else if (ThingToAdd.at(0) == 'C')
			{
				FrontLevelVector.push_back("C");
			}
			else //If program isnt sure whats in text position or there is a "." in position then adds empty space
			{
				FrontLevelVector.push_back(".");
			}
			ReadingPosition++;
		}
		ReadingPosition = ReadingPosition + 2;
	}

	SaveLevelFromText.close();

#pragma endregion

	//Load back level into vector
#pragma region LoadBackLevel

	SaveLevelFromText.open("Assets/Level1Back.txt");

	ThingToAdd = "";
	temp = "";
	ReadingPosition = 0;

	if (SaveLevelFromText.fail())
	{
		std::cout << "Failed to open text file, reset program." << std::endl;
		exit(0);
	}

	//Get level width. Get first line of level and count characters
	SaveLevelFromText.seekg(0) >> temp;

	m_LevelHeight = 12;

	//Goes through the level text file and adds that character into a vector which is used for drawing
	for (int j = 0; j < m_LevelHeight; j++)
	{
		for (int i = 0; i < m_LevelWidth; i++)
		{
			SaveLevelFromText.seekg(ReadingPosition) >> ThingToAdd;
			if (ThingToAdd.at(0) == 'G')
			{
				BackLevelVector.push_back("G");
			}
			else if (ThingToAdd.at(0) == 'D')
			{
				BackLevelVector.push_back("D");
			}
			else if (ThingToAdd.at(0) == 'S')
			{
				BackLevelVector.push_back("S");
			}
			else if (ThingToAdd.at(0) == 'P')
			{
				BackLevelVector.push_back("P");
			}
			else if (ThingToAdd.at(0) == 'C')
			{
				BackLevelVector.push_back("C");
			}
			else //If program isnt sure whats in text position or there is a "." in position then adds empty space
			{
				BackLevelVector.push_back(".");
			}
			ReadingPosition++;
		}
		ReadingPosition = ReadingPosition + 2;
	}
	SaveLevelFromText.close();

#pragma endregion

		
}

void Level::CreateTextures() //Creates all the textures before the level starts getting drawn
{
	//Grass block
	m_psurface = SDL_LoadBMP(GrassBlock.c_str());
	Uint32 colourKey = SDL_MapRGB(m_psurface->format, 255, 0, 255);
	SDL_SetColorKey(m_psurface, SDL_TRUE, colourKey);
	m_GrassTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_psurface);
	
	//Dirt block
	m_psurface = SDL_LoadBMP(DirtBlock.c_str());
	SDL_SetColorKey(m_psurface, SDL_TRUE, colourKey);
	m_DirtTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_psurface);
	
	//Stone block
	m_psurface = SDL_LoadBMP(StoneBlock.c_str());
	SDL_SetColorKey(m_psurface, SDL_TRUE, colourKey);
	m_StoneTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_psurface);
	
	//Player spawn flag
	m_psurface = SDL_LoadBMP(PlayerSpawn.c_str());
	SDL_SetColorKey(m_psurface, SDL_TRUE, colourKey);
	m_PlayerSpawnTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_psurface);
	
	//Coal block
	m_psurface = SDL_LoadBMP(CoalBlock.c_str());
	SDL_SetColorKey(m_psurface, SDL_TRUE, colourKey);
	m_CoalTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_psurface);

	//Back dirt block
	m_psurface = SDL_LoadBMP(BackDirtBlock.c_str());
	SDL_SetColorKey(m_psurface, SDL_TRUE, colourKey);
	m_BackDirtTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_psurface);

	//Back stone block
	m_psurface = SDL_LoadBMP(BackStoneBlock.c_str());
	SDL_SetColorKey(m_psurface, SDL_TRUE, colourKey);
	m_BackStoneTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_psurface);
	
	//Cleanup
	SDL_FreeSurface(m_psurface);
}



void Level::RenderLevel(int PlayerX, int PlayerY)
{
	//Find the top left position of the screen with regards to the players world position. The level isn't changed on the Y-axis so only the X is needed

	ViewPortX = PlayerX - (m_ScreenWidth/2);
	
	//Update offset based on how much the player moved (if they moved)
	m_Offset += (m_ViewPortPrevX - ViewPortX);

	//Makes it so m_Offset is always -64 and 64. Raises / reduces number if exceeds

	if (m_Offset > m_BlockWidth)
	{
		m_tempOffset = m_Offset - m_BlockWidth;
		m_Offset = 0;
		m_Offset += m_tempOffset;
		VectorPos--;
	}
	else if (m_Offset < -m_BlockWidth)
	{
		m_tempOffset = m_Offset + m_BlockWidth;
		m_Offset = 0;
		m_Offset += m_tempOffset;
		VectorPos++;
	}
	
	//Draw back level onto screen
#pragma region DrawBackLevel

	//Set all the variables used for drawing level

	m_XDrawTo += m_Offset;
	SavedXDrawTo = m_XDrawTo;
	m_DrawingPosition = VectorPos;

	//Loop to draw the front level

	for (int i = VectorPos; i < VectorPos + MaxBlockHeight; i++)
	{
		for (int j = VectorPos; j < VectorPos + MaxBlockWidth; j++)
		{
			if (BackLevelVector.at(m_DrawingPosition) == "G") //Grass block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_GrassTexture);
			}
			else if (BackLevelVector.at(m_DrawingPosition) == "D") //Dirt block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_BackDirtTexture);
			}
			else if (BackLevelVector.at(m_DrawingPosition) == "S") //Stone block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_BackStoneTexture);
			}
			else if (BackLevelVector.at(m_DrawingPosition) == "P") //Player spawn 
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_PlayerSpawnTexture);
			}
			else if (BackLevelVector.at(m_DrawingPosition) == "C") //Coal Block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_CoalTexture);
			}
			else //Empty space
			{

			}

			m_XDrawTo += m_BlockWidth;
			m_DrawingPosition++;
		}

		//70 goes to the next block that needs to be renderered on the next line. will break if the rows are made bigger in level text file 
		m_DrawingPosition += 70;

		m_XDrawTo = SavedXDrawTo;
		m_YDrawTo = m_YDrawTo + m_BlockHeight;
	}

	//Reset everything ready for next render of level

	m_ViewPortPrevX = ViewPortX;
	m_XDrawTo = -m_BlockWidth;
	m_YDrawTo = 0;

#pragma endregion

	//Draw front level onto screen
#pragma region DrawFrontLevel

	//Set all the variables used for drawing level

	m_XDrawTo += m_Offset;
	SavedXDrawTo = m_XDrawTo;
	m_DrawingPosition = VectorPos;

	//Loop to draw the front level

	for (int i = VectorPos; i < VectorPos + MaxBlockHeight; i++)
	{
		for (int j = VectorPos; j < VectorPos + MaxBlockWidth; j++)
		{
			if (FrontLevelVector.at(m_DrawingPosition) == "G") //Grass block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_GrassTexture);
			}
			else if (FrontLevelVector.at(m_DrawingPosition) == "D") //Dirt block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_DirtTexture);
			}
			else if (FrontLevelVector.at(m_DrawingPosition) == "S") //Stone block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_StoneTexture);
			}
			else if (FrontLevelVector.at(m_DrawingPosition) == "P") //Player spawn 
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_PlayerSpawnTexture);
			}
			else if (FrontLevelVector.at(m_DrawingPosition) == "C") //Coal Block
			{
				DrawBlockOnPosition(m_XDrawTo, m_YDrawTo, m_CoalTexture);
			}
			else //Empty space
			{

			}
			
			m_XDrawTo += m_BlockWidth;
			m_DrawingPosition++;
		}

		//70 goes to the next block that needs to be renderered on the next line. will break if the rows are made bigger in level text file 
		m_DrawingPosition += 70;
		
		m_XDrawTo = SavedXDrawTo;
		m_YDrawTo = m_YDrawTo + m_BlockHeight;
	}

	//Reset everything ready for next render of level

	m_ViewPortPrevX = ViewPortX;
	m_XDrawTo = -m_BlockWidth;
	m_YDrawTo = 0;

#pragma endregion

}

void Level::DrawBlockOnPosition(int X, int Y, SDL_Texture* texture)
{
	//Draw the block
	SDL_Rect destRect = { X,Y,m_BlockWidth,m_BlockHeight };
	SDL_RenderCopy(m_pRenderer, texture, NULL, &destRect);
}



bool Level::IsWall(int TopX, int TopY, int BotX, int BotY) 
{
	//Find where the player is within the level by using the cords in the functions parameter
	//The X cords are adjusted for the offset used to draw the level and the players viewport
	TopX -= ((ViewPortX + m_Offset) - m_BlockWidth);
	BotX -= ((ViewPortX + m_Offset) - m_BlockWidth);

	//ColVectorPos is the top left block within the vector
	ColXVectorPos = 0;
	ColYVectorPos = 0;
	ColVectorPos = VectorPos;

	//As the top left block is known we can find out where the player is within the vector
	//Find out how many times TopX goes into 64 (64 equals the size of a block)
	while (TopX > m_BlockWidth)
	{
		TopX -= m_BlockWidth;
		ColXVectorPos++;
	}

	//Same for TopY
	while (TopY > m_BlockWidth)
	{
		TopY -= m_BlockWidth;
		ColYVectorPos += m_LevelWidth; 
	}

	//Can add ColXVector & and ColYVector to ColVectorPos to find out exactly where this creature is
	ColVectorPos += ColXVectorPos + ColYVectorPos;
	
	//if position doesnt equal "." then there is something there so return true (meaning there's a wall there)
	if (FrontLevelVector.at(ColVectorPos) != "." && FrontLevelVector.at(ColVectorPos) != "P")
	{
		return true;
	}

	//If TopX&Y didn't hit anything then BotX&Y will be checked

	ColXVectorPos = 0;
	ColYVectorPos = 0;
	ColVectorPos = VectorPos;


	while (BotX > m_BlockWidth)
	{
		BotX -= m_BlockWidth;
		ColXVectorPos++;
	}

	while (BotY > m_BlockWidth)
	{
		BotY -= m_BlockWidth;
		ColYVectorPos += m_LevelWidth;
	}

	ColVectorPos += ColXVectorPos + ColYVectorPos;

	if (FrontLevelVector.at(ColVectorPos) != "." && FrontLevelVector.at(ColVectorPos) != "P")
	{
		return true;
	}
	return false;
}

int Level::GetViewPortX()
{
	return ViewPortX;
}



