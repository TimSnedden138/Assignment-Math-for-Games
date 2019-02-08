#include "barrel.h"
barrel::barrel()
{
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
	DrawTextureEx(barrelImg,barrelPostr.worldPosition(), 0.0f, 1, WHITE);
}
void barrel::rotate() 
{
	if (IsKeyDown(KEY_LEFT))
	{
		barrelPostr.localRot++;
	}
	if(IsKeyDown(KEY_RIGHT))
	{
		barrelPostr.localRot--;
	}
}
