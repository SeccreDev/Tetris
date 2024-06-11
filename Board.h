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
		bool isRowFull(int row);
		void clearRow(int row);
		void moveRowDown(int row, int numRows);

	public:
		int board[20][10];
		Board();
		void setBoard();
		void showBoard() const;
		void draw();
		bool isCellOutside(int row, int column);
		bool isCellEmpty(int row, int column);
		int clearFullRows();
};

