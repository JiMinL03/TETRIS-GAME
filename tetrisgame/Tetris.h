#pragma once
#include "GameBoard.h"
#include "Block.h"
class Tetris
{
private:
    GameBoard gameBoard; // ���� ���带 ��Ÿ���� ����
    Tetris();
    Tetris(const Tetris& ref) {}
    Tetris& operator=(const Tetris& ref) {}
    ~Tetris() {}

public:
    static Tetris& getIncetance() {
        static Tetris s;
        return s;
    }

    void initGame();                   // ������ �ʱ�ȭ�ϴ� �Լ�
    void moveBlock(int direction = 0); // Down(Defalut) = 0, Left = 1, Right = 2, UP(DEBUG) = 3
    void rotateBlock();                // ����� ȸ����Ű�� �Լ�
    int* getBoard();                   // ���� ���带 ��ȯ�ϴ� �Լ�
    Block getNextBlock();              // ���� ����� ��ȯ�ϴ� �Լ�
    bool isGameOver();                 // ������ �������� Ȯ���ϴ� �Լ�
};
