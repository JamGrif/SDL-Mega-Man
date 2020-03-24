#include "LevelManager.h"

LevelManager::LevelManager(Renderer* renderer, EntityManager* entitymanager)
{

	m_prenderer = renderer;

	m_pentitymanager = entitymanager;

	//By default, the program loads level 1 first
	LoadLevel();
	
}

LevelManager::~LevelManager()
{
	LevelVector.clear();

}


void LevelManager::LoadLevel()
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

	m_LevelHeight = 15;

	ThingToAdd = "";
	temp = "";
	ReadingPosition = 0;

	//Goes through the level text file and adds that character into a vector which is used for drawing
	for (int j = 0; j < m_LevelHeight; j++)
	{
		for (int i = 0; i < m_LevelWidth; i++)
		{
			SaveLevelFromText.seekg(ReadingPosition) >> ThingToAdd;
			if (ThingToAdd.at(0) == '1')
			{
				LevelVector.push_back("1");
			}
			else if (ThingToAdd.at(0) == '2')
			{
				LevelVector.push_back("2");
			}
			else if (ThingToAdd.at(0) == '3')
			{
				LevelVector.push_back("3");
			}
			else if (ThingToAdd.at(0) == '4')
			{
				LevelVector.push_back("4");
			}
			else if (ThingToAdd.at(0) == '5')
			{
				LevelVector.push_back("5");
			}
			else if (ThingToAdd.at(0) == '6')
			{
				LevelVector.push_back("6");
			}
			else if (ThingToAdd.at(0) == '7')
			{
				LevelVector.push_back("7");
			}
			else if (ThingToAdd.at(0) == '8')
			{
				LevelVector.push_back("8");
			}
			else if (ThingToAdd.at(0) == '9')
			{
				LevelVector.push_back("9");
			}
			else if (ThingToAdd.at(0) == 'B')
			{
				LevelVector.push_back("B");
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

void LevelManager::UnloadLevel()
{
}


void LevelManager::RenderLevel()
{
	//Loop to draw the level
	for (int i = 0; i < m_LevelHeight; i++)
	{
		for (int j = 0; j < m_LevelWidth; j++)
		{
			if (LevelVector.at(m_DrawingPosition) == "1") //Grass block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/1.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/1.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "2") //Dirt block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/2.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/2.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "3") //Stone block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/3.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/3.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "4") //Player spawn 
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/4.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/4.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "5") //Coal Block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/5.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/5.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "6") //Coal Block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/6.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/6.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "7") //Coal Block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/7.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/7.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "8") //Coal Block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/8.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/8.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "9") //Coal Block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/9.bmp");
				m_pentitymanager->CreateLevelBlock(m_XDrawTo, m_YDrawTo, "Assets/9.bmp");
			}
			else if (LevelVector.at(m_DrawingPosition) == "B") //Coal Block
			{
				//CreateBlock(m_XDrawTo, m_YDrawTo, "Assets/9.bmp");
				m_pentitymanager->CreateBunbyHeli(m_XDrawTo, m_YDrawTo);
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
