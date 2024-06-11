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
			DrawRectangle(j * cellSize + 11, i * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
}

bool Board::isCellOutside(int row, int column)
{
	if (row >= 0 && row < rows && column >= 0 && column < columns)
	{
		return false;
	}
	return true;
}

bool Board::isCellEmpty(int row, int column)
{
	if (board[row][column] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Board::clearFullRows()
{
	int completed = 0;
	for (int row = rows - 1; row >= 0; row--)
	{
		if (isRowFull(row))
		{
			clearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			moveRowDown(row, completed);
		}
	}
	return completed;
}

bool Board::isRowFull(int row)
{
	for (int column = 0; column < columns; column++)
	{
		if (board[row][column] == 0)
		{
			return false;
		}
	}
		return true;
}

void Board::clearRow(int row)
{
	for (int column = 0; column < columns; column++)
	{
		board[row][column] = 0;
	}
}

void Board::moveRowDown(int row, int numRows)
{
	for (int column = 0; column < columns; column++)
	{
		board[row + numRows][column] = board[row][column];
		board[row][column] = 0;
	}
}
