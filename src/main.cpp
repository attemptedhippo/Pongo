#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "raylib.h"

#include "ball.h"
#include "paddle.h"
#include "block.h"

//TODO: move engine boilerplate to an app/engine class.

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
	int padding = 5;
	int topPadding = 50;
	
	std::string Log;
	//Log.append(TextFormat("total width %i: %i  || ", width_of_block_group, leftPadding));

	for(int i = 0; i < 30; i++)
	{
		blocks.push_back(std::make_unique<Block>(leftPadding + (((i % 10) * blockWidth) + (padding * (i % 10))),
					topPadding + (((i / 10) * blockHeight) + (padding * (i / 10))), blockWidth, blockHeight));
	}

	bool pause = false;
	while (!WindowShouldClose())
	{
		if(!pause)
		{

		float deltaTime = GetFrameTime();

		if(IsKeyDown(KEY_RIGHT)) playerPaddle.move(250 * deltaTime);
		if(IsKeyDown(KEY_LEFT)) playerPaddle.move(-250 * deltaTime);

		for(auto & element : blocks)
		{
			if(CheckCollisionRecs(mainBall.getRect(), element->getRect()))
			{
				mainBall.collided(true, true);	//TODO: Break down ball.checkCollision into check and do logic.
												//call do collide logic here.
				element->collided();			//TODO: Implement block break logic.
				break;
			}
		}
		blocks.erase(std::remove_if(blocks.begin(), blocks.end(), 
					[](const std::unique_ptr<Block>& b) { return b->getDestroyed(); } ), blocks.end());
		mainBall.checkCollision(playerPaddle);
		mainBall.update(deltaTime);

		}

		switch (GetKeyPressed())
		{
			case(KEY_A):
				//Do nothing, this is a placeholder for other key events.
				pause = !pause;
				break;
		}

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
