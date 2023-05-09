#include "raylib.h"
#include "paddle.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawRectangle(175, 690, 50, 20, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
