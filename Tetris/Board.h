#pragma once
#include <vector>
#include <raylib.h>
#include <iostream>


class Board
{
	private:
		int rows;
		int columns;
		int cellSize;
		int board[20][10];
		std::vector <Color> colors;
		std::vector <Color> GetCellColors();

	public:
		Board();
		void setBoard();
		void showBoard() const;
		void draw();


};

