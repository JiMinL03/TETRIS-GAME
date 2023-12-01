// Block.cpp
#include "pch.h"
#include "Block.h"
#include <stdlib.h>
#include <time.h>

Block::Block()
{
    initBlock();
};

Block::~Block()
{
    // ��� �Ҹ��� ����
    delete[] block_arr;
}

// ���� ������ ����
Block::Block(const Block& other)
{
    width = other.width;
    height = other.height;

    // �޸� �Ҵ� �� ����
    block_arr = new int[width * height];
    for (int i = 0; i < width * height; i++)
    {
        block_arr[i] = other.block_arr[i];
    }

    return;
}

void Block::rotate()
{
    // ��� ȸ�� ����

    int* temp = new int[width * height];

    for (int i = 0; i < width * height; i++)
    {
        temp[i] = block_arr[i];
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
            block_arr[i * height + j] = temp[(height - j - 1) * width + i];
    }

    int temp_width = width;
    width = height;
    height = temp_width;
}

int* Block::getBlock()
{
    return block_arr;
}

void Block::initBlock()
{

    srand((unsigned int)time(NULL));
    int random = rand() % 7 + 1;

    switch (random)
    {
    case 1:
        block_arr = new int[2 * 2]{ 1, 1,
                                   1, 1 };
        width = 2;
        height = 2;
        break;
    case 2:
        block_arr = new int[2 * 3]{ 2, 0,
                                   2, 0,
                                   2, 2 };
        width = 2;
        height = 3;
        break;

    case 3:
        block_arr = new int[2 * 3]{ 0, 3,
                                   0, 3,
                                   3, 3 };
        width = 2;
        height = 3;
        break;

    case 4:
        block_arr = new int[4 * 1]{ 4, 4, 4, 4 };
        width = 4;
        height = 1;

        break;

    case 5:
        block_arr = new int[3 * 2]{ 0, 5, 0,
                                   5, 5, 5 };
        width = 3;
        height = 2;

        break;

    case 6:
        block_arr = new int[3 * 2]{ 0, 6, 6,
                                   6, 6, 0 };
        width = 3;
        height = 2;

        break;

    case 7:
        block_arr = new int[3 * 2]{ 7, 7, 0,
                                   0, 7, 7 };
        width = 3;
        height = 2;

        break;
    }

    return;
}

// ���� ������ ����
Block& Block::operator=(const Block& other)
{
    if (this != &other)
    {
        // ���� ��ü�� �ڿ��� �����ϰ� �ٽ� �Ҵ�
        delete[] block_arr;

        width = other.width;
        height = other.height;

        // �޸� �Ҵ� �� ����
        block_arr = new int[width * height];
        for (int i = 0; i < width * height; i++)
        {
            block_arr[i] = other.block_arr[i];
        }
    }

    return *this;
}