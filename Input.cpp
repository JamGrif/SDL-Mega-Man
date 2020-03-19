#include "Input.h"

Input::Input()
{
	for (int i = 0; i < SIZE_OF_KEYS_PRESSED_ENUM; i++) { m_keysPressed[i] = NULL; }
	for (int i = 0; i < SIZE_OF_MOUSE_PRESSED_ENUM; i++) { m_mousePressed[i] = NULL; }
}

Input::~Input()
{

}

void Input::Update()
{
	//loop through all the events in the event list

	while (SDL_PollEvent(&m_InputEvent) != NULL)
	{

		//first check for key down
		if (m_InputEvent.type == SDL_KEYDOWN) {
			SDL_Keycode keyPressed = m_InputEvent.key.keysym.sym;
			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				m_keysPressed[KEY_ESCAPE] = true;
				break;
			case SDLK_a:
				m_keysPressed[KEY_A] = true;
				break;
			case SDLK_d:
				m_keysPressed[KEY_D] = true;
				break;
			case SDLK_r:
				m_keysPressed[KEY_R] = true;
				break;
			case SDLK_SPACE:
				m_keysPressed[KEY_SPACE] = true;
				break;
			case SDLK_w:
				m_keysPressed[KEY_W] = true;
				break;
			case SDLK_s:
				m_keysPressed[KEY_S] = true;
				break;
			case SDLK_1:
				m_keysPressed[KEY_1] = true;
				break;
			case SDLK_2:
				m_keysPressed[KEY_2] = true;
				break;
			}
		}

		//second check for key up
		else if (m_InputEvent.type == SDL_KEYUP)
		{
			SDL_Keycode keyPressed = m_InputEvent.key.keysym.sym;
			switch (keyPressed)
			{
			case SDLK_a:
				m_keysPressed[KEY_A] = false;
				break;
			case SDLK_d:
				m_keysPressed[KEY_D] = false;
				break;
			case SDLK_r:
				m_keysPressed[KEY_R] = false;
				break;
			case SDLK_SPACE:
				m_keysPressed[KEY_SPACE] = false;
				break;
			case SDLK_w:
				m_keysPressed[KEY_W] = false;
				break;
			case SDLK_s:
				m_keysPressed[KEY_S] = false;
				break;
			case SDLK_1:
				m_keysPressed[KEY_1] = false;
				break;
			case SDLK_2:
				m_keysPressed[KEY_2] = false;
				break;
			}
		}

		//third check for mouse down
		else if (m_InputEvent.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_Keycode keyPressed = m_InputEvent.button.button;
			switch (keyPressed)
			{
			case SDL_BUTTON_LEFT:
				m_mousePressed[MOUSE_LEFT] = true;
				break;
			case SDL_BUTTON_RIGHT:
				m_mousePressed[MOUSE_RIGHT] = true;
				break;
			case SDL_BUTTON_MIDDLE:
				m_mousePressed[MOUSE_MIDDLE] = true;
				break;
			}
		}

		//fourth check for mouse up
		else if (m_InputEvent.type == SDL_MOUSEBUTTONUP)
		{
			SDL_Keycode keyPressed = m_InputEvent.button.button;

			switch (keyPressed)
			{
			case SDL_BUTTON_LEFT:
				m_mousePressed[MOUSE_LEFT] = false;
				break;
			case SDL_BUTTON_RIGHT:
				m_mousePressed[MOUSE_RIGHT] = false;
				break;
			case SDL_BUTTON_MIDDLE:
				m_mousePressed[MOUSE_MIDDLE] = false;
				break;
			}
		}
		//fifth check for mouse motion
		else if (m_InputEvent.type == SDL_MOUSEMOTION) 
		{
			m_XMouse = m_InputEvent.motion.x;
			m_YMouse = m_InputEvent.motion.y;
		}
	}
}

bool Input::KeyIsPressed(KEYS_PRESSED_LIST key)
{
	return m_keysPressed[key];
}

/*void Input::KeyIsNotPressed(KEYS_PRESSED_LIST &key)
{
	m_keysPressed[key] = false;
}*/

bool Input::MouseIsPressed(MOUSE_PRESSED_LIST mouse)
{
	return m_mousePressed[mouse];
}

void Input::MouseIsNotPressed(MOUSE_PRESSED_LIST &mouse)
{
	m_mousePressed[mouse] = false;
}

int Input::GetMouseX()
{
	return m_XMouse;
}

int Input::GetMouseY()
{
	return m_YMouse;
}
