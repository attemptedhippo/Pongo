#pragma once

#include "raylib.h"

class Paddle
{
public:
	Paddle(int _x, int _y, int _w, int _h);
	void move(int _x, int _y);
	int getX();
	int getY();
	int getW();
	int getH();
private:
	int x;
	int y;
	int w;
	int h;
};
