#include "Input.h"

Input::Input()
{
	std::cout << "Created InputManager" << std::endl;
	SDL_Init(SDL_INIT_JOYSTICK);
	SDL_Init(SDL_INIT_GAMECONTROLLER);

	for (int i = 0; i < SIZE_OF_KEYS_PRESSED_ENUM; i++) { m_keysPressed[i] = NULL; }
	for (int i = 0; i < SIZE_OF_MOUSE_PRESSED_ENUM; i++) { m_mousePressed[i] = NULL; }

	//Check if controller is plugged in
	if (SDL_NumJoysticks() < 1) 
	{
		ControllerActive = false;
		std::cout << "No controller detected" << std::endl;
	}
	else 
	{
		ControllerActive = true;
		std::cout << "Controller detected" << std::endl;

		Controller = SDL_JoystickOpen(0);
	}
}

Input::~Input()
{
	//Close controller interface
	SDL_JoystickClose(Controller);
	Controller = NULL;
}

void Input::Update()
{
	SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	SDL_Init(SDL_INIT_GAMECONTROLLER);

	//Check if controller is plugged in
	if (ControllerActive == true && SDL_NumJoysticks() < 1)
	{
		ControllerActive = false;
		std::cout << "Controller disconnected" << std::endl;
	}
	else if (ControllerActive == false && SDL_NumJoysticks() > 0)
	{
		ControllerActive = true;
		std::cout << "Controller connected" << std::endl;
	}
	//Loop through all the events in the event list
	while (SDL_PollEvent(&m_InputEvent) != NULL)
	{
		//Check for key down
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

		//Check for key up
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

		//Check for mouse down
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

		//Check for mouse up
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

		//Check for mouse motion
		else if (m_InputEvent.type == SDL_MOUSEMOTION)
		{
			m_XMouse = m_InputEvent.motion.x;
			m_YMouse = m_InputEvent.motion.y;

		}

		//Check for controller down
		else if (m_InputEvent.type == SDL_JOYBUTTONDOWN) 
		{
			SDL_Keycode keyPressed = m_InputEvent.cbutton.button;
			switch (keyPressed) 
			{
			case SDL_CONTROLLER_BUTTON_A:
				m_controllerPressed[BUTTON_A] = true;
				break;
			case SDL_CONTROLLER_BUTTON_B:
				m_controllerPressed[BUTTON_B] = true;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				m_controllerPressed[DPAD_LEFT] = true;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				m_controllerPressed[DPAD_RIGHT] = true;
				break;
			}
		}

		//Check for controller up
		else if (m_InputEvent.type == SDL_JOYBUTTONUP)
		{
			SDL_Keycode keyPressed = m_InputEvent.cbutton.button;
			switch (keyPressed)
			{
			case SDL_CONTROLLER_BUTTON_A:
				m_controllerPressed[BUTTON_A] = false;
				break;
			case SDL_CONTROLLER_BUTTON_B:
				m_controllerPressed[BUTTON_B] = true;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				m_controllerPressed[DPAD_LEFT] = false;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				m_controllerPressed[DPAD_RIGHT] = false;
				break;
			}
		}

		//Check for controller joystick
		else if (m_InputEvent.type == SDL_JOYAXISMOTION) 
		{
			//X axis motion
			if (m_InputEvent.jaxis.axis == 0) 
			{
				if (m_InputEvent.jaxis.value < -Deadzone) 
				{
					XDirection = -1;
				}
				else if (m_InputEvent.jaxis.value > Deadzone)
				{
					XDirection = 1;
				}
				else 
				{
					XDirection = 0;
				}
			}

		}
	}
}

bool Input::KeyIsPressed(KEYS_PRESSED_LIST key)
{
	return m_keysPressed[key];
}

bool Input::MouseIsPressed(MOUSE_PRESSED_LIST mouse)
{
	return m_mousePressed[mouse];
}

bool Input::ControllerIsPressed(CONTROLLER_PRESSED_LIST controller)
{
	return m_controllerPressed[controller];
}

int Input::GetJoystickPosition()
{
	return XDirection;
}

int Input::GetMouseX()
{
	return m_XMouse;
}

int Input::GetMouseY()
{
	return m_YMouse;
}
