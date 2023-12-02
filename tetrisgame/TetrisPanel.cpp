#include "pch.h"
#include "TetrisPanel.h"
#include "Tetris.h"
#include <iostream>
#include "tetrisgameDlg.h"
using namespace std;
TetrisPanel::TetrisPanel() {

}
TetrisPanel::~TetrisPanel() {

}

void TetrisPanel::OnTimer(UINT_PTR nIDEvent) {
    game.moveBlock(0);
    Invalidate();
    CStatic::OnTimer(nIDEvent);
}

BEGIN_MESSAGE_MAP(TetrisPanel, CStatic)
    ON_WM_PAINT()
    ON_WM_KEYDOWN()  // 키다운 이벤트 핸들러를 등록합니다.
    ON_WM_TIMER() // 타이머 이벤트 핸들러를 등록합니다.
END_MESSAGE_MAP()

void TetrisPanel::OnPaint() {

    CPaintDC dc(this);
    CRect rect;
    GetClientRect(&rect);

    int cellWidth = rect.Width() / 10;
    int cellHeight = rect.Height() / 17;


        for (int row = 0; row < 20; row++) {
            for (int col = 0; col < 10; col++) {
                int left = col * (cellWidth + 2);
                int top = row * (cellHeight + 2);
                int right = left + cellWidth;
                int bottom = top + cellHeight;

                CRect cellRect(left, top, right, bottom);
                dc.Rectangle(&cellRect);
                dc.FillSolidRect(&cellRect, RGB(220, 220, 215));
            }
        }

        int* board = game.getBoard();
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                int cellValue = board[y * BOARD_WIDTH + x];
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
        if (!game.isGameOver()) {
            isGameOver = true;
        }
        if (game.isGameOver() && isGameOver) {
            HandleGameOverAndRestart();
        }
	}

void TetrisPanel::HandleGameOverAndRestart()
{

        ((CtetrisgameDlg*)GetParent())->StopTimer();  // StopTimer 함수 호출
        int result = AfxMessageBox(_T("GAME OVER! Do you want to restart?"), MB_ICONERROR | MB_YESNO);
        if (result == IDYES) {//"예" 클릭한다면
            game.initGame();//게임 다시 시작하는 메서드
            Invalidate();//OnPaint 재실행
            ((CtetrisgameDlg*)GetParent())->StartTimer();
            isGameOver = false;
        }
        else { //"아니오"를 클릭한다면
            ((CtetrisgameDlg*)GetParent())->EndDialog(IDCANCEL); //종료   
        }
}

void TetrisPanel::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
    switch (nChar) {
    case VK_UP:
        game.rotateBlock();  // 위쪽 화살표 키 처리
        break;
    case VK_DOWN:
        game.moveBlock(0);  // 아래쪽 화살표 키 처리
        break;
    case VK_LEFT:
        game.moveBlock(1    );  // 왼쪽 화살표 키 처리
        break;
    case VK_RIGHT:
        game.moveBlock(2);  // 오른쪽 화살표 키 처리
        break;
    case 'Q':
        // 'Q' 키를 누르면 어플리케이션 종료
        AfxGetMainWnd()->PostMessage(WM_CLOSE);
        break;
    }

    // 화면 갱신을 위해 다시 그리기
    Invalidate();

    // 기본 동작 수행
    CStatic::OnKeyDown(nChar, nRepCnt, nFlags);
}
