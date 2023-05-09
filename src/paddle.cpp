#include "paddle.h"
#include "raylib.h"

Paddle::Paddle(int _x, int _y, int _w, int _h) :
	rect{_x, _y, _w, _h}
{
	
}

void Paddle::draw()
{
	DrawRectangle(rect.x, rect.y, rect.width, rect.height, RAYWHITE);
}

void Paddle::move(int _x)
{
	if((rect.x + _x < 0) || (rect.x + _x > GetScreenWidth()))
		return;

	rect.x += _x;
}

Rectangle Paddle::getRect() const
{
	return rect;
}
