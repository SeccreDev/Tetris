#include <raylib.h>
#include "Game.h"


int main()
{
    // Initialize Window with width, height, and name
    InitWindow(300, 600, "Tetris");

    // Set FPS
    SetTargetFPS(30);

    Game game = Game();
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);
        game.draw();
        EndDrawing();
    }
    CloseWindow();
}