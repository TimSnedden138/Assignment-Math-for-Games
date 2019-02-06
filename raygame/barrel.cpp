#include "barrel.h"
barrel::barrel()
{
	barrelPosv = {280,260 };
	barrelPostr.localPos = { 290,260 };
}

barrel::~barrel()
{
	delete &barrelImg;
}

void barrel::update()
{

}

void barrel::draw()
{
	barrelImg = LoadTexture("barrel.png");
	DrawTextureEx(barrelImg,barrelPosv, barrelPostr.localRot, 1, WHITE);
}
void barrel::move()
{
	if (IsKeyDown(KEY_W))
	{
		barrelPosv.y--;
	}
	if (IsKeyDown(KEY_S))
	{
		barrelPosv.y++;
	}
	if (IsKeyDown(KEY_A))
	{
		barrelPosv.x--;
	}
	if (IsKeyDown(KEY_D))
	{
		barrelPosv.x++;
	}
}
void barrel::rotate() 
{
	if (IsKeyDown(KEY_Q))
	{
		barrelPostr.localRot--;
	}
	if (IsKeyDown(KEY_E))
	{
		barrelPostr.localRot++;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		barrelPostr.localRot++;
	}
	if(IsKeyDown(KEY_RIGHT))
	{
		barrelPostr.localRot--;
	}
}
