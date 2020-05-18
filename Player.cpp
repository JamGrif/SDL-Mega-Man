#include "Player.h"

Player::Player(Camera* camera, Renderer* renderer, Input* input, LevelManager* levelmanager, float X, float Y, int LayerNum)
	:MoveableEntity(renderer, levelmanager, LayerNum)
{

	m_pcamera = camera;

	m_pinput = input;

	//Megaman is 48 x 48
	m_Width = 48;
	m_Height = 48;

	//Set the player sprite to the default sprite
	m_object->SetSprite(PlayerIdle1R);
	SpriteToUse = PlayerIdle1R;

	m_object->SetX(X);
	m_object->SetY(Y);

	m_Moveable = true;

	m_Acceleration = 4;

	PlayerRunL.push_back(PlayerRun1L);
	PlayerRunL.push_back(PlayerRun1L);
	PlayerRunL.push_back(PlayerRun1L);
	PlayerRunL.push_back(PlayerRun2L);
	PlayerRunL.push_back(PlayerRun2L);
	PlayerRunL.push_back(PlayerRun2L);
	PlayerRunL.push_back(PlayerRun3L);
	PlayerRunL.push_back(PlayerRun3L);
	PlayerRunL.push_back(PlayerRun3L);

	PlayerRunR.push_back(PlayerRun1R);
	PlayerRunR.push_back(PlayerRun1R);
	PlayerRunR.push_back(PlayerRun1R);
	PlayerRunR.push_back(PlayerRun2R);
	PlayerRunR.push_back(PlayerRun2R);
	PlayerRunR.push_back(PlayerRun2R);
	PlayerRunR.push_back(PlayerRun3R);
	PlayerRunR.push_back(PlayerRun3R);
	PlayerRunR.push_back(PlayerRun3R);

}

Player::~Player()
{

}

void Player::Update()
{
	/*
		Input to move
	*/
	if (m_pinput->KeyIsPressed(KEY_D) || m_pinput->GetJoystickPosition() == 1)
	{
		Right();
		//std::cout << "right" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_A) || m_pinput->GetJoystickPosition() == -1)
	{
		Left();
		//std::cout << "left" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_W))
	{
		//Up();
		//std::cout << "up" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_S))
	{
		//Down();
		//std::cout << "down" << std::endl;
	}
	if (m_pinput->KeyIsPressed(KEY_SPACE) || m_pinput->ControllerIsPressed(BUTTON_A))
	{
		if (CanJump)
		{
			//std::cout << "jumping activated" << std::endl;
			IsJumping = true;
			CanJump = false;
			m_JumpCurrentTick = 0;
			m_VerticalMoving = true;
		}
	}

	/*
		Air Resistance
	*/

	//Apply air resistance to horizontal velocity
	if (m_HorizontalMoving) //Object moving horizontally
	{
		if (Velocity.x > 0) //Object moving right
		{
			Velocity.x -= m_AirResistance;
			if (0 - Velocity.x > Velocity.x) { Velocity.x = 0; }
		}
		else if (Velocity.x < 0) //Object moving left
		{
			Velocity.x += m_AirResistance;
			if (0 - Velocity.x < Velocity.x) { Velocity.x = 0; }
		}
	}

	/*
		Gravity
	*/

	//Gravity only applies if player not jumping
	if (!IsJumping)
	{
		
		//Check pixel directly below player
		if (!m_plevelmanager->CheckForWall(m_Top, m_Bottom + 3, m_Left, m_Right))
		{
			IsGrounded = false;
			CanJump = false;
		}
		else
		{
			if (!IsJumping) { CanJump = true; }
		}

		//If player is not grounded then apply gravity
		if (!IsGrounded)
		{

			if (!AppliedGravity)
			{
				//std::cout << "gravity applied" << std::endl;
				Velocity.y += m_Gravity;
				AppliedGravity = true;
				m_VerticalMoving = true;
			}


		}
		else
		{
			AppliedGravity = false;
			Velocity.y = 0;
		}

	}

	/*
		Jumping
	*/
	//std::cout << m_object->GetY() << std::endl;
	if (IsJumping) 
	{
		//std::cout << "hello1" << std::endl;
		//std::cout << "currenttick is " << m_JumpCurrentTick << std::endl;
		//std::cout << "maxtick is " << m_JumpMaxTick << std::endl;

		if (m_JumpCurrentTick < m_JumpMaxTick) 
		{
			Velocity.y -= 0.1;
			m_JumpCurrentTick++;
			//std::cout << "hello2" << std::endl;
		}
		else 
		{
			//std::cout << "stop jumping" << std::endl;
			IsJumping = false;
			m_JumpCurrentTick = 0;
			Velocity.y = 0;
		}
	}

	
	/*
		Collision check and movement
	*/

	//Check for collision and move object horizontally
	if (m_HorizontalMoving) 
	{
		m_object->SetX(m_object->GetX() + Velocity.x);
		
		UpdateCollisionPosition();

		//Check collision with level 
		if (m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right))
		{
			m_object->SetX(m_object->GetX() - Velocity.x); 
			Velocity.x = 0;
		}
	}
	
	//Check for collision and move object vertically
	if (m_VerticalMoving)
	{
		//std::cout << Velocity.y << std::endl;
		m_object->SetY(m_object->GetY() + Velocity.y);

		UpdateCollisionPosition();
		/*
		//If velocity.y is negative then player is jumping
		if (Velocity.y < 0) 
		{	//Check above player to see if player can still jump
			if (m_plevelmanager->CheckForWall(m_Top + 4, m_Bottom, m_Left, m_Right)) 
			{
				IsJumping = false;
			}
		}*/
		if (!IsJumping) 
		{
			if (AppliedGravity)
			{
				if (m_plevelmanager->CheckForWall(m_Top, m_Bottom, m_Left, m_Right))
				{

					m_object->SetY(m_object->GetY() - Velocity.y);
					Velocity.y = 0;

					CanJump = true;
					IsGrounded = true;
					AppliedGravity = false;
				}
				else
				{
					IsGrounded = false;
				}
			}
		}
		
		
		
		
	}

	//std::cout << Velocity.y << std::endl;
	if (Velocity.x == 0) { m_HorizontalMoving = false; }
	if (Velocity.y == 0) { m_VerticalMoving = false; }

	//std::cout << "Isjumping is " << IsJumping << std::endl;
	//std::cout << "CanJump is " << CanJump << std::endl;

	SpriteUpdate();

	//Centers the camera on the player
	m_pcamera->CenterCamera(m_object->GetX(), m_object->GetY());
}

void Player::SpriteUpdate()
{
	if (m_HorizontalMoving)
	{
		//Running left
		if (Velocity.x < 0) 
		{
			FacingRight = false;
			m_CurrentFrame++;
			if (m_CurrentFrame > 8) { m_CurrentFrame = 0; }
			SpriteToUse = PlayerRunL.at(m_CurrentFrame);
		}
		//Running right
		else
		{
			FacingRight = true;
			m_CurrentFrame++;
			if (m_CurrentFrame > 8) { m_CurrentFrame = 0; }
			SpriteToUse = PlayerRunR.at(m_CurrentFrame);
		}
	}
	else 
	{
		SpriteToUse = FacingRight ? PlayerIdle1R : PlayerIdle1L;
		m_CurrentFrame = 0;
	}

	m_object->SetSprite(SpriteToUse);
}














