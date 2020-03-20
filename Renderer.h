#pragma once
#include <SDL.h>
#include "SDL_ttf.h"

#include <vector>
#include <iostream>

namespace NSRenderer
{

	class Mesh 
	{
	public:

		SDL_Surface* m_pbitmapSurface;
		SDL_Texture* m_pbitmapTexture;
			
		void SetSprite(std::string filename);

		void Draw();

		void SetX(float x);
		void SetY(float y);

		float GetX();
		float GetY();

	private:
		struct Vector2 { float x; float y; };
		Vector2 Position{ 0,0 };

	};

	class Renderer
	{
	public:

		Renderer(int screenwidth, int screenheight);

		void RenderLoop();

		Mesh* CreateMesh();

	private:


		SDL_Renderer* m_Renderer;
		SDL_Window* m_Window;

	};

}

