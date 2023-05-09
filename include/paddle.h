#pragma once

#include "raylib.h"

class Paddle
{
public:
	void move(int _x, int _y);
private:
	int x;
	int y;
	int w;
	int h;
};
