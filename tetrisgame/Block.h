// Block.h

#pragma once

class Block
{
private:
    int* block_arr;   // ����� ����� ��Ÿ���� �迭
    int width;        // ����� �ʺ�
    int height;       // ����� ����
    void initBlock(); // ����� �ʱ�ȭ�ϴ� �Լ�(�������� ����� ����)

public:
    Block();
    Block(const Block& other); // ���� ������
    ~Block();

    Block& operator=(const Block& other); // ���� ������ �����ε�

    void rotate();   // ����� ȸ����Ű�� �Լ�
    int* getBlock(); // ����� ��ȯ�ϴ� �Լ�

    int getWidth() { return width; }
    int getHeight() { return height; }
};