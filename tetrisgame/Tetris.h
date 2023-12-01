#pragma once
#include "GameBoard.h"
#include "Block.h"
class Tetris
{
private:
    GameBoard gameBoard; // ���� ���带 ��Ÿ���� ����

public:
    Tetris();

    void initGame();                   // ������ �ʱ�ȭ�ϴ� �Լ�
    void moveBlock(int direction = 0); // Down(Defalut) = 0, Left = 1, Right = 2, UP(DEBUG) = 3
    void rotateBlock();                // ����� ȸ����Ű�� �Լ�
    int* getBoard();                   // ���� ���带 ��ȯ�ϴ� �Լ�
    Block getNextBlock();              // ���� ����� ��ȯ�ϴ� �Լ�
    bool isGameOver();                 // ������ �������� Ȯ���ϴ� �Լ�
};