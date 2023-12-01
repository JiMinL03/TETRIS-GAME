// GameBoard.h

#pragma once

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

#include "Block.h"

class GameBoard
{
private:
    int* board;             // 보드 상태를 저장하는 배열
    Block currentBlock;     // 현재 블록을 나타내는 변수
    int currentX, currentY; // 현재 블록의 위치를 나타내는 변수
    Block nextBlock;        // 다음 블록을 나타내는 변수
    bool isGameOver;        // 게임이 끝났는지 나타내는 변수

    bool isCollision();              // 블록을 회전시키고 충돌이 일어나는지 확인하는 함수
    bool isCollision(int direction); // 블록을 이동시키고 충돌이 일어나는지 확인하는 함수
    void fixToBoard();               // 블록을 보드에 고정시키는 함수
    void loadNextBlock();            // 다음 블록을 불러오는 함수
    int checkLine();                 // 꽉찬 라인이 있는지 확인하고 있다면 어떤 라인인지 반환하는 함수 (없다면 -1 반환)
    void clearLine(int y);           // 해당 라인을 지우는 함수
    void moveLine(int y);            // 해당 라인 위의 라인들을 한칸씩 내리는 함수
    bool checkGameOver();            // 게임이 끝났는지 확인하는 함수

public:
    GameBoard();
    int* getBoard();                   // 보드를 반환하는 함수
    void clearBoard();                 // 게임 보드를 초기화하는 함수
    void rotateBlock();                // 블록을 회전시키는 함수
    void moveBlock(int direction = 0); // Down(Defalut) = 0, Left = 1, Right = 2, UP(DEBUG) = 3
    bool isOver();                     // 게임이 끝났는지 확인하는 함수
    Block getNextBlock();              // 다음 블록을 반환하는 함수
};