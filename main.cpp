#include <raylib.h>
#include "Game.h"
#include <iostream>

double lastUpdateTime = 0;
bool paused = false;
bool eventTriggered(double interval);

int main()
{
    // Initialize Window with width, height, and name
    InitWindow(500, 620, "Tetris");

    // Set FPS
    SetTargetFPS(30);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Game game = Game();
 
    while (WindowShouldClose() == false)
    {
        // Pause
        if (IsKeyPressed(KEY_ENTER))
        {
            paused = !paused;
        }

        // Checks to pause
        if (!paused)
        {
            // Handles music
            UpdateMusicStream(game.music);

            // Handle inputs
            game.handleInput();

            // Speed of the game

            if (eventTriggered(game.speed))
            {
                game.moveBlockDown();
            }
        }

        
        BeginDrawing();
        ClearBackground(GRAY);

        // UI
        DrawTextEx(font, "Score", { 350, 15 }, 38, 2, WHITE);
        char scoreText[10];
        sprintf_s(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, BLACK);
        DrawTextEx(font, scoreText, { 320 + ((170 - textSize.x) / 2), 65}, 38, 2, WHITE);


        DrawTextEx(font, "Next", { 365, 175 }, 38, 2, WHITE);
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, BLACK);

        // Level
        DrawTextEx(font, "Level:", { 340, 460 }, 32, 2, WHITE);
        char levelText[10];
        sprintf_s(levelText, "%d", game.level);
        DrawTextEx(font, levelText, {450, 458 }, 38, 2, WHITE);

        if (game.gameOver)
        {
            DrawTextEx(font, "Game Over", { 320, 550 }, 32, 2, WHITE);
        }

        game.draw();

        // Paused
        if (paused)
        {
            DrawTextEx(font, "Pause", { 90, 275 }, 62, 2, RED);
        }

        EndDrawing();
    }
    CloseWindow();
}

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
