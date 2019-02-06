#pragma once
#include"transform2d.h"
#include"raylib.h"
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