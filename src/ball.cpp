#include "ball.h"
#include "raylib.h"

Ball::Ball() :
	rect{GetScreenWidth()/2, GetScreenHeight()/2, 20, 20},
	x_velocity{8}, //Magic number!
	y_velocity{8}

{

}

void Ball::update()
{
	if((rect.x + x_velocity <= 0) || (rect.x + x_velocity >= GetScreenWidth())) x_velocity = -x_velocity;
	if((rect.y + y_velocity <= 0) || (rect.y + y_velocity >= GetScreenHeight())) y_velocity = -y_velocity;

	rect.x += x_velocity;
	rect.y += y_velocity;
}

void Ball::collided(bool horizontal, bool vertical)
{
	if(horizontal)	x_velocity = -x_velocity;
	if(vertical)	y_velocity = -y_velocity;
}

Rectangle Ball::getRect() const
{
	return rect;
}
