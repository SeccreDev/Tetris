#include <raylib.h>
#include "Game.h"

double lastUpdateTime = 0;
bool eventTriggered(double interval);

int main()
{
    // Initialize Window with width, height, and name
    InitWindow(300, 600, "Tetris");

    // Set FPS
    SetTargetFPS(30);

    Game game = Game();
    while (WindowShouldClose() == false)
    {
        game.handleInput();
        if (eventTriggered(0.02))
        {
            game.moveBlockDown();
        }

        BeginDrawing();
        ClearBackground(RED);
        game.draw();
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
