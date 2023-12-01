// Block.h

#pragma once

class Block
{
private:
    int* block_arr;   // 블록의 모양을 나타내는 배열
    int width;        // 블록의 너비
    int height;       // 블록의 높이
    void initBlock(); // 블록을 초기화하는 함수(랜덤으로 블록을 생성)

public:
    Block();
    Block(const Block& other); // 복사 생성자
    ~Block();

    Block& operator=(const Block& other); // 대입 연산자 오버로딩

    void rotate();   // 블록을 회전시키는 함수
    int* getBlock(); // 블록을 반환하는 함수

    int getWidth() { return width; }
    int getHeight() { return height; }
};