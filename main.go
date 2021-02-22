package main

import (
	rl "github.com/gen2brain/raylib-go/raylib"
)

const (
	screenWidth  = 200
	screenHeight = 200
	radius       = 100
)

var (
	pi     float64
	total  int
	inside int
	center = rl.NewVector2(screenWidth/2, screenHeight/2)
)

type Point struct {
	rl.Vector2
	IsInside bool
}

func main() {
	rl.SetConfigFlags(rl.FlagMsaa4xHint)
	rl.InitWindow(screenWidth, screenHeight, "Piral")

	circle := rl.LoadTexture("circle.png")
	defer rl.UnloadTexture(circle)

	rl.SetTargetFPS(60)
	rl.ClearBackground(rl.Black)

	points := make(chan Point, 100)
	for i := 0; i < 100; i++ {
		go gen(points)
	}

	for !rl.WindowShouldClose() {
		for point := range points {
			if point.IsInside {
				inside++
			}
			total++
			pi = 4.0 * float64(inside) / float64(total)

			rl.BeginDrawing()
			if point.IsInside {
				rl.DrawTextureEx(circle, point.Vector2, 0, 0.25, rl.SkyBlue)
			} else {
				rl.DrawTextureEx(circle, point.Vector2, 0, 0.25, rl.Green)
			}

			rl.DrawCircleLines(int32(center.X), int32(center.Y), radius, rl.White)
			rl.EndDrawing()
		}
	}
}

func gen(points chan Point) {
	for {
		point := Point{
			Vector2: rl.NewVector2(
				float32(rl.GetRandomValue(0, screenWidth)),
				float32(rl.GetRandomValue(0, screenHeight)),
			),
		}
		point.IsInside = rl.CheckCollisionPointCircle(point.Vector2, center, radius)
		points <- point
	}
}
