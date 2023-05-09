#pragma once

#include "raylib.h"

class Paddle
{
public:
	Paddle(int _x, int _y, int _w, int _h);
	void draw();
	void move(int _x);
	Rectangle getRect() const;
private:
	Rectangle rect;
};
