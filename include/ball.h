#pragma once

#include "raylib.h"
#include "paddle.h"



class Ball
{
public:
	Ball();
	void update(float delta);
	void draw();
	void checkCollision(Paddle& paddle);
	void collided(bool horizontal, bool vertical);
	
	Rectangle getRect() const;
	int getX_Velocity() const;
private:
	Rectangle rect;
	int x_velocity;
	int y_velocity;
};
