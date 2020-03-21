#include "Camera.h"

Camera::Camera(int ScreenWidth, int ScreenHeight)
{

	//m_pplayer = player;

	m_ScreenWidth = ScreenWidth;
	m_ScreenHeight = ScreenHeight;

}

Camera::~Camera()
{
}

int Camera::GetScreenWidth()
{
	return m_ScreenWidth;
}

int Camera::GetScreenHeight()
{
	return m_ScreenHeight;
}

void Camera::CenterCamera(float PlayerX, float PlayerY)
{
	CameraPos.x = (PlayerX + 48 / 2) - m_ScreenWidth / 2;
	CameraPos.y = (PlayerY + 48 / 2) - m_ScreenHeight / 2;
}

float Camera::GetCameraOffX()
{
	return CameraPos.x;
}

float Camera::GetCameraOffY()
{
	return CameraPos.y;
}
