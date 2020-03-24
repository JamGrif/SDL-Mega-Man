#include "Game.h"

Game::Game()
{
	//Create the camera
	CameraObj = new Camera(m_ScreenWidth, m_ScreenHeight);

	//Create renderer
	RendererObj = new Renderer(CameraObj);

	//Create input manager
	InputObj = new Input();

	//Create UI
	//m_ui = new UI(m_Renderer);

	//Create entity manager
	EMObj = new EntityManager(RendererObj, CameraObj);

	//Create level manager
	LevelObj = new LevelManager(RendererObj, EMObj);

	//Create the Player
	//PlayerObj = new Player(CameraObj, RendererObj, 2);


}

Game::~Game()
{
	/*if (PlayerObj)
	{
		delete PlayerObj;
		PlayerObj = nullptr;
	}*/

	if (LevelObj)
	{
		delete LevelObj;
		LevelObj = nullptr;
	}

	if (UIObj)
	{
		delete UIObj;
		UIObj = nullptr;
	}

	if (InputObj)
	{
		delete InputObj;
		InputObj = nullptr;
	}

	if (RendererObj)
	{
		delete RendererObj;
		RendererObj = nullptr;
	}

	if (CameraObj)
	{
		delete CameraObj;
		CameraObj = nullptr;
	}

	//Destroy in reverse order they were created
	/*if (m_Renderer) 
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	if (m_Window) 
	{
		SDL_DestroyWindow(m_Window);
	}*/
}

void Game::GameLoop()
{
	//level rendered once here -------------
	EMObj->CreatePlayer(69, 69);
	LevelObj->RenderLevel();
	while (true) //Game ends if player collects 5 coins and reaches end flag
	{
		//Check for input
		CheckKeyPressed();

		//PlayerObj->Update();

		EMObj->UpdateEntities();

		//m_ui->PresentUi(m_Player->GetCoinsCollected());
		
		//Render stuff
		//CameraObj->CenterCamera();
		RendererObj->RenderLoop();
		SDL_Delay(20);

	}

	std::cout << "Game ended" << std::endl;

}

void Game::CheckKeyPressed()
{
	InputObj->Update();
	//Keyboard
	if (InputObj->KeyIsPressed(KEY_D))
	{
		//PlayerObj->Move('r');
	}
	if (InputObj->KeyIsPressed(KEY_A))
	{
		//PlayerObj->Move('l');
	}
	if (InputObj->KeyIsPressed(KEY_W))
	{
		//PlayerObj->Move('u');
	}
	if (InputObj->KeyIsPressed(KEY_S))
	{
		//PlayerObj->Move('d');
	}
	if (InputObj->KeyIsPressed(KEY_SPACE))
	{
		//PlayerObj->Move('j');
		//std::cout << "Space key is pressed!" << std::endl;
	}
	if (InputObj->KeyIsPressed(KEY_R))
	{

	}
	if (InputObj->KeyIsPressed(KEY_1))
	{
	}
	if (InputObj->KeyIsPressed(KEY_2))
	{
	}
	//Mouse
	if (InputObj->MouseIsPressed(MOUSE_LEFT))
	{
		std::cout << "Mouse X position is " << InputObj->GetMouseX() << ". Mouse Y position is " << InputObj->GetMouseY() << "." << std::endl;
	}
	if (InputObj->MouseIsPressed(MOUSE_RIGHT))
	{
		std::cout << "Right mouse is pressed!" << std::endl;
	}
	if (InputObj->MouseIsPressed(MOUSE_MIDDLE))
	{
		std::cout << "Middle mouse is pressed!" << std::endl;
	}


}





