#include <raylib.h>
#include "Board.h"
#include "Blocks.cpp"
#include <iostream>


int main()
{
    // Initialize Window with width, height, and name
    InitWindow(300, 600, "Tetris");

    // Set FPS
    SetTargetFPS(30);

    // Board
    Board board = Board();
    Lblock block = Lblock();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RED);
        board.draw();
        block.draw();
        EndDrawing();
    }
    CloseWindow();
}