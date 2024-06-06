#pragma once
#include <vector>
#include <raylib.h>

class Board
{
	private:
		int rows;
		int columns;
		int cellSize;
		std::vector <Color> colors;

	public:
		int board[20][10];
		Board();
		void setBoard();
		void showBoard() const;
		void draw();
};

