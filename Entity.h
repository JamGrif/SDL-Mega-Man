#pragma once
#include "SDL.h"
#include "SDL_render.h"
#include <iostream>
#include <vector>
#include <string>

#include "Renderer.h"
using namespace NSRenderer;

class Entity
{
public:
	Entity(Renderer* renderer, int LayerNum = 2);
	~Entity();

	virtual void Update() = 0;

	void UpdateCollisionPosition();

	bool GetMoveable();

	float GetTopCol();
	float GetBotCol();
	float GetLefCol();
	float GetRigCol();

protected:
	
	//Renderer
	Renderer* m_prenderer;

	Sprite* m_object;

	//Collision
	float m_Top;
	float m_Bottom;
	float m_Left;
	float m_Right;

	//Size of Entity
	int m_Width = 0;
	int m_Height = 0;

	//Entities that are moveable will check for collision with all other entities
	bool m_Moveable = false;

};

