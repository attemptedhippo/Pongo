#pragma once

#include "raylib.h"

class Ball
{
public:
	Ball();
	void update();
	void draw();
	void collided(bool horizontal, bool vertical);
	
	Rectangle getRect() const;
private:
	Rectangle rect;
	int x_velocity;
	int y_velocity;
};
