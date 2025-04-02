#include "raylib.h" // should use "raylib.h" instead of <raylib.h> since the raylib headers are included locally in this project
#include "game.h"

// double lastUpdateTime = 0;

// // this timer resets every time it returns true
// bool EventTriggered(double interval)
// {
//     double currentTime = GetTime();
//     if (currentTime - lastUpdateTime >= interval)
//     {
//         lastUpdateTime = currentTime;
//         return true;
//     }
//     return false;
// }

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};
    const Color darkBlue = {44, 44, 127, 255}; 
    
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib Tetris");
    SetTargetFPS(60);

    Game game = Game();

    
    while (!WindowShouldClose())
    {
        game.HandleInput();
        if (game.TimerTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        // Get FPS value and draw it in a custom color
        int fps = GetFPS();  
        DrawText(TextFormat("FPS: %d", fps), 10, 10, 20, WHITE); 

        EndDrawing();
    }
    
    CloseWindow();
}