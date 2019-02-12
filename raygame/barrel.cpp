#include "barrel.h"
barrel::barrel()
{
	rot = 1.0f;
	barrelPosv = {0,0 };
	barrelPostr.localPos = { 0,0 };
	barrelImg = LoadTexture("Resource/barrel.png");
}

barrel::~barrel()
{
}

void barrel::update()
{

}

void barrel::draw()
{
	DrawTextureEx(barrelImg, tankPostr.localPos, barrelPostr.worldRotation(),1,WHITE);
}
void barrel::rotate()
{
	if (IsKeyDown(KEY_LEFT))
	{
		barrelPostr.localRot += rot;
	}
	if(IsKeyDown(KEY_RIGHT))
	{
		barrelPostr.localRot -= rot;
	}
}
