/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include"mathUtil.h"
#include"tank.h"
#include"barrel.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);
	barrel barrel;
	tank tank;
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("Rotations:", 0, 20, 20, RED);
		DrawText("W to move forward", 5, 40, 20, RED);
		DrawText("S to move backward", 5, 60, 20, RED);
		DrawText("A to move left", 5, 80, 20, RED);
		DrawText("D to move right", 5, 100, 20, RED);
		DrawText("Q to rotate both left", 5, 120, 20, RED);
		DrawText("E to rotate both right",5, 140, 20, RED);
		DrawText("Left Arrow to rotate barrel left", 5, 160, 20, RED);
		DrawText("Right Arrow to rotate barrel right", 5, 180, 20, RED);
		tank.draw();
		tank.move();
		tank.rotate();
		barrel.draw();
		barrel.rotate();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}