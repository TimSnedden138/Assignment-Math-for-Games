#include "barrel.h"
barrel::barrel()
{
	rot = 20.0f;
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
	DrawTextureEx(barrelImg,barrelPostr.worldPosition(), barrelPostr.worldRotation(), 0.0f,WHITE);
}
void barrel::rotate() 
{
	if (IsKeyDown(KEY_LEFT))
	{
		barrelPostr.rotate(math_help::DEG_TO_RAD(rot));
	}
	if(IsKeyDown(KEY_RIGHT))
	{
		barrelPostr.rotate(math_help::DEG_TO_RAD(-rot));
	}
}
