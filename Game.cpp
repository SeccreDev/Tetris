#include "Game.h"

Game::Game()
{
	board = Board();
	blocks = getAllBlocks();
	Block currentBlock = getRandomBlock();
	Block nextBlock = getRandomBlock();
}

Block Game::getRandomBlock()
{
	if (blocks.empty())
	{
		blocks = getAllBlocks();
	}

	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block> Game::getAllBlocks()
{
	return { Iblock(), Jblock(), Lblock(), Oblock(), Sblock(), Tblock(), Zblock() };
}

void Game::draw()
{
	board.draw();
	currentBlock.draw();
}