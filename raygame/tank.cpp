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
	DrawTextureEx(tankImg, tankPostr.worldPosition(), 0.0f, 1, WHITE);
}
void tank::move()
{
	vec2 moving = { 5,6 };
	if (IsKeyDown(KEY_W))
	{
		tankPostr.localPos.y -= moving.y;

	}
	if (IsKeyDown(KEY_S))
	{
		tankPostr.localPos.y += moving.y;
	}
	if (IsKeyDown(KEY_A))
	{
		tankPostr.localPos.x -= moving.x;
	}
	if (IsKeyDown(KEY_D))
	{
		tankPostr.localPos.x += moving.x;
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
