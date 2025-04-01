#include "raylib.h" // should use "raylib.h" instead of <raylib.h> since the raylib headers are included locally in this project
#include "grid.h"
#include "blocks.cpp"

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};
    const Color darkBlue = {44, 44, 127, 255}; 
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    // grid.grid[1][2] = 2;
    grid.Print();

    ZBlock block = ZBlock();
    block.Move(4,3);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();

        // Get FPS value and draw it in a custom color
        int fps = GetFPS();  
        DrawText(TextFormat("FPS: %d", fps), 10, 10, 20, WHITE); 

        EndDrawing();
    }
    
    CloseWindow();
}