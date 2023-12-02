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
    ON_WM_KEYDOWN()  // Ű�ٿ� �̺�Ʈ �ڵ鷯�� ����մϴ�.
    ON_WM_TIMER() // Ÿ�̸� �̺�Ʈ �ڵ鷯�� ����մϴ�.
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

        ((CtetrisgameDlg*)GetParent())->StopTimer();  // StopTimer �Լ� ȣ��
        int result = AfxMessageBox(_T("GAME OVER! Do you want to restart?"), MB_ICONERROR | MB_YESNO);
        if (result == IDYES) {//"��" Ŭ���Ѵٸ�
            game.initGame();//���� �ٽ� �����ϴ� �޼���
            Invalidate();//OnPaint �����
            ((CtetrisgameDlg*)GetParent())->StartTimer();
            isGameOver = false;
        }
        else { //"�ƴϿ�"�� Ŭ���Ѵٸ�
            ((CtetrisgameDlg*)GetParent())->EndDialog(IDCANCEL); //����   
        }
}

void TetrisPanel::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
    switch (nChar) {
    case VK_UP:
        game.rotateBlock();  // ���� ȭ��ǥ Ű ó��
        break;
    case VK_DOWN:
        game.moveBlock(0);  // �Ʒ��� ȭ��ǥ Ű ó��
        break;
    case VK_LEFT:
        game.moveBlock(1    );  // ���� ȭ��ǥ Ű ó��
        break;
    case VK_RIGHT:
        game.moveBlock(2);  // ������ ȭ��ǥ Ű ó��
        break;
    case 'Q':
        // 'Q' Ű�� ������ ���ø����̼� ����
        AfxGetMainWnd()->PostMessage(WM_CLOSE);
        break;
    }

    // ȭ�� ������ ���� �ٽ� �׸���
    Invalidate();

    // �⺻ ���� ����
    CStatic::OnKeyDown(nChar, nRepCnt, nFlags);
}
