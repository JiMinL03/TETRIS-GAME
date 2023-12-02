#include "pch.h"
#include "NextBlockPanel.h"

NextBlockPanel::NextBlockPanel() {

}
NextBlockPanel::~NextBlockPanel() {

}

BEGIN_MESSAGE_MAP(NextBlockPanel, CStatic)
    ON_WM_PAINT()
END_MESSAGE_MAP()

void NextBlockPanel::OnPaint() {
    CPaintDC dc(this);
    CRect rectt;
    GetClientRect(&rectt);

    int cellWidth = rectt.Width() / 10;  // 각 셀의 너비
    int cellHeight = rectt.Height() / 8;  // 각 셀의 높이

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            int left = col * (cellWidth + 2);  // 각 사각형의 왼쪽 좌표에 2의 여백을 추가
            int top = row * (cellHeight + 2);
            int right = left + cellWidth;
            int bottom = top + cellHeight;

            CRect cellRect(left, top, right, bottom);
            dc.Rectangle(&cellRect);
            dc.FillSolidRect(&cellRect, RGB(220, 220, 215));
        }
    }

    Block board = game.getNextBlock();
    int blockWidth = board.getWidth();
    int blockHeight = board.getHeight();
    for (int y = 0; y < blockWidth; y++) {
        for (int x = 0; x < blockHeight; x++) {
            int cellValue = board.getBlock()[x * BOARD_WIDTH + y];
            if (cellValue != 0) {
                int left = x * (cellWidth + 2);
                int top = y * (cellHeight + 2);
                int right = left + cellWidth;
                int bottom = top + cellHeight;

                CRect cellRect(left, top, right, bottom);
                dc.Rectangle(&cellRect);
                if (cellValue == 1) {
                    dc.FillSolidRect(&cellRect, RGB(255, 0, 0));
                }
                else if (cellValue == 2) {
                    dc.FillSolidRect(&cellRect, RGB(255, 165, 0));
                }
                else if (cellValue == 3) {
                    dc.FillSolidRect(&cellRect, RGB(70, 130, 180));
                }
                else if (cellValue == 4) {
                    dc.FillSolidRect(&cellRect, RGB(0, 200, 0));
                }
                else if (cellValue == 5) {
                    dc.FillSolidRect(&cellRect, RGB(0, 0, 200));
                }
                else if (cellValue == 6) {
                    dc.FillSolidRect(&cellRect, RGB(255, 105, 180));
                }
                else if (cellValue == 7) {
                    dc.FillSolidRect(&cellRect, RGB(128, 0, 200));
                }
            }
        }
    }
}
