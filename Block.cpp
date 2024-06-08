#include "Block.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
}

void Block::draw()
{
	std::vector<Position> tiles = cells[rotationState];
	for (Position item : tiles)
	{
		DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void Block::move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

void Block::rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}