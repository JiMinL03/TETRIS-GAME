#pragma once
#include "GameBoard.h"
#include "Block.h"
#include "Tetris.h"
#include "resource.h"

class TetrisPanel : public CStatic
{
public:
    TetrisPanel();
    virtual ~TetrisPanel();
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
    afx_msg void OnPaint();
    DECLARE_MESSAGE_MAP()
private:
    Tetris game;  // Tetris 게임 객체 추가
    CString m_strMessage;
};