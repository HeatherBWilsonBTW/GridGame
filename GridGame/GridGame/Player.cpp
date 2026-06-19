#include "Player.h"
#include "raylib.h"

Player::Player()
{
	playerX = 400;
	playerY = 300;
	speed = 5;
}

void Player::Update()
{
	//movement input 
	// move up
	if (IsKeyDown(KEY_W))
	{
		playerY -= speed;
	}

	// move down
	if (IsKeyDown(KEY_S))
	{
		playerY += speed;
	}

	// move left
	if (IsKeyDown(KEY_A))
	{
		playerX -= speed;
	}

	// move right
	if (IsKeyDown(KEY_D))
	{
		playerX += speed;
	}
	// boundaries
	//top 
	if (playerY < 20)
	{                   
		playerY = 20;
	}

	// bottom
	if (playerY > 580)
	{
		playerY = 580;
	}

	// left boundary
	if (playerX < 20)
	{
		playerX = 20;
	}

	// right boundary
	if (playerX > 780)
	{
		playerX = 780;
	}

}

void Player::Draw() const
{
	DrawTriangle({ (float)playerX, (float)playerY - 40 }, { (float)playerX - 19, (float)playerY + 18 },
	{ (float)playerX + 19, (float)playerY + 18 }, BLUE);
	

	//cockpit
	DrawCircle(playerX, playerY - 5, 6, ORANGE);
	// rectagle body
	DrawRectangle(playerX - 18, playerY + 10, 36, 24, BLUE);

}
