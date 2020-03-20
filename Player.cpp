#include "Player.h"

Player::Player(Renderer* renderer, int xpos, int ypos, Level* pLevel, bool useTransparency)
	:Creature(renderer, xpos, ypos, pLevel, useTransparency)
{
	//player is 64 pixels wide and 128 pixels tall
	CurrentPicture = PlayerR;
	//UpdateBitmap(CurrentPicture, true);

	m_Acceleration = 4;

	m_JumpSpeed = 7;
	m_CurrentJumpSpeed = m_JumpSpeed;
	m_MaxJumpTick = 9;

	m_Width = 53;
	m_Height = 51;

	m_object = m_prenderer->CreateMesh();
	m_object->SetSprite("Assets/PlayerR.bmp");

	//Saving the running sprites into the approiate vectors
	/*PlayerRunL.push_back("Assets/PlayerRun1L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun1L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun1L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun2L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun2L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun2L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun1L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun1L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun1L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun3L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun3L.bmp");
	PlayerRunL.push_back("Assets/PlayerRun3L.bmp");

	PlayerRunR.push_back("Assets/PlayerRun1R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun1R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun1R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun2R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun2R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun2R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun1R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun1R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun1R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun3R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun3R.bmp");
	PlayerRunR.push_back("Assets/PlayerRun3R.bmp");*/
}


Player::~Player()
{

}

void Player::Move(char Direction)
{
	if (Direction == 'u') //Up
	{
		//if (!TouchingUp) { Velocity.y -= m_Acceleration; }
	}
	else if (Direction == 'd') //Down
	{
		//if (!TouchingDown) { Velocity.y += m_Acceleration; }
	}
	else if (Direction == 'l') //Left
	{
		if (!TouchingLeft) { Velocity.x -= m_Acceleration; }
	}
	else if (Direction == 'r') //Right
	{
		if (!TouchingRight) { Velocity.x += m_Acceleration; }
	}
	else if (Direction == 'j') //Jump
	{
		//If player is currently not jumping and is grounded then set it so they are currently jumping
		if (!IsJumping && IsGrounded)
		{
			IsJumping = true;
			m_CurrentJumpTick = 0;
		}
	}

	

}

void Player::Update()
{

	//If Velocity exceeds MaxVelocity then lower Velocity down to MaxVelocity  
	if (Velocity.x > m_MaxVelocity) { Velocity.x = m_MaxVelocity; }
	if (Velocity.x < -m_MaxVelocity) { Velocity.x = -m_MaxVelocity; }

	if (Velocity.y > m_MaxVelocity) { Velocity.y = m_MaxVelocity; }
	if (Velocity.y < -m_MaxVelocity) { Velocity.y = -m_MaxVelocity; }

	//Get the collision position of creature
	GetCollisionPosition();

	//Check if the player is grounded or not
	IsGrounded = levelinfo->IsWall(BotLeftPosX, BotLeftPosY + 1, BotRightPosX, BotRightPosY + 1) == true ? true : false;

	if (IsGrounded == false) //If the player is not grounded then apply gravity
	{
		if (!AppliedGravity)
		{
			Velocity.y += m_Gravity;
			AppliedGravity = true;
		}
	}
	else
	{
		AppliedGravity = false;
		Velocity.y = 0;
	}


	//If the character is jumping then apply jumping stuff
	if (IsJumping)
	{
		if (m_CurrentJumpTick < m_MaxJumpTick)
		{
			m_CurrentJumpSpeed--;
			Velocity.y -= m_CurrentJumpSpeed;
			m_CurrentJumpTick++;
		}
		else
		{
			AppliedGravity = false;
			IsJumping = false;
			m_CurrentJumpTick = 0;
			Velocity.y = 0;
			m_CurrentJumpSpeed = m_JumpSpeed;
		}

		//Check above the player and if they hit something then stop jumping
		if (levelinfo->IsWall(TopLeftPosX, TopLeftPosY - 1, TopRightPosX, TopRightPosY - 1) == true)
		{
			AppliedGravity = false;
			IsJumping = false;
			m_CurrentJumpTick = 0;
			Velocity.y = 0;
			m_CurrentJumpSpeed = m_JumpSpeed;
		}
	}


	//Move the creature depending on velocity and if something is in the way
	TouchingRight = levelinfo->IsWall(TopRightPosX, TopRightPosY, BotRightPosX, BotRightPosY - 2) == true ? true : false;
	if (Velocity.x > 0 && !TouchingRight) //Creature moving right 
	{
		Position.x += Velocity.x;
		CanMove = levelinfo->IsWall(TopRightPosX, TopRightPosY, BotRightPosX, BotRightPosY - 2) == true ? false : true;
		if (!CanMove)
		{
			Velocity.x = 0;
		}
	}

	TouchingLeft = levelinfo->IsWall(TopLeftPosX, TopLeftPosY, BotLeftPosX, BotLeftPosY - 2) == true ? true : false;
	if (Velocity.x < 0 && !TouchingLeft) //Creature moving left
	{
		Position.x += Velocity.x;
		CanMove = levelinfo->IsWall(TopLeftPosX, TopLeftPosY, BotLeftPosX, BotLeftPosY - 2) == true ? false : true;
		if (!CanMove)
		{
			Velocity.x = 0;
		}
	}

	TouchingUp = levelinfo->IsWall(TopLeftPosX, TopLeftPosY - 1, TopRightPosX, TopRightPosY - 1) == true ? true : false;
	if (Velocity.y < 0 && !TouchingUp) //Creature moving up
	{
		Position.y += Velocity.y;
		CanMove = levelinfo->IsWall(TopLeftPosX, TopLeftPosY - 1, TopRightPosX, TopRightPosY - 1) == true ? false : true;
		if (!CanMove)
		{
			Velocity.y = 0;
		}
	}

	TouchingDown = levelinfo->IsWall(BotLeftPosX, BotLeftPosY + 1, BotRightPosX, BotRightPosY + 1) == true ? true : false;
	if (Velocity.y > 0 && !TouchingDown) //Creature moving down;
	{
		Position.y += Velocity.y;
		CanMove = levelinfo->IsWall(BotLeftPosX, BotLeftPosY + 1, BotRightPosX, BotRightPosY + 1) == true ? false : true;
		if (!CanMove)
		{
			Velocity.y = 0;
		}
	}

	//Apply air resistance to velocity
	if (Velocity.x > 0)
	{
		Moving = true;
		FacingRight = true;
		Velocity.x -= m_AirResistance;
	}
	else if (Velocity.x < 0)
	{
		Moving = true;
		FacingRight = false;
		Velocity.x += m_AirResistance;
	}
	else 
	{
		Moving = false;
	}

	//Change animation if needed
	SpriteUpdate();

}

bool Player::HasPlayerWon() 
{
	if (Position.x >= 4870 && Coins == 5) 
	{
		return true;
	}
	return false;
}




//Ran at the end of physics check and is used to decide what sprite the player should be
void Player::SpriteUpdate()
{
	SavedCurrentPicture = CurrentPicture;

	//Change picture depending on what direction the player is going
	if (IsGrounded && !FacingRight)
	{
		CurrentPicture = PlayerL;
	}
	else if (IsGrounded && FacingRight)
	{
		CurrentPicture = PlayerR;
	}

	//If player is running then change animation to running animation
	if (Moving && IsGrounded && (Velocity.x > 1 || Velocity.x < -1))
	{
		if (FacingRight) 
		{
			m_CurrentFrame++;
			if (m_CurrentFrame > 11) { m_CurrentFrame = 0; }
			CurrentPicture = PlayerRunR.at(m_CurrentFrame);
		}
		else 
		{
			m_CurrentFrame++;
			if (m_CurrentFrame > 11) { m_CurrentFrame = 0; }
			CurrentPicture = PlayerRunL.at(m_CurrentFrame);
		}
		
	}
	else 
	{
		m_CurrentFrame = 0;
	}

	//If player is jumping then change animation to jumping animation
	if (IsJumping || !IsGrounded && AppliedGravity)
	{
		if (FacingRight) 
		{
			CurrentPicture = PlayerJumpR;
		}
		else 
		{
			CurrentPicture = PlayerJumpL;
		}
	}

	//If the current picture has not been changed then dont run UpdateBitmap function
	if (SavedCurrentPicture != CurrentPicture) 
	{
		UpdateBitmap(CurrentPicture, true);
	}

}

int Player::GetCoinsCollected()
{
	return Coins;
}

void Player::IncreaseCoinsCollected()
{
	Coins++;
}

void Player::Respawn()
{
	Position.x = SpawnPositionX;
	Position.y = SpawnPositionY;
}





