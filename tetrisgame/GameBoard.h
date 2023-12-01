// GameBoard.h

#pragma once

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

#include "Block.h"

class GameBoard
{
private:
    int* board;             // ���� ���¸� �����ϴ� �迭
    Block currentBlock;     // ���� ����� ��Ÿ���� ����
    int currentX, currentY; // ���� ����� ��ġ�� ��Ÿ���� ����
    Block nextBlock;        // ���� ����� ��Ÿ���� ����
    bool isGameOver;        // ������ �������� ��Ÿ���� ����

    bool isCollision();              // ����� ȸ����Ű�� �浹�� �Ͼ���� Ȯ���ϴ� �Լ�
    bool isCollision(int direction); // ����� �̵���Ű�� �浹�� �Ͼ���� Ȯ���ϴ� �Լ�
    void fixToBoard();               // ����� ���忡 ������Ű�� �Լ�
    void loadNextBlock();            // ���� ����� �ҷ����� �Լ�
    int checkLine();                 // ���� ������ �ִ��� Ȯ���ϰ� �ִٸ� � �������� ��ȯ�ϴ� �Լ� (���ٸ� -1 ��ȯ)
    void clearLine(int y);           // �ش� ������ ����� �Լ�
    void moveLine(int y);            // �ش� ���� ���� ���ε��� ��ĭ�� ������ �Լ�
    bool checkGameOver();            // ������ �������� Ȯ���ϴ� �Լ�

public:
    GameBoard();
    int* getBoard();                   // ���带 ��ȯ�ϴ� �Լ�
    void clearBoard();                 // ���� ���带 �ʱ�ȭ�ϴ� �Լ�
    void rotateBlock();                // ����� ȸ����Ű�� �Լ�
    void moveBlock(int direction = 0); // Down(Defalut) = 0, Left = 1, Right = 2, UP(DEBUG) = 3
    bool isOver();                     // ������ �������� Ȯ���ϴ� �Լ�
    Block getNextBlock();              // ���� ����� ��ȯ�ϴ� �Լ�
};