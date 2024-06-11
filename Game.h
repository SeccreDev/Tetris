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
		void updateScore(int linesCleared, int moveDownPoints);
		Block getRandomBlock();
		std::vector<Block> getAllBlocks();
		void moveBlockLeft();
		void moveBlockRight();
		Board board;
		Sound rotateSound;
		Sound clearSound;

	public:
		bool gameOver;
		int score;
		Game();
		~Game();
		void draw();
		void handleInput();
		void moveBlockDown();
		void rotateBlock();
		Music music;


};

