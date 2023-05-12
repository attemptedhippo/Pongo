#include <string>
#include <vector>
#include <memory>
#include "raylib.h"

#include "ball.h"
#include "paddle.h"
#include "block.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "Game");
	SetTargetFPS(60);

	Paddle playerPaddle(screenWidth/2 - 25, screenHeight - 30, 50, 10);
	Ball mainBall;

	std::vector<std::unique_ptr<Block>> blocks;
	int blockWidth = 50;
	int blockHeight = 30;
	std::string Log;
	for(int i = 0; i < 10; i++)
	{
		Log.append(TextFormat("%i ", i + 3 * i));
		blocks.push_back(std::make_unique<Block>((i * blockWidth) + 3 * i, 50, blockWidth, blockHeight));
	}

	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();

		if(IsKeyDown(KEY_RIGHT)) playerPaddle.move(200 * deltaTime);
		if(IsKeyDown(KEY_LEFT)) playerPaddle.move(-200 * deltaTime);

		switch (GetKeyPressed())
		{
			case(KEY_A):
				//Do nothing, this is a placeholder for other key events.
				break;
		}
		
		mainBall.checkCollision(playerPaddle);
		mainBall.update(deltaTime);

		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawText(Log.c_str(), 3, 3, 15, BLACK);
		mainBall.draw();
		playerPaddle.draw();
		for(auto & element : blocks)
		{
			element->draw();
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
