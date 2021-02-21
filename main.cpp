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
    long double pi{};

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Monlo Pi");
    Texture2D circle = LoadTexture("circle.png");

    SetTargetFPS(60);
    ClearBackground(BLACK);

    while (!WindowShouldClose())
    {
        for (int i = 0; i < 10000; i++)
        {
            Vector2 point{(float)GetRandomValue(0, SCREEN_WIDTH), (float)GetRandomValue(0, SCREEN_HEIGHT)};
            points.push_back(point);
            if (CheckCollisionPointCircle(point, center, CIRCLE_RADIUS))
                points_inside++;
        }

        BeginDrawing();
        for (auto point : points)
        {
            if (CheckCollisionPointCircle(point, center, CIRCLE_RADIUS))
                DrawTextureEx(circle, point, 0, 0.25, SKYBLUE);
            else
                DrawTextureEx(circle, point, 0, 0.25, GREEN);
            pi = 4.0 * ((long double)points_inside / (long double)points.size());
        }

        DrawCircleLines(center.x, center.y, CIRCLE_RADIUS, WHITE);
        EndDrawing();
        std::cout << pi << std::endl;
    }

    UnloadTexture(circle);
    CloseWindow();

    return 0;
}