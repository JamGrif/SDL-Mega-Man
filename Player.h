#pragma once
#include "Entity.h"
#include "Camera.h"
#include "Input.h"
class Player :
	public Entity
{
public:
	Player(Camera* camera, Renderer* renderer, Input* input, float X, float Y, int LayerNum);
	~Player();

	void Update();

	virtual void OnCollision(Entity* entity);

private:

	Input* m_pinput;
	Camera* m_pcamera;

	int speed = 5;

};

