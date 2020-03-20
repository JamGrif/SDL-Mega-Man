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
		Mesh(SDL_Renderer* renderer);
		~Mesh();

		void SetSprite(std::string filename);

		void Draw(SDL_Renderer* renderer);

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
		Renderer(int screenwidth, int screenheight);
		~Renderer();

		void RenderLoop();

		SDL_Renderer* GetRenderer();

		Mesh* CreateMesh();

	private:

		SDL_Renderer* m_Renderer;
		SDL_Window* m_Window;

	};

}

