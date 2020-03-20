#include "Renderer.h"

namespace NSRenderer
{
	std::vector<Sprite*> sprites;

	Sprite* Renderer::CreateSprite()
	{
		Sprite* sprite = new Sprite(m_Renderer);
		sprites.push_back(sprite);
		return sprite;
		
	}

	Sprite::Sprite(SDL_Renderer* renderer)
	{
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

	void Sprite::Draw(SDL_Renderer* renderer)
	{
		if (m_pbitmapTexture)
		{
			SDL_Rect destRect = { Position.x, Position.y, m_pbitmapSurface->w, m_pbitmapSurface->h }; //Where on screen bitmap is drawn to and how big it will appear
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

	Renderer::Renderer(int screenwidth, int screenheight)
	{
		m_Window = nullptr;
		m_Renderer = nullptr;

		//Start up
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();

		//Create the window
		//Title, initial x position, initial y position, width in pixels, height in pixels, window behaviour flags
		m_Window = SDL_CreateWindow("Mega Man", 200, 200, screenwidth, screenheight, 0);

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
		SDL_SetWindowIcon(m_Window, m_IconSurface);
		SDL_FreeSurface(m_IconSurface);

	}

	void Renderer::RenderLoop()
	{
		//Loop through meshes drawing them all
		for (Sprite* sprite : sprites)
		{
			sprite->Draw(m_Renderer);
		}

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