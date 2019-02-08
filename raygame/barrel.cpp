#include "barrel.h"
barrel::barrel()
{
	barrelPosv = {280,260 };
	barrelPostr.localPos = { 290,260 };
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
	DrawTextureEx(barrelImg,barrelPosv, barrelPostr.worldRotation(), 1, WHITE);
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
