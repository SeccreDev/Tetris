#include "Board.h"

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

std::vector <Color> Board::GetCellColors()
{

	Color eerieBlack = { 27, 32, 33, 255 };
	Color vanilla = { 227, 220, 149, 255 };
	Color pearl = { 227, 220, 194, 255 };
	Color hunterGreen = { 56, 102, 65, 255 };
	Color navy = { 0, 0, 128, 255 };
	Color mountPink = { 148, 110, 131 };
	Color roseWood = { 107, 15, 26, 255 };
	Color buff = { 223, 160, 110, 255 };
	return { eerieBlack, vanilla, pearl, hunterGreen, navy, mountPink, roseWood, buff };
}


void Board::draw()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int cellValue = board[i][j];
			std::cout << cellValue;
			DrawRectangle(columns * cellSize + 1, rows * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
	std::cout << "\nFinished;";
}

