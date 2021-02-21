#include "include/raylib.h"
#include <vector>
#include <string>
#include <iostream>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900
#define CIRCLE_RADIUS 450

int main(void)
{
    std::vector<Vector2> points{};
    int points_inside{};
    const Vector2 center{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    double pi{};

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Monlo Pi");
    Texture2D circle = LoadTexture("circle.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        for (int i = 0; i < 1000; i++)
        {
            Vector2 point{(float)GetRandomValue(0, SCREEN_WIDTH), (float)GetRandomValue(0, SCREEN_HEIGHT)};
            points.push_back(point);
            if (CheckCollisionPointCircle(point, center, CIRCLE_RADIUS))
                points_inside++;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        for (auto point : points)
        {
            DrawTextureEx(circle, point, 0, 1, SKYBLUE);
            pi = 4 * ((double)points_inside / (double)points.size());
        }
        DrawCircleLines(center.x, center.y, CIRCLE_RADIUS, YELLOW);
        DrawText(std::to_string(pi).c_str(), 5, 5, 23, WHITE);
        EndDrawing();
    }

    UnloadTexture(circle);
    CloseWindow();

    return 0;
}