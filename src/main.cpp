#include "raylib.h" // should use "raylib.h" instead of <raylib.h> since the raylib headers are included locally in this project
#include "game.h"
#include <iostream>
// #include "paths.h"
#include "assets.h"

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
    
    constexpr int screenWidth = 300 + 200;
    constexpr int screenHeight = 600 + 20;

    InitWindow(screenWidth, screenHeight, "raylib Tetris");
    SetTargetFPS(60);
    
    // std::cout << "Working directory: " << GetWorkingDirectory() << std::endl;
    // std::cout << "Executable path: " << GetApplicationDirectory() << std::endl;
    // const char* EXECUTABLE_PATH =  GetApplicationDirectory(); // C-style string
    
    // // Load an external font
    // Font font_UI = LoadFontEx((FONTS_PATH + "AmaticSC-Regular.ttf").c_str(), 64, 0, 0); // LoadFontEx expects a const char* (C-style string)
    

    InitAudioDevice(); // gives us the ability to load and play sounds
    
    // Load Game Assets
    // NOTE: now that we have gameAssets in main.cpp, we should pass this by
    // reference to other objects in the game, i.e. GameObject.initialize(&GameAssets gameAssets)
    GameAssets gameAssets;  
    gameAssets.LoadAssets();

    // access the UI font from game assets
    Font font_UI = gameAssets.fonts["monogram"];
    // Font font_UI = gameAssets.fonts["AmaticSC-Regular"];

    // access sound assets
    Music bg_music = gameAssets.music["Eurobeat_Remix"];
    Sound clearSound = gameAssets.sounds["clear"];
    Sound rotateSound = gameAssets.sounds["rotate"];

    // Instantiate the game
    Game game = Game();

    // Start the music
    SetMusicVolume(bg_music, 0.2f); // Set to 20% volume
    PlayMusicStream(bg_music);

    // Game loop
    while (!WindowShouldClose())
    {
        UpdateMusicStream(bg_music);
        game.HandleInput();
        if (game.TimerTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font_UI, "Score", {360, 15}, 38, 2, WHITE);
        DrawTextEx(font_UI, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font_UI,"GAME OVER", {320,450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        // Draw the score 
        char scoreText[10];
        sprintf(scoreText, "%d",game.score); // assign a string to scoreText
        Vector2 textSize = MeasureTextEx(font_UI, scoreText, 38, 2);

        DrawTextEx(font_UI, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        // Get FPS value and draw it in a custom color
        int fps = GetFPS();  
        DrawTextEx(font_UI, TextFormat("FPS: %d", fps), {10, 10}, 20, 2, WHITE); 

        EndDrawing();
    }
    
    
    // Stop streaming audio
    // CloseAudioDevice();

    // Unload assets
    UnloadMusicStream(bg_music);
    UnloadSound(clearSound);
    UnloadSound(rotateSound);
    UnloadFont(font_UI);
    
    // Close the game window
    CloseWindow();
}


