#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "raylib.h"

#include "ball.h"
#include "paddle.h"
#include "block.h"

class Game
{
public:
	Game();
	bool OnInit(const int screenWidth, const int screenHeight, const char* title);
	int Run();
	void OnUpdate();
	void OnRender();
	void OnCleanup();
	//Game specific functions
	void CreateBoard();
private:
	std::string Log;
	std::vector<std::unique_ptr<Block>> blocks;
	std::vector<std::unique_ptr<Ball>> balls;
	std::unique_ptr<Paddle> paddle;
};

