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
		
		GetCollisionRec(mainBall.getRect(), playerPaddle.getRect());
		mainBall.update();

		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawRectangle(mainBall.getRect().x , mainBall.getRect().y , mainBall.getRect().width , mainBall.getRect().height , RED);
		DrawRectangle(playerPaddle.getRect().x, playerPaddle.getRect().y, playerPaddle.getRect().width, playerPaddle.getRect().height , RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
