
// tetrisgameDlg.h: 헤더 파일
//

#pragma once
#include "TetrisPanel.h"
#include "NextBlockPanel.h"


// CtetrisgameDlg 대화 상자
class CtetrisgameDlg : public CDialogEx
{
// 생성입니다.
public:
	CtetrisgameDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	afx_msg void StopTimer();
	afx_msg void StartTimer();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TETRISGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	
// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	TetrisPanel m_TetrisPanel;
	NextBlockPanel m_NextBlockPanel;

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
public:
	afx_msg void OnBnClickedStart();
};
