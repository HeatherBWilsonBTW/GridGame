#include <iostream>
#include "raylib.h"
#include <string>


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


		BeginDrawing();
		ClearBackground(BLACK);
		DrawTriangle(
			{ (float)playerX, (float)playerY - 20 },
			{ (float)playerX - 20, (float)playerY + 20 },
			{ (float)playerX + 20, (float)playerY + 20 },
			BLUE
		);
		EndDrawing();
	}
	// close window
	CloseWindow();

	return 0;
	
}
