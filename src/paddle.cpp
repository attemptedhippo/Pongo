#include "paddle.h"
#include "raylib.h"

void Paddle::move(int _x, int _y)
{
	if((x + _x < 0)	|| (x + _x > GetScreenWidth()))
		return;

	x += _x;
}
