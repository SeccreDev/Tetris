#include "Board.h"
#include <iostream>
#include "Colors.h"

Board::Board()
{
	rows = 20;
	columns = 10;
	cellSize = 30;
	setBoard();
	colors = GetCellColors();
}

void Board::setBoard()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			board[i][j] = 0;
		}
	}
}

void Board::showBoard() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << '\n';
	}
}


void Board::draw()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int cellValue = board[i][j];
			DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
}

