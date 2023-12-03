#pragma once
#include "GameBoard.h"
#include "Block.h"
class Tetris
{
private:
    GameBoard gameBoard; // 게임 보드를 나타내는 변수
    Tetris();
    Tetris(const Tetris& ref) {}
    Tetris& operator=(const Tetris& ref) {}
    ~Tetris() {}

public:
    static Tetris& getIncetance() {
        static Tetris s;
        return s;
    }

    void initGame();                   // 게임을 초기화하는 함수
    void moveBlock(int direction = 0); // Down(Defalut) = 0, Left = 1, Right = 2, UP(DEBUG) = 3
    void rotateBlock();                // 블록을 회전시키는 함수
    int* getBoard();                   // 게임 보드를 반환하는 함수
    Block getNextBlock();              // 다음 블록을 반환하는 함수
    bool isGameOver();                 // 게임이 끝났는지 확인하는 함수
};
