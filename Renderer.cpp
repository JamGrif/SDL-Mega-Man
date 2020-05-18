#include "Renderer.h"

namespace NSRenderer
{

	//Layers used for drawing order. Starts from top 
	std::vector<Sprite*> SkyLayer;
	std::vector<Sprite*> BackLayer;
	std::vector<Sprite*> PlayLayer;
	std::vector<Sprite*> FrontLayer;
	std::vector<Sprite*> UILayer;

	Sprite* Renderer::CreateSprite(int LayerNum)
	{
		Sprite* sprite = new Sprite(m_Renderer);
		switch (LayerNum) 
		{
		case SkyL:
			SkyLayer.push_back(sprite);
			break;
		case BackL:
			BackLayer.push_back(sprite);
			break;
		case PlayL:
			PlayLayer.push_back(sprite);
			break;
		case FrontL:
			FrontLayer.push_back(sprite);
			break;
		case UIL:
			UILayer.push_back(sprite);
			break;
		default:
			PlayLayer.push_back(sprite); //number outside 0-4 results in sprite being put into playlayer
			break;
		}
		return sprite;
	}

	Sprite::Sprite(SDL_Renderer* renderer)
	{
		std::cout << "Created Sprite" << std::endl;
		m_pRenderer = renderer;

		SetSprite("Assets/MissingPic.bmp");

	}

	void Sprite::SetSprite(std::string filename)
	{
		SDL_FreeSurface(m_pbitmapSurface);
		SDL_DestroyTexture(m_pbitmapTexture);

		//Create the bitmap surface
		m_pbitmapSurface = SDL_LoadBMP(filename.c_str()); //loads bitmap from file into a member variable

		//CurrentPicture = filename;

		if (!m_pbitmapSurface)
		{
			//bitmap failed to load
			printf("Surface for bitmap '%s' not loaded! \n", filename.c_str());
			printf("%s\n", SDL_GetError());
		}
		else
		{
			//if we are to use transparency, going to assume
			//the colour key is magenta
			Uint32 colourKey = SDL_MapRGB(m_pbitmapSurface->format, 255, 0, 255);
			SDL_SetColorKey(m_pbitmapSurface, SDL_TRUE, colourKey);

			//create the texture
			m_pbitmapTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pbitmapSurface); //Converting raw pixels to something more efficient. Copies pixel data from one memory location to another
			if (!m_pbitmapTexture)
			{
				//texture failed to load
				printf("Texture for bitmap '%s' not loaded! a\n", filename.c_str());
				printf("%s\n", SDL_GetError());
			}
		}
	}

	void Sprite::Draw(SDL_Renderer* renderer, float CameraX, float CameraY)
	{
		if (m_pbitmapTexture)
		{
			SDL_Rect destRect = { Position.x - CameraX, Position.y - CameraY, m_pbitmapSurface->w, m_pbitmapSurface->h }; //Where on screen bitmap is drawn to and how big it will appear
			SDL_RenderCopy(renderer, m_pbitmapTexture, NULL, &destRect);
		}
	}

	void Sprite::SetX(float x)
	{
		Position.x = x;
	}

	void Sprite::SetY(float y)
	{
		Position.y = y;
	}

	float Sprite::GetX()
	{
		return Position.x;
	}

	float Sprite::GetY()
	{
		return Position.y;
	}

	Renderer::Renderer(Camera* camera)
	{
		std::cout << "Created Renderer" << std::endl;
		m_pcamera = camera;

		m_Window = nullptr;
		m_Renderer = nullptr;

		//Start up
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();

		//Create the window
		//Title, initial x position, initial y position, width in pixels, height in pixels, window behaviour flags
		m_Window = SDL_CreateWindow("Mega Man", 200, 200, m_pcamera->GetScreenWidth(), m_pcamera->GetScreenHeight(), 0);

		if (!m_Window)
		{
			std::cout << ("WINDOW initialisation failed: %s\n", SDL_GetError());
			std::cout << ("Press any key to continue\n");
			//getchar();
			return;
		}

		//Create the renderer
		//link renderer to newly created window,index rendering driver, renderer behaviour flags
		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

		if (!m_Renderer)
		{
			printf("RENDERER initialisation failed: %s\n", SDL_GetError());
			printf("Press any key to continue\n");
			//getchar();
			return;
		}

		//Application icon
		std::string Icon = "Assets/Icon.bmp";
		SDL_Surface* m_IconSurface = SDL_LoadBMP(Icon.c_str());
		Uint32 colourKey = SDL_MapRGB(m_IconSurface->format, 255, 0, 255);
		SDL_SetColorKey(m_IconSurface, SDL_TRUE, colourKey);
		SDL_SetWindowIcon(m_Window, m_IconSurface);
		SDL_FreeSurface(m_IconSurface);

		//Set background colour
		SDL_SetRenderDrawColor(m_Renderer, 101, 141, 209, 255);

	}

	Renderer::~Renderer()
	{

	}

	void Renderer::RenderLoop()
	{
		float x = m_pcamera->GetCameraOffX();
		float y = m_pcamera->GetCameraOffY();

		//Loop through layers drawing all the sprites
		int xd = 0;
		for (Sprite* sprite : SkyLayer)
		{
			sprite->Draw(m_Renderer, x, y);
			xd++;
		}
		for (Sprite* sprite : BackLayer)
		{
			sprite->Draw(m_Renderer, x, y);
			xd++;
		}
		for (Sprite* sprite : PlayLayer)
		{
			sprite->Draw(m_Renderer, x, y);
			xd++;
		}
		for (Sprite* sprite : FrontLayer)
		{
			sprite->Draw(m_Renderer, x, y);
			xd++;
		}
		for (Sprite* sprite : UILayer)
		{
			sprite->Draw(m_Renderer, x, y);
			xd++;
		}
		//std::cout << xd << " entites were drawn." << std::endl;
		
		//Show what was drawn
		SDL_RenderPresent(m_Renderer);

		//Wipe the display 
		SDL_RenderClear(m_Renderer);

	}

	SDL_Renderer* Renderer::GetRenderer()
	{
		return m_Renderer;
	}

	
}
