#include <raylib.h>
#include "Board.h"
#include <iostream>


int main()
{
    // Initialize Window with width, height, and name
    InitWindow(300, 600, "Tetris");
    Color vanilla = { 227, 220, 149, 255 };
    // Set FPS
    SetTargetFPS(30);

    // Board
    Board board = Board();
    board.showBoard();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(vanilla);
        board.draw();

        EndDrawing();
    }
    CloseWindow();
}