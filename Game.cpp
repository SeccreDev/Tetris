#include "Game.h"

Game::Game()
{
	board = Board();
	blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	gameOver = false;
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

void Game::handleInput()
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		reset();
	}
	switch (keyPressed)
	{
		case KEY_LEFT:
			moveBlockLeft();
			break;
		case KEY_RIGHT:
			moveBlockRight();
			break;
		case KEY_UP:
			rotateBlock();
			break;
		case KEY_DOWN:
			moveBlockDown();
			break;
	}
}

void Game::moveBlockLeft()
{
	if (!gameOver)
	{
		currentBlock.move(0, -1);
		if (isBlockOutside() || blockFits() == false)
		{
			currentBlock.move(0, 1);
		}
	}
}

void Game::moveBlockRight()
{
	if (!gameOver)
	{
		currentBlock.move(0, 1);
		if (isBlockOutside() || blockFits() == false)
		{
			currentBlock.move(0, -1);
		}
	}
}

void Game::moveBlockDown()
{
	if (!gameOver)
	{
		currentBlock.move(1, 0);
		if (isBlockOutside() || blockFits() == false)
		{
			currentBlock.move(-1, 0);
			lockBlock();
		}
	}
}

void Game::rotateBlock()
{
	if (!gameOver)
	{
		currentBlock.rotate();
		if (isBlockOutside() || blockFits() == false)
		{
			currentBlock.undoRotation();
		}
	}
}

bool Game::isBlockOutside()
{
	std::vector <Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		if (board.isCellOutside(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::lockBlock()
{
	std::vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		board.board[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (blockFits() == false)
	{
		gameOver = true;
	}

	nextBlock = getRandomBlock();
	board.clearFullRows();
}

bool Game::blockFits()
{
	std::vector <Position> tiles = currentBlock.getCellPositions();
	for (Position items : tiles)
	{
		if (board.isCellEmpty(items.row, items.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::reset()
{
	board.setBoard();
	blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
}