#pragma once
#include "Board.h"
#include "Blocks.cpp"

class Game
{
	private:
		std::vector<Block> blocks;
		Block currentBlock;
		Block nextBlock;


	public:
		Game();
		Block getRandomBlock();
		std::vector<Block> getAllBlocks();
		void draw();
		Board board;



};

