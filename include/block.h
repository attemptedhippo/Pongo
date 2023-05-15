#pragma once

#include "raylib.h"

//TODO: make getter func for when block is ready to be removed from
//entity list. fix dying logic; collided sets dying bool to true,
//when dying timer ends set destroyed to true. call getter main game
//update loop, if getDestroyed pop from list.

class Block
{
public:
	Block(int _x, int _y, int _w, int _h);
	void update(float delta);
	void draw();
	void collided();
	bool getDestroyed();
	Rectangle getRect();

private: 
	//add dyingTimer here
	//add dyingBool here
	bool destroyed;
	Rectangle rect;
};
