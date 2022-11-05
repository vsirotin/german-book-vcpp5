// ViBuro.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ViBuro.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "ViBuroDoc.h"
#include "StunEingab.h"
#include "Waechter.h"
#include "AufgabenView.h"
#include "BerichtView.h"
#include "EdDoc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViBuroApp

BEGIN_MESSAGE_MAP(CViBuroApp, CWinApp)
	//{{AFX_MSG_MAP(CViBuroApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViBuroApp construction

CViBuroApp::CViBuroApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_pAufgabenDoc = NULL;
	m_pBerichtDoc = NULL;
	
	m_bTimeInitialized = FALSE;

}

/////////////////////////////////////////////////////////////////////////////
// The one and only CViBuroApp object

CViBuroApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CViBuroApp initialization

BOOL CViBuroApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

		//Abfrage und Prüfung des Passwords: 	
	UINT nPassIteration = 0;
	for(;;)
	{
		CWaechter dlgWillkom;
		if(dlgWillkom.DoModal() != IDOK)
			return FALSE;
		else if(dlgWillkom.m_bResult == TRUE)
			break;
		else if(++nPassIteration >= 3)
			return FALSE;
	}

	
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_VIBUROTYPE,
		RUNTIME_CLASS(CViBuroDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CStunEingab));
	AddDocTemplate(pDocTemplate);

	m_pDocTemplateAufgaben = new CMultiDocTemplate(
		IDR_VIBUROTYPE,
		RUNTIME_CLASS(CEdDoc),
		RUNTIME_CLASS(CChildFrame), // Aufgabenfenster
		RUNTIME_CLASS(CAufgabenView));
	AddDocTemplate(m_pDocTemplateAufgaben);

	m_pDocTemplateBericht = new CMultiDocTemplate(
		IDR_VIBUROTYPE,
		RUNTIME_CLASS(CEdDoc),
		RUNTIME_CLASS(CChildFrame), // Berichtfenster
		RUNTIME_CLASS(CBerichtView));
	AddDocTemplate(m_pDocTemplateBericht);



	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
/*
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
*/
	 ASSERT_VALID(pDocTemplate);
	 pDocTemplate->OpenDocumentFile("Hauptdoc.aaa");  //Vorläufige Lösung

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CViBuroApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CViBuroApp commands
