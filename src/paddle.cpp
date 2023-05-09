#include "paddle.h"
#include "raylib.h"

Paddle::Paddle(int _x, int _y, int _w, int _h) :
	rect{_x, _y, _w, _h}
	//rect.x{_x},
	//rect.y{_y},
	//rect.width{_w},
	//rect.height{_h}

{
	
}

void Paddle::move(int _x)
{
	if((rect.x + _x < 0)	|| (rect.x + _x > GetScreenWidth()))
		return;

	rect.x += _x;
}

Rectangle Paddle::getRect() const
{
	return rect;
}
