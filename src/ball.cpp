#include "ball.h"
#include "paddle.h"
#include "raylib.h"

Ball::Ball() :
	rect{GetScreenWidth()/2, GetScreenHeight()/2, 20, 20},
	x_velocity{200}, //Magic number!
	y_velocity{200}

{

}

void Ball::update(float delta)
{
	if((rect.x + x_velocity * delta <= 0) || ((rect.x + rect.width) + x_velocity * delta >= GetScreenWidth())) x_velocity = -x_velocity;
	if((rect.y + y_velocity * delta <= 0) || ((rect.y + rect.height) + y_velocity * delta >= GetScreenHeight())) y_velocity = -y_velocity;

	rect.x += x_velocity * delta;
	rect.y += y_velocity * delta;
}

void Ball::draw()
{
	DrawRectangle(rect.x, rect.y, rect.width, rect.height, RED);
}
void Ball::checkCollision(Paddle& paddle)
{
	if(CheckCollisionRecs(rect, paddle.getRect()))
	{
		Rectangle tmpRect = GetCollisionRec(rect, paddle.getRect());
		float centerPoint = tmpRect.x + (tmpRect.width / 2);
		if(centerPoint <= (paddle.getRect().x + (paddle.getRect().width / 2)))
		{
			if(x_velocity > 0) // if greater than 0 its moving to the right
				collided(true, true);
			else
			 	collided(false, true);
		}
		else
		{
			if(x_velocity > 0)
				collided(false, true);
			else
				collided(true, true);
		}
	}
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

int Ball::getX_Velocity() const
{
	return x_velocity;
}
