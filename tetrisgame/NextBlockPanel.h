#pragma once
#include "GameBoard.h"
#include "Tetris.h"
class NextBlockPanel : public CStatic
{

    public:
        NextBlockPanel();
        virtual ~NextBlockPanel();
    protected:
        afx_msg void OnPaint();
        DECLARE_MESSAGE_MAP()
        Tetris game;
};

