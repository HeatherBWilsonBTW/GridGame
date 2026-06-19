#include <iostream>
#include "raylib.h"
#include <string>
#include "Player.h"

int main()
{
	std::cout << "Before InitWindow\n";
	// create Window
	InitWindow(800, 600, "Space Hunter");
	std::cout << "After InitWindow\n";
	// Set FPS
	SetTargetFPS(60);

	int playerX = 400;
	int playerY = 300;
	
	Player player;

	//variable for score
	int score = 0;

	while (!WindowShouldClose())
	{
		// input movement
		// If w is pressed
		if (IsKeyDown(KEY_W))
		{
			playerY -= 5;
		}
		//if s is pressed
		if (IsKeyDown(KEY_S)) 
		{
			playerY += 5;
		}

		//if a is pressed 
		if (IsKeyDown(KEY_A))
		{
			playerX -= 5;
		}

		//if d is preessed
		if (IsKeyDown(KEY_D))
		{
			playerX += 5;
		}
		

		// set up boundaries
		
		//if player goes too far up
		if (playerY < 20)
		{
			// set player back to top limit
			playerY = 20;
		}

		//if player goes too far down
		if (playerY > 580)
		{
			// set player back to bottom limit
			playerY = 580;
		}

		//if player goes too far left
		if (playerX < 20)
		{
			// set player back to the left limit
			playerX = 20;
		}    
		
		// if plyaer goes too far right
		if (playerX > 780)
		{
			// set player back to the right limit
			playerX = 780;
		}
		player.Update();

		BeginDrawing();
		ClearBackground(BLACK);
		player.Draw();
		std::string scoreText = "Score: " + std::to_string(score);
		DrawText(scoreText.c_str(), 20, 20, 30, WHITE);
		EndDrawing();
	}
	// close window
	CloseWindow();

	return 0;
	
}
