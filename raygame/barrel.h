#pragma once
#include "tank.h"
#include"raylib.h"
class barrel : public tank
{
public:
	Vector2 barrelPosv;
	Texture2D barrelImg;
	transform2d barrelPostr;
	float rot;
	barrel();
	~barrel();
	void update();
	void draw();
	void rotate();
};