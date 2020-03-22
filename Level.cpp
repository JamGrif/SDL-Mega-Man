#include "Level.h"

Level::Level(Renderer* renderer)
{
	//Screen resoultion fits a width of 20 blocks and a height of 12 blocks
	m_prenderer = renderer;

	//By default, the program loads level 1 first
	LoadLevel();
	
}

Level::~Level()
{
	LevelVector.clear();

}


void Level::LoadLevel()
{
	//Load level into vector
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

	ThingToAdd = "";
	temp = "";
	ReadingPosition = 0;

	//Goes through the level text file and adds that character into a vector which is used for drawing
	for (int j = 0; j < m_LevelHeight; j++)
	{
		for (int i = 0; i < m_LevelWidth; i++)
		{
			SaveLevelFromText.seekg(ReadingPosition) >> ThingToAdd;
			if (ThingToAdd.at(0) == 'G')
			{
				LevelVector.push_back("G");
			}
			else if (ThingToAdd.at(0) == 'D')
			{
				LevelVector.push_back("D");
			}
			else if (ThingToAdd.at(0) == 'S')
			{
				LevelVector.push_back("S");
			}
			else if (ThingToAdd.at(0) == 'P')
			{
				LevelVector.push_back("P");
			}
			else if (ThingToAdd.at(0) == 'C')
			{
				LevelVector.push_back("C");
			}
			else //If game isn't sure whats in text position or there is a "." in position then adds empty space
			{
				LevelVector.push_back(".");
			}
			ReadingPosition++;
		}
		ReadingPosition = ReadingPosition + 2;
	}

	SaveLevelFromText.close();

}

void Level::UnloadLevel()
{
}

void Level::CreateBlock(float X, float Y, const char* AssetName)
{
	std::cout << "adding to level list with x cord of " << X << " and y cord of " << Y << std::endl;
	ListOfBlocks.push_back(levelblock = new LevelBlock(m_prenderer, X, Y, AssetName));
}

/*void Level::DeleteBlocks()
{
	for (LevelBlock* levelblock : ListOfBlocks) 
	{
		delete levelblock;
		levelblock = nullptr;
	}
}*/



void Level::RenderLevel()
{
	//Loop to draw the level

	for (int i = 0; i < m_LevelHeight; i++)
	{
		for (int j = 0; j < m_LevelWidth; j++)
		{
			if (LevelVector.at(m_DrawingPosition) == "G") //Grass block
			{
				CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/GrassBlock.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "D") //Dirt block
			{
				CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/DirtBlock.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "S") //Stone block
			{
				CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/StoneBlock.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "P") //Player spawn 
			{
				CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/PlayerSpawn.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "C") //Coal Block
			{
				CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/CoalBlock.bmp");
			}
			else //Empty space
			{

			}
			
			m_XDrawTo += m_BlockWidth;
			m_DrawingPosition++;
		}

		//70 goes to the next block that needs to be renderered on the next line. will break if the rows are made bigger in level text file 
		
		m_XDrawTo = SavedXDrawTo;
		m_YDrawTo += m_BlockHeight;
	}

}

