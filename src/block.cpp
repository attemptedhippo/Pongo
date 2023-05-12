#include "block.h"
#include "raylib.h"

Block::Block(int _x, int _y, int _w, int _h) :
	rect{_x, _y, _w, _h},
	destroyed{false}
{

}

Rectangle Block::getRect()
{
	return rect;
}

void Block::update(float delta)
{
	//do update
}

void Block::draw()
{
	DrawRectangle(rect.x, rect.y, rect.width, rect.height, DARKGREEN);
}

void Block::collided()
{
	destroyed = true;
	destroy();
}

void Block::destroy()
{
	//oh no I have died!
}

