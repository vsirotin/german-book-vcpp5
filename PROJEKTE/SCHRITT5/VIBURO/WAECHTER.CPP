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
	m_sName = theApp.m_sName;
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
   
   AfxMessageBox("Rufen Sie bitte Ihren Administrator an."); 
   
	
}


void CWaechter::OnOK() 
{
	// TODO: Add extra validation here
	
	//Prüfung des Administratorpaßworts
	if(m_sPassword.Compare("ADMINISTRATOR") == 0)
	{
		CString sTmp = m_sName;
		sTmp.MakeUpper();
		if(sTmp.Compare("ADMINISTRATOR") == 0)
		{
			theApp.m_bIamAdministrator = TRUE;
			m_bResult = TRUE;
		}
	}
	else
	{
	  //Prüfung des normalen Paßworts

		CString sStdPswd = theApp.m_sPassword;
		sStdPswd.MakeUpper();
		
		if(m_sPassword.Compare(sStdPswd) == 0)
			m_bResult = TRUE;
		else 
			MessageBeep(MB_ICONSTOP);
	}

	CDialog::OnOK();
	
}


BOOL CWaechter::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//Initialisierung der "OK"-Schaltfläche
	CWnd* pOK = GetDlgItem(IDOK);
	if(pOK != NULL)
		pOK->EnableWindow(FALSE); 
	
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
			pOK->EnableWindow(FALSE); 
		else
			pOK->EnableWindow(TRUE); 
	}
}


