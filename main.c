/*******************************************************************************************
*
*   raylib [core] example - 2d camera
*
*   This example has been created using raylib 1.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "include/raylib.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900
#define CIRCLE_RADIUS 450

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Monlo Pi");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircleLines(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, CIRCLE_RADIUS, BLUE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}