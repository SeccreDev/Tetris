#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
	private:
		int cellSize;
		int rotationState;
		int rowOffset;
		int columnOffset;
		std::vector <Color> colors;

	public:
		int id;
		std::map<int, std::vector<Position>> cells;
		Block();
		void draw(int offsetX, int offsetY);
		std::vector<Position> getCellPositions();
		void move(int rows, int columns);
		void rotate();
		void undoRotation();


};

