#pragma once
#include <SDL.h>
#include "SDL_ttf.h"

#include "Camera.h"

#include <list>
#include <vector>
#include <iostream>




namespace NSRenderer
{
	enum Layer { SkyL, BackL, PlayL, FrontL, UIL };
	class Sprite 
	{
	public:
		Sprite(SDL_Renderer* renderer);
		~Sprite();

		void SetSprite(std::string filename);

		void Draw(SDL_Renderer* renderer, float CameraX, float CameraY);

		void SetX(float x);
		void SetY(float y);

		float GetX();
		float GetY();

		SDL_Surface* m_pbitmapSurface;
		SDL_Texture* m_pbitmapTexture;

	private:

		//Pointer to main renderer
		SDL_Renderer* m_pRenderer;

		struct Vector2 { float x; float y; };
		Vector2 Position{ 0,0 };

	};

	class Renderer
	{
	public:
		Renderer(Camera* camera);
		~Renderer();

		void RenderLoop();

		SDL_Renderer* GetRenderer();

		Sprite* CreateSprite(int LayerNum);

	private:

		//enum Layer { SkyL, BackL, PlayL, FrontL, UIL };

		Camera* m_pcamera;

		SDL_Renderer* m_Renderer;
		SDL_Window* m_Window;

	};

}

