#include "pch.h"
#include "Tetris.h"

Tetris::Tetris()
{
    gameBoard = GameBoard();
}

void Tetris::initGame()
{
    gameBoard.clearBoard();
}

void Tetris::moveBlock(int direction)
{
    gameBoard.moveBlock(direction);
}

void Tetris::rotateBlock()
{
    gameBoard.rotateBlock();
}

bool Tetris::isGameOver()
{
    return gameBoard.isOver();
}

Block Tetris::getNextBlock()
{
    return gameBoard.getNextBlock();
}

int* Tetris::getBoard()
{
    return gameBoard.getBoard();
}