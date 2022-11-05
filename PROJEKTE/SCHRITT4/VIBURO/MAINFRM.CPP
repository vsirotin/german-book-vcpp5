// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ViBuro.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_ARBEIT_Aufgaben, OnArbeitAufgaben)
	ON_COMMAND(ID_ARBEIT_BERICHT, OnArbeitBericht)
	ON_UPDATE_COMMAND_UI(ID_ARBEIT_BERICHT, OnUpdateArbeitBericht)
	ON_COMMAND(ID_ARBEIT_EINSTELLUNGEN, OnArbeitEinstellungen)
	ON_UPDATE_COMMAND_UI(ID_ARBEIT_Aufgaben, OnUpdateArbeitAufgaben)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CMDIFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CMDIFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CMDIFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CMDIFrameWnd::OnHelpFinder)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_SITZUNG_DAUER,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndStatusBar.SetPaneInfo(1, ID_SITZUNG_DAUER, SBPS_POPOUT, 100);
	//m_wndStatusBar.SetPaneInfo(0, ID_SITZUNG_DAUER, SBPS_POPOUT, 100);
	
	SetTimer(ID_TIMER, 1000, NULL);

	
	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CMDIFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnArbeitAufgaben() 
{

	if(theApp.m_pAufgabenDoc == NULL)
	{
		ASSERT_VALID(theApp.m_pDocTemplateAufgaben);

		theApp.m_pAufgabenDoc =  (CEdDoc*)theApp.m_pDocTemplateAufgaben
			->OpenDocumentFile("Aufgaben.txt", TRUE);
	}
}

void CMainFrame::OnArbeitBericht() 
{
	// TODO: Add your command handler code here

	if(theApp.m_pBerichtDoc == NULL)
	{
		ASSERT_VALID(theApp.m_pDocTemplateBericht);

		theApp.m_pBerichtDoc =  (CEdDoc*)theApp.m_pDocTemplateBericht
			->OpenDocumentFile("Bericht.txt", TRUE);
	}
}



void CMainFrame::OnUpdateArbeitBericht(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(theApp.m_pBerichtDoc != NULL)
		pCmdUI->SetCheck(1);
	else 
		pCmdUI->SetCheck(0);
	
}

void CMainFrame::OnArbeitEinstellungen() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUpdateArbeitAufgaben(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(theApp.m_pAufgabenDoc != NULL)
		pCmdUI->SetCheck(1);
	else 
		pCmdUI->SetCheck(0);
}


void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(nIDEvent == ID_TIMER)
	{
				
		time_t t0, currentTime;
		static CTimeSpan beginSitzung;
		if(!theApp.m_bTimeInitialized)
		{
			time(&t0);
			beginSitzung = CTimeSpan(t0);
			theApp.m_bTimeInitialized = TRUE;
		}
		CTimeSpan curr = CTimeSpan(time(&currentTime));
		theApp.m_timeSitzungDauer = curr - beginSitzung;
		CString sRes = theApp.m_timeSitzungDauer.Format("Sitzung: %D : %M : %S");

		m_wndStatusBar.SetPaneText(1, sRes, TRUE);

	}

	CMDIFrameWnd::OnTimer(nIDEvent);
}
