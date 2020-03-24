#pragma once
#include <SDL.h>
//#include <iostream>
enum KEYS_PRESSED_LIST 
{
	KEY_ESCAPE, KEY_A, KEY_D, KEY_R, KEY_SPACE, KEY_W, KEY_S, KEY_1, KEY_2, SIZE_OF_KEYS_PRESSED_ENUM
};
enum MOUSE_PRESSED_LIST 
{
	MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE, SIZE_OF_MOUSE_PRESSED_ENUM
};
class Input
{
public:
	Input();
	~Input();

	void Update();

	bool KeyIsPressed(KEYS_PRESSED_LIST key);
	bool MouseIsPressed(MOUSE_PRESSED_LIST mouse);
	
	int GetMouseX();
	int GetMouseY();
	
private:
	int m_XMouse = 0;
	int m_YMouse = 0;

	KEYS_PRESSED_LIST KeyList;
	MOUSE_PRESSED_LIST MouseList;

	SDL_Event m_InputEvent;
	
	bool m_keysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
	bool m_mousePressed[SIZE_OF_MOUSE_PRESSED_ENUM];
};

