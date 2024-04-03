#pragma once
#include "../Tetris-Core/GameBoard.h"
#include "../Tetris-Core/Block.h"
#include "Tetris.h"
#include "resource.h"
#include <vector>

class TetrisPanel : public CStatic
{
public:
    TetrisPanel();
    virtual ~TetrisPanel();
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnPaint();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    void PressRestartButt();
protected:
    DECLARE_MESSAGE_MAP()
private:
    Tetris *game;  // Tetris 게임 객체 추가
    CString m_strMessage;
    bool isGameOver;
    void HandleGameOverAndRestart();
};