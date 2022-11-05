// ViBuro.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ViBuro.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "ViBuroDoc.h"
#include "StunEingab.h"
#include "Waechter.h"
#include "AufgabeView.h"
#include "BerichtView.h"
#include "EdDoc.h"
#include "NewDialog.h"


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
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
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
	m_pAufgabeDoc = NULL;
	m_pBerichtDoc = NULL;
	
	m_bTimeInitialized = FALSE;

	m_bIamAdministrator = FALSE;

	m_iJobCode = -1;

	m_nSek = 0;

	m_bIsArbeitsListe = FALSE;

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

	SetRegistryKey( "Addison Wesley");

	
	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	//Lesen von Konfigurationsdaten aus der Registrierdatenbank

	

	int iAddAutomat = GetProfileInt("Einstellungen", 
		"Add_Sitzung_Automatisch", 0);
	if(iAddAutomat == 1)
		m_bAddSitzungAutomat = TRUE;
	else
		m_bAddSitzungAutomat = FALSE;
	
	
	m_sPassword = GetProfileString("Paßwort", "Paßwort");

	m_sBLZ = GetProfileString("Konto", "BLZ");
	m_sGeldInstitut = GetProfileString("Konto", "Bank");
	m_sKontoStadt = GetProfileString("Konto", "Stadt");
	m_sKonto = GetProfileString("Konto", "Kontonummer");

	m_sName = GetProfileString("Name", "Name");
	m_sVorname = GetProfileString("Name", "Vorname");
	m_nNameJahr = GetProfileInt("Name", "Jahr", 1996);
	m_nNameMonat = (UINT)GetProfileInt("Name", "Monat",1);
	m_nNameTag = (UINT)GetProfileInt("Name", "Tag",1);
	

	m_sPLZ = GetProfileString("Adresse", "PLZ");
	m_sStadt = GetProfileString("Adresse", "Stadt");
	m_sStrasse = GetProfileString("Adresse", "Straße");
	m_sTelefon = GetProfileString("Adresse", "Telefon");

	m_iJobCode = GetProfileInt("Tätigkeit", "JobCode", -1);


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.


	
	m_pDocTemplateListe = new CMultiDocTemplate(
		IDR_VIBUROTYPE,
		RUNTIME_CLASS(CViBuroDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CStunEingab)); //Arbeitszeitliste
	AddDocTemplate(m_pDocTemplateListe);

	m_pDocTemplateAufgabe = new CMultiDocTemplate(
		IDR_VIBUROTYPE_AUFGABE,
		RUNTIME_CLASS(CEdDoc),
		RUNTIME_CLASS(CChildFrame), // Aufgabenfenster
		RUNTIME_CLASS(CAufgabeView));
	AddDocTemplate(m_pDocTemplateAufgabe);

		m_pDocTemplateBericht = new CMultiDocTemplate(
		IDR_VIBUROTYPE_BERICHT,
		RUNTIME_CLASS(CEdDoc),
		RUNTIME_CLASS(CChildFrame), // Berichtfenster
		RUNTIME_CLASS(CBerichtView));
	AddDocTemplate(m_pDocTemplateBericht);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
	
	EnableShellOpen(); 
	RegisterShellFileTypes();
	m_pMainWnd->DragAcceptFiles();

	//Ermittelung des aktuellen Datums
	time_t t0;
	time(&t0);
	m_Heute = CTime(t0);
	
	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
  
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
			
	//Abfrage und Prüfung des Paßwort: 	
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

	if(!m_bIsArbeitsListe)
	{

		m_nNewJahr = m_Heute.GetYear();
		m_nNewMonat = m_Heute.GetMonth();
	
	  //Erzeugung eines Dateinamens bezüglich des aktuellen Datums
		
		CString sFileName;
		::GetFileName(&sFileName, m_nNewJahr, m_nNewMonat);

		 m_pDocTemplateListe->OpenDocumentFile(sFileName); 
	}

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

//Global Function

UINT  GetMonatDauer(UINT nJahr, UINT nMonat)
{
	if((nJahr < 1980)||(nMonat < 1)||(nMonat > 12))
		return 31;

	CTime t1(nJahr, nMonat, 1, 0, 0, 0);
	CTime t2;
	if(nMonat == 12)
		t2 = CTime(nJahr + 1, 1, 1, 0, 0, 0);
	else
		t2 = CTime(nJahr, nMonat + 1, 1, 0, 0, 0);
	
	CTimeSpan ts = t2 - t1;

	UINT nMonatDauer = (UINT)ts.GetDays(); 
	return nMonatDauer;
};

void GetFileName(CString* sFileName, UINT nJahr, UINT nMonat)
{
	*sFileName = "D_";
	
	char sTmp[20];
	
	wsprintf(sTmp, "%d_", nMonat);
	*sFileName += sTmp;

	wsprintf(sTmp, "%d_Liste.vil", nJahr);
	*sFileName += sTmp;
}
void CViBuroApp::OnFileNew() 
{
	// TODO: Add your command handler code here
	CNewDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_nNewJahr = dlg.m_nJahr;
		m_nNewMonat = dlg.m_iMonat + 1;

		CString sFileName;
		::GetFileName(&sFileName, m_nNewJahr, m_nNewMonat);
		m_pDocTemplateListe->OpenDocumentFile(sFileName); 

	}
}

void CViBuroApp::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_bIsArbeitsListe);
}

BOOL CViBuroApp::ProcessShellCommand( CCommandLineInfo& rCmdInfo )
{
	CString sFileName = rCmdInfo.m_strFileName;
	
	if(sFileName.Find("Aufgaben.via") > 0)
	{
		theApp.m_pAufgabeDoc =  (CEdDoc*)theApp.m_pDocTemplateAufgabe
			->OpenDocumentFile("Aufgaben.via");
		return TRUE;
	}
	if(sFileName.Find("Bericht.vib") > 0)
	{		  
		theApp.m_pBerichtDoc =  (CEdDoc*)theApp.m_pDocTemplateBericht
			->OpenDocumentFile("Bericht.vib");
		return TRUE;
	}
	if(sFileName.Find("_Liste.vil") > 1)
	{
		m_pDocTemplateListe->OpenDocumentFile(sFileName); 
		return TRUE;
	}

	return TRUE; 
}
