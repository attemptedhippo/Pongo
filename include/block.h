#pragma once

#include "raylib.h"

class Block
{
public:
	Block(int _x, int _y, int _w, int _h);
	void update();
	void draw();
	void collided();
	void destroy();
	Rectangle getRect();

private: 

	bool destroyed;
	Rectangle rect;
};
