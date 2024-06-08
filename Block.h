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
		std::vector <Color> colors;

	public:
		Block();
		void draw();
		void Move(int rows, int columns);
		int id;
		std::map<int, std::vector<Position>> cells;

};

