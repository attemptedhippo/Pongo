#include "raylib.h"

#include "ball.h"
#include "paddle.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "Game");
	SetTargetFPS(60);

	Paddle playerPaddle(screenWidth/2 - 25, screenHeight - 30, 50, 10);
	Ball mainBall; 

	while (!WindowShouldClose())
	{
		if(IsKeyDown(KEY_RIGHT)) playerPaddle.move(8);
		if(IsKeyDown(KEY_LEFT)) playerPaddle.move(-8);

		switch (GetKeyPressed())
		{
			case(KEY_A):
				//Do nothing, this is a placeholder for other key events.
				break;
		}
		if(CheckCollisionRecs(mainBall.getRect(), playerPaddle.getRect()))
		{
			mainBall.collided(true, true);
		}
		GetCollisionRec(mainBall.getRect(), playerPaddle.getRect());
		mainBall.update();

		BeginDrawing();
		ClearBackground(DARKGRAY);
		mainBall.draw();
		playerPaddle.draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
