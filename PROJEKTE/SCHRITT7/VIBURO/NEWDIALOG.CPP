// NewDialog.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "NewDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewDialog dialog


CNewDialog::CNewDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CNewDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewDialog)
	m_nJahr = 0;
	m_iMonat = -1;
	//}}AFX_DATA_INIT
	
	
	m_nJahr = (UINT)theApp.m_Heute.GetYear();
	m_iMonat = (UINT)theApp.m_Heute.GetMonth() - 1;
	
}


void CNewDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewDialog)
	DDX_Text(pDX, IDC_JAHR, m_nJahr);
	DDX_CBIndex(pDX, IDC_MONAT, m_iMonat);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewDialog, CDialog)
	//{{AFX_MSG_MAP(CNewDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewDialog message handlers

void CNewDialog::OnOK() 
{
	// TODO: Add extra validation here
	
	UpdateData(TRUE);
	if(m_nJahr < 1996)
	{
		AfxMessageBox("Die Eingabe Jahren vor 1996 ist nicht erlaubt", MB_OK);
		return;
	}

	if(m_nJahr > 2100)
	{
		AfxMessageBox("Die Eingabe Jahren nach 2100 ist nicht erlaubt", MB_OK);
		return;
	}
	CDialog::OnOK();
}
