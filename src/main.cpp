#include "raylib.h"
#include "paddle.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "Game");
	SetTargetFPS(60);

	Paddle playerPaddle(screenWidth/2 - 25, screenHeight/2 - 10, 50, 10);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawRectangle(playerPaddle.getX(), playerPaddle.getY(), playerPaddle.getW(), playerPaddle.getH(), RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
