#pragma once
class Player
{
private:
	int playerX;

	int playerY; 

	int speed;

public:

// ceate a player
	Player();

// tell it to update
	void Update();

// tel it to draw
	void Draw() const;

};

