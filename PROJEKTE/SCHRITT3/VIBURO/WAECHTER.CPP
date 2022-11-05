// Waechter.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "Waechter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWaechter dialog


CWaechter::CWaechter(CWnd* pParent /*=NULL*/)
	: CDialog(CWaechter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWaechter)
	m_sName = _T("");
	m_sPassword = _T("");
	//}}AFX_DATA_INIT

	m_bResult = FALSE;
}


void CWaechter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWaechter)
	DDX_Text(pDX, IDC_NAME, m_sName);
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWaechter, CDialog)
	//{{AFX_MSG_MAP(CWaechter)
	ON_BN_CLICKED(IDC_HILFE, OnHilfe)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWaechter message handlers

void CWaechter::OnHilfe() 
{
	// TODO: Add your control notification handler code here
   
   AfxMessageBox("Fragen Sie bitte Ihren Administrator!"); 
   
	
}


void CWaechter::OnOK() 
{
	// TODO: Add extra validation here
	
	CString sStdPswd("Bin"); //Vorläufige Lösung!
	CString sTmp = m_sPassword;
	sStdPswd.MakeUpper();

	if(sTmp.Compare(sStdPswd) == 0)
		m_bResult = TRUE;
	else 
		MessageBeep(MB_ICONQUESTION);
	
	CDialog::OnOK();
	
}


BOOL CWaechter::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	// Initialisierung des Benutzernamens. 
	m_sName = "Mustermann";	 //Vorläufige Lösung!
	UpdateData(FALSE);


	CWnd* pOK = GetDlgItem(IDOK);
	if(pOK != NULL)
		pOK->EnableWindow(FALSE); //Deaktivieren der "OK"-Schaltfläche 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CWaechter::OnChangePassword() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	
	CWnd* pOK = GetDlgItem(IDOK);
	if(pOK != NULL)
	{
		if(m_sPassword.GetLength() == 0)
			pOK->EnableWindow(FALSE); //Deaktivieren der "OK"-Schaltfläche  
		else
			pOK->EnableWindow(TRUE);  //Aktivieren der "OK"-Schaltfläche 
	}
}


