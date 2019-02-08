#include "tank.h"
tank::tank()
{

	tankPosv = { 250,250 };
	tankPostr.localPos = { 250,250 };
	tankImg = LoadTexture("Resource/tank.png");
}

tank::~tank()
{

}

void tank::update()
{
}

void tank::draw()
{
	DrawTextureEx(tankImg, tankPosv, tankPostr.localRot, 1, WHITE);
}
void tank::move()
{
	if (IsKeyDown(KEY_W))
	{
		tankPosv.y--;

	}
	if (IsKeyDown(KEY_S))
	{
		tankPosv.y++;
	}
	if (IsKeyDown(KEY_A))
	{
		tankPosv.x--;
	}
	if (IsKeyDown(KEY_D))
	{
		tankPosv.x++;
	}
}
void tank::rotate()
{
	if (IsKeyDown(KEY_Q))
	{
		tankPostr.localRot--;
	}
	if (IsKeyDown(KEY_E))
	{
		tankPostr.localRot++;
	}

}
