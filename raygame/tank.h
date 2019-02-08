#pragma once
#include"raylib.h"
#include"transform2d.h"
class tank
{
public:
	tank();
	~tank();
	Texture2D tankImg;
	transform2d tankPostr;
	Vector2 tankPosv;
	void update();
	void draw();
	void move();
	void rotate();
};