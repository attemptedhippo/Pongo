#include "paddle.h"
#include "raylib.h"
#include <cwchar>
Paddle::Paddle(int _x, int _y, int _w, int _h) :
	x{_x},
	y{_y},
	w{_w},
	h{_h}

{}

void Paddle::move(int _x, int _y)
{
	if((x + _x < 0)	|| (x + _x > GetScreenWidth()))
		return;

	x += _x;
}

int Paddle::getX()
{
	return x;
}

int Paddle::getY()
{
	return y;
}

int Paddle::getW()
{
	return w;
}

int Paddle::getH()
{
	return h;
}
