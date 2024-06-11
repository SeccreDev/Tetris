#pragma once
#include "Board.h"
#include "Blocks.cpp"

class Game
{
	private:
		std::vector<Block> blocks;
		Block currentBlock;
		Block nextBlock;
		bool isBlockOutside();
		void lockBlock();
		bool blockFits();
		void reset();


	public:
		bool gameOver;
		Game();
		Block getRandomBlock();
		std::vector<Block> getAllBlocks();
		void draw();
		Board board;

		void handleInput();
		void moveBlockLeft();
		void moveBlockRight();
		void moveBlockDown();
		void rotateBlock();


};

