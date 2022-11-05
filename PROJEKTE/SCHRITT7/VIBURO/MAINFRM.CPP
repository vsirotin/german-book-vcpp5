// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ViBuro.h"

#include "MainFrm.h"
#include "Option.h"

//#include <afxpriv.h>

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
	ON_COMMAND(ID_ARBEIT_AUFGABE, OnArbeitAufgabe)
	ON_COMMAND(ID_ARBEIT_BERICHT, OnArbeitBericht)
	ON_UPDATE_COMMAND_UI(ID_ARBEIT_BERICHT, OnUpdateArbeitBericht)
	ON_COMMAND(ID_ARBEIT_EINSTELLUNGEN, OnArbeitEinstellungen)
	ON_UPDATE_COMMAND_UI(ID_ARBEIT_AUFGABE, OnUpdateArbeitAufgabe)
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

void CMainFrame::OnArbeitAufgabe() 
{

	if(theApp.m_pAufgabeDoc == NULL)
	{
		ASSERT_VALID(theApp.m_pDocTemplateAufgabe);

		theApp.m_pAufgabeDoc =  (CEdDoc*)theApp.m_pDocTemplateAufgabe
			->OpenDocumentFile("Aufgaben.via", TRUE);
	}
}

void CMainFrame::OnArbeitBericht() 
{
	// TODO: Add your command handler code here

	if(theApp.m_pBerichtDoc == NULL)
	{
		ASSERT_VALID(theApp.m_pDocTemplateBericht);

		theApp.m_pBerichtDoc =  (CEdDoc*)theApp.m_pDocTemplateBericht
			->OpenDocumentFile("Bericht.vib", TRUE);
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
	OnProperties();
}

void CMainFrame::OnUpdateArbeitAufgabe(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(theApp.m_pAufgabeDoc != NULL)
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

void CMainFrame::OnProperties()
{
	// TODO: The property sheet attached to your project
	// via this function is not hooked up to any message
	// handler.  In order to actually use the property sheet,
	// you will need to associate this function with a control
	// in your project such as a menu item or tool bar button.

	COptionSheet propSheet;

	propSheet.SetTitle("Einstellungen", 0);

	propSheet.m_psh.dwFlags = 
		propSheet.m_psh.dwFlags|PSH_NOAPPLYNOW;
 
	if(propSheet.DoModal() == IDOK)
	{

		//Kartei "Paßwort"
		theApp.m_sPassword = propSheet.m_Page2.m_sPassword;
		theApp.WriteProfileString("Paßwort", "Paßwort", theApp.m_sPassword);

		//Kartei "Konto"
		theApp.m_sBLZ = propSheet.m_Page3.m_sBLZ;
		theApp.m_sGeldInstitut = propSheet.m_Page3.m_sGeldInstitut;
		theApp.m_sKontoStadt = propSheet.m_Page3.m_sKontoStadt;
		theApp.m_sKonto = propSheet.m_Page3.m_sKonto;
		
		theApp.WriteProfileString("Konto", "BLZ", theApp.m_sBLZ);
		theApp.WriteProfileString("Konto", "Bank", theApp.m_sGeldInstitut);
		theApp.WriteProfileString("Konto", "Stadt", theApp.m_sKontoStadt);
		theApp.WriteProfileString("Konto", "Kontonummer", theApp.m_sKonto);

		//Kartei "Adresse"
		theApp.m_sPLZ = propSheet.m_Page4.m_sPLZ;
		theApp.m_sStadt = propSheet.m_Page4.m_sStadt;
		theApp.m_sStrasse = propSheet.m_Page4.m_sStrasse;
		theApp.m_sTelefon = propSheet.m_Page4.m_sTelefon;

		theApp.WriteProfileString("Adresse", "PLZ", theApp.m_sPLZ);
		theApp.WriteProfileString("Adresse", "Stadt", theApp.m_sStadt);
		theApp.WriteProfileString("Adresse", "Straße", theApp.m_sStrasse);
		theApp.WriteProfileString("Adresse", "Telefon", theApp.m_sTelefon);

		//Kartei "Name"
		theApp.m_sName = propSheet.m_Page5.m_sName;
		theApp.m_sVorname = propSheet.m_Page5.m_sVorname;
		theApp.m_nNameJahr = propSheet.m_Page5.m_nNameJahr;
		theApp.m_nNameMonat = propSheet.m_Page5.m_nNameMonat;
		theApp.m_nNameTag = propSheet.m_Page5.m_nNameTag;
		
		theApp.WriteProfileString("Name", "Name", theApp.m_sName);
		theApp.WriteProfileString("Name", "Vorname", theApp.m_sVorname);
		theApp.WriteProfileInt("Name", "Jahr", theApp.m_nNameJahr);
		theApp.WriteProfileInt("Name", "Monat", theApp.m_nNameMonat);
		theApp.WriteProfileInt("Name", "Tag", theApp.m_nNameTag);

		
		//Kartei "Sitzung" (Klassenvariable ist schon erneut
		int iAddAutomat = 1; 
		if(theApp.m_bAddSitzungAutomat == FALSE)
			iAddAutomat =0;
		
		theApp.WriteProfileInt("Einstellungen", 
			"Add_Sitzung_Automatisch", iAddAutomat);

	}

	// This is where you would retrieve information from the property
	// sheet if propSheet.DoModal() returned IDOK.  We aren't doing
	// anything for simplicity.
}
/*
void CMainFrame::OnContextHelp()
{
	// TODO: Add your specialized code here and/or call the base class
	
	CMDIFrameWnd::OnContextHelp();
}

LRESULT CMainFrame::OnCommandHelp(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
//	AfxGetApp()->WinHelp(HIDD_MAIN1);
	return TRUE;
}
*/