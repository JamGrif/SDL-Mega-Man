#pragma once
#include <iostream>
class Camera
{
public:
	Camera(int ScreenWidth, int ScreenHeight);
	~Camera();

	int GetScreenWidth();
	int GetScreenHeight();

	void CenterCamera(float PlayerX, float PlayerY);

	float GetCameraOffX();
	float GetCameraOffY();

private:

	//Player* m_pplayer;

	int m_ScreenWidth = 0;
	int m_ScreenHeight = 0;

	struct Vector2 { float x; float y; };
	Vector2 CameraPos{ 0,0 };
};

