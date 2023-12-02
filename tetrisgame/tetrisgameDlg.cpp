
// tetrisgameDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "tetrisgame.h"
#include "tetrisgameDlg.h"
#include "afxdialogex.h"
#include "TetrisPanel.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX); 


protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


CtetrisgameDlg::CtetrisgameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TETRISGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtetrisgameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtetrisgameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_START, &CtetrisgameDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CtetrisgameDlg 메시지 처리기


BOOL CtetrisgameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	//--------------------------------------------------------------------------------------------------

	SetWindowText(_T("TETRIS GAME")); //프레임 타이틀 제목 지정
	SetTimer(ID_AUTO_MOVE_TIMER, 750, nullptr);
	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect); 
	rect.top += 89;
	rect.left += 40; 
	rect.right += 40;
	m_TetrisPanel.Create(NULL, WS_CHILD | WS_VISIBLE, rect, this);
	CRect rectt;
	GetDlgItem(IDC_STATIC4)->GetClientRect(&rectt); 
	rectt.left -= 60;
	rectt.right += 100;
	rectt.right += 100;
	rectt.bottom += 150;
	rectt.OffsetRect(100, 0);
	m_NextBlockPanel.Create(NULL, WS_CHILD | WS_VISIBLE, rectt, GetDlgItem(IDC_STATIC4));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}
BOOL CtetrisgameDlg::PreTranslateMessage(MSG* pMsg)
{	
	if (pMsg->message == WM_KEYDOWN)
	{

		// TetrisPanel에게 키 이벤트 전달
		m_TetrisPanel.OnKeyDown(pMsg->wParam, 1, 0);
		// 여기서 return TRUE를 하면 이벤트를 더 이상 전달하지 않습니다.
		// return TRUE;
	}

	// 기본 동작 수행
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CtetrisgameDlg::OnTimer(UINT_PTR nIDEvent)
{
	// 타이머 이벤트 처리
	if (nIDEvent == ID_AUTO_MOVE_TIMER)
	{

		// TetrisPanel의 ontimer 이벤트 호출
		m_TetrisPanel.OnTimer(nIDEvent);
	}

	CDialogEx::OnTimer(nIDEvent);
}
void CtetrisgameDlg::StopTimer()
{
	// ID_AUTO_MOVE_TIMER 타이머를 중지
	KillTimer(ID_AUTO_MOVE_TIMER);
}
void CtetrisgameDlg::StartTimer()
{
	// ID_AUTO_MOVE_TIMER 타이머를 중지
	SetTimer(ID_AUTO_MOVE_TIMER, 750, nullptr);
}
//--------------------------------------------------------------------------------------------------
void CtetrisgameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


void CtetrisgameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CtetrisgameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CtetrisgameDlg::OnBnClickedStart()
{
	
}