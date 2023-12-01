// GameBoard.cpp
#include "pch.h"
#include "GameBoard.h"

GameBoard::GameBoard()
{
    board = new int[BOARD_WIDTH * BOARD_HEIGHT];
    clearBoard();
    this->isGameOver = false;
}

// 보드 정보 + 현재 블록 정보 반환
int* GameBoard::getBoard()
{
    int* board = new int[BOARD_WIDTH * BOARD_HEIGHT];
    for (int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++)
    {
        board[i] = this->board[i];
    }

    for (int y = 0; y < currentBlock.getHeight(); y++)
    {
        for (int x = 0; x < currentBlock.getWidth(); x++)
        {
            if (currentBlock.getBlock()[y * currentBlock.getWidth() + x] != 0)
            {
                board[(currentY + y) * BOARD_WIDTH + (currentX + x)] = currentBlock.getBlock()[y * currentBlock.getWidth() + x];
            }
        }
    }

    return board;
}

void GameBoard::clearBoard()
{
    for (int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++)
    {
        board[i] = 0;
    }
    currentBlock = Block();
    nextBlock = Block();
    currentX = 4;
    currentY = 0;
}

void GameBoard::rotateBlock()
{
    if (isCollision())
    {
        return;
    }
    currentBlock.rotate();
}

void GameBoard::moveBlock(int direction)
{
    if (isCollision(direction) && direction == 0)
    {
        fixToBoard();
        loadNextBlock();
        return;
    }
    else if (isCollision(direction))
    {
        return;
    }

    switch (direction)
    {
    case 0: // Down
        currentY++;
        break;
    case 1: // Left
        currentX--;
        break;
    case 2: // Right
        currentX++;
        break;
    case 3: // UP
        currentY--;
        break;
    default:
        break;
    }
}

bool GameBoard::isCollision()
{
    Block temp = currentBlock;
    temp.rotate();
    for (int y = 0; y < temp.getHeight(); y++)
    {
        for (int x = 0; x < temp.getWidth(); x++)
        {
            if (temp.getBlock()[y * temp.getWidth() + x] != 0)
            {
                if (currentY + y >= BOARD_HEIGHT || currentX + x < 0 || currentX + x >= BOARD_WIDTH)
                {
                    return true;
                }
                if (board[(currentY + y) * BOARD_WIDTH + (currentX + x)] != 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool GameBoard::isCollision(int direction)
{

    int destinationX = currentX;
    int destinationY = currentY;

    switch (direction)
    {
    case 0: // Down
        destinationY++;
        break;
    case 1: // Left
        destinationX--;
        break;
    case 2: // Right
        destinationX++;
        break;
    case 3: // UP
        destinationY--;
        break;
    default:
        break;
    }

    for (int y = 0; y < currentBlock.getHeight(); y++)
    {
        for (int x = 0; x < currentBlock.getWidth(); x++)
        {
            if (currentBlock.getBlock()[y * currentBlock.getWidth() + x] != 0)
            {
                if (destinationY + y >= BOARD_HEIGHT || destinationX + x < 0 || destinationX + x >= BOARD_WIDTH)
                {
                    return true;
                }
                if (board[(destinationY + y) * BOARD_WIDTH + (destinationX + x)] != 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void GameBoard::fixToBoard()
{
    for (int y = 0; y < currentBlock.getHeight(); y++)
    {
        for (int x = 0; x < currentBlock.getWidth(); x++)
        {
            if (currentBlock.getBlock()[y * currentBlock.getWidth() + x] != 0)
            {
                board[(currentY + y) * BOARD_WIDTH + (currentX + x)] = currentBlock.getBlock()[y * currentBlock.getWidth() + x];
            }
        }
    }

    int line = checkLine();
    while (line != -1)
    {
        clearLine(line);
        moveLine(line);
        line = checkLine();
    }
}

void GameBoard::loadNextBlock()
{
    // 현재 블록을 다음 블록으로 바꾸고 다음 블록을 새로 생성
    currentBlock = nextBlock;
    currentX = 4;
    currentY = 0;
    nextBlock = Block();

    // 다음 블록이 생성되었을 때 충돌이 일어나면 게임 오버
    if (checkGameOver())
    {
        isGameOver = true;
    }
}

int GameBoard::checkLine()
{
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        bool isLine = true;
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            if (board[y * BOARD_WIDTH + x] == 0)
            {
                isLine = false;
                break;
            }
        }
        if (isLine)
        {
            return y;
        }
    }

    return -1;
}

void GameBoard::clearLine(int y)
{
    for (int x = 0; x < BOARD_WIDTH; x++)
    {
        board[y * BOARD_WIDTH + x] = 0;
    }
}

void GameBoard::moveLine(int y)
{
    for (int i = y; i > 0; i--)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            board[i * BOARD_WIDTH + x] = board[(i - 1) * BOARD_WIDTH + x];
        }
    }
}

bool GameBoard::isOver()
{
    return isGameOver;
}

bool GameBoard::checkGameOver()
{
    for (int x = 0; x < BOARD_WIDTH; x++)
    {
        if (board[x] != 0)
        {
            isGameOver = true;
            return true;
        }
    }
    return false;
}

Block GameBoard::getNextBlock()
{
    return nextBlock;
}