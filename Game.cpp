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
	UIObj = new UI(RendererObj);

	//Create level manager
	LevelObj = new LevelManager(RendererObj);

	//Create entity manager
	EMObj = new EntityManager(RendererObj, CameraObj, InputObj, LevelObj);

	//Create audio manager
	AudioObj = new Audio;

}

Game::~Game()
{
	if (AudioObj)
	{
		std::cout << "Deleted AudioObj" << std::endl;
		delete AudioObj;
		AudioObj = nullptr;
	}

	if (EMObj)
	{
		std::cout << "Deleted EMObj" << std::endl;
		delete EMObj;
		EMObj = nullptr;
	}

	if (LevelObj)
	{
		std::cout << "Deleted LevelObj" << std::endl;
		delete LevelObj;
		LevelObj = nullptr;
	}

	if (UIObj)
	{
		std::cout << "Deleted UIObj" << std::endl;
		delete UIObj;
		UIObj = nullptr;
	}

	if (InputObj)
	{
		std::cout << "Deleted InputObj" << std::endl;
		delete InputObj;
		InputObj = nullptr;
	}

	if (RendererObj)
	{
		std::cout << "Deleted RendererObj" << std::endl;
		delete RendererObj;
		RendererObj = nullptr;
	}

	if (CameraObj)
	{
		std::cout << "Deleted CameraObj" << std::endl;
		delete CameraObj;
		CameraObj = nullptr;
	}

	
}

void Game::GameLoop()
{
	EMObj->CreatePlayer(75, 135);
	LevelObj->RenderLevel();
	while (!InputObj->KeyIsPressed(KEY_ESCAPE) && !InputObj->ControllerIsPressed(BUTTON_B))
	{
		//Start frame timing
		Uint32 StartTick = SDL_GetTicks();
		Uint64 StartPerf = SDL_GetPerformanceCounter();

		//Check for input
		InputObj->Update();

		//Update entities
		EMObj->UpdateEntities();
		
		//Render scene
		RendererObj->RenderLoop();

		//Display UI
		UIObj->PresentUi();

		//End frame timing
		Uint32 EndTicks = SDL_GetTicks();
		Uint64 EndPerf = SDL_GetPerformanceCounter();
		Uint64 FramePerf = EndPerf - StartPerf;
		float FrameTime = 1.0f/((EndTicks - StartTick) / 1000.0f);
		UIObj->SetFPS(FrameTime);
		SDL_Delay(20);
		
	}

	std::cout << "Game ended" << std::endl;

}

void Game::CheckKeyPressed()
{
	InputObj->Update();
	
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





