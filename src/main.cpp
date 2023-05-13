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
	int width_of_block_group = ((10 * blockWidth) + 5 * 9); // (i * blockWidth) + 3 * (i - 1)
	int leftPadding = (screenWidth / 2) - width_of_block_group / 2;
	
	std::string Log;
	Log.append(TextFormat("total width %i: %i  || ", width_of_block_group, leftPadding));

	for(int i = 0; i < 10; i++)
	{
		blocks.push_back(std::make_unique<Block>(leftPadding + ((i * blockWidth) + 5 * i), 50, blockWidth, blockHeight));
	}

	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();

		if(IsKeyDown(KEY_RIGHT)) playerPaddle.move(250 * deltaTime);
		if(IsKeyDown(KEY_LEFT)) playerPaddle.move(-250 * deltaTime);

		switch (GetKeyPressed())
		{
			case(KEY_A):
				//Do nothing, this is a placeholder for other key events.
				break;
		}
		
		for(auto & element : blocks)
		{
			if(CheckCollisionRecs(mainBall.getRect(), element->getRect()))
			{
				mainBall.collided(true, true);	//TODO: Break down ball.checkCollision into check and do logic. call do collide logic here.
				element->collided();			//TODO: Implement block break logic.
			}
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
