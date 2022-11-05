// StunEingab.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "StunEingab.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStunEingab

IMPLEMENT_DYNCREATE(CStunEingab, CFormView)

CStunEingab::CStunEingab()
	: CFormView(CStunEingab::IDD)
{
	//{{AFX_DATA_INIT(CStunEingab)
	m_dGehalt = 0.0;
	m_dStundSumme = 0.0;
	m_iAnzeigFormat = 1;
	m_nJahr = 1996;
	m_nMonat = 1;
	m_nTag = 1;
	m_nStunden = 0;
	m_nMin = 0;
	//}}AFX_DATA_INIT

	m_nMonatDauer = 31; //Vorläufige Lösung!
 }

CStunEingab::~CStunEingab()
{
}

void CStunEingab::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStunEingab)
	DDX_Control(pDX, IDC_MONAT, m_contrlMonatCombBox);
	DDX_Control(pDX, IDC_SPIN_STUN, m_contrlSpinStun);
	DDX_Control(pDX, IDC_SPIN_MIN, m_contrlSpinMin);
	DDX_Control(pDX, IDC_SLIDER, m_contrlSlider);
	DDX_Control(pDX, IDC_SPIN_TAG, m_contrlSpinTag);
	DDX_Text(pDX, IDC_TAG, m_nTag);
	DDV_MinMaxUInt(pDX, m_nTag, 1, 31);
	DDX_Text(pDX, IDC_STUN, m_nStunden);
	DDV_MinMaxUInt(pDX, m_nStunden, 0, 23);
	DDX_Text(pDX, IDC_MIN, m_nMin);
	DDV_MinMaxUInt(pDX, m_nMin, 0, 59);
	DDX_Radio(pDX, IDC_ANZEIG_JA, m_iAnzeigFormat);
	DDX_Text(pDX, IDC_JAHR, m_nJahr);
	DDV_MinMaxUInt(pDX, m_nJahr, 1996, 3000);
	DDX_Text(pDX, IDC_GEHALT, m_dGehalt);
	DDV_MinMaxDouble(pDX, m_dGehalt, 0,9999999);
	DDX_Text(pDX, IDC_STUN_SUM, m_dStundSumme);
	DDV_MinMaxDouble(pDX, m_dStundSumme, 0, 25);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStunEingab, CFormView)
	//{{AFX_MSG_MAP(CStunEingab)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_ANZEIG_JA, OnAnzeigJa)
	ON_BN_CLICKED(IDC_ANZEIG_NEIN, OnAnzeigNein)
	ON_EN_CHANGE(IDC_TAG, OnChangeTag)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_MIN, OnChangeMin)
	ON_EN_CHANGE(IDC_STUN, OnChangeStun)
	ON_CBN_SELCHANGE(IDC_MONAT, OnSelchangeMonat)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStunEingab diagnostics

#ifdef _DEBUG
void CStunEingab::AssertValid() const
{
	CFormView::AssertValid();
}

void CStunEingab::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStunEingab message handlers

void CStunEingab::OnAdd() 
{
	// TODO: Add your control notification handler code here
	
}

void CStunEingab::OnDel() 
{
	// TODO: Add your control notification handler code here
	
}

void CStunEingab::OnAnzeigJa() 
{
	// TODO: Add your control notification handler code here
	
	ShowGehalt();
}

void CStunEingab::OnAnzeigNein() 
{
	// TODO: Add your control notification handler code here
	
	ShowGehalt();
}



void CStunEingab::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	//ComboBox Einstellungen:
	
	m_contrlMonatCombBox.SetCurSel(m_nMonat);

	//Radiobuttons Einstellungen

	CButton* pButt = (CButton*)GetDlgItem(IDC_ANZEIG_NEIN);
	if(pButt != 0)
		pButt->SetCheck(1);
	 
	//Slider Einstellungen:

	m_contrlSlider.SetRangeMin(0);
	m_contrlSlider.SetRangeMax(24*60 - 1);

	
	//Tag-Spin Einstellungen:
	CWnd* pWnd = GetDlgItem(IDC_TAG);
	if(pWnd != NULL)
	{
		m_contrlSpinTag.SetBuddy( pWnd);
		m_contrlSpinTag.SetRange(1, m_nMonatDauer);
		m_contrlSpinTag.SetPos(m_nTag);
	}
	  
	//Stunden-Spin Einstellungen
	pWnd = GetDlgItem(IDC_STUN);
	if(pWnd != NULL)
	{
		m_contrlSpinStun.SetBuddy( pWnd);
		m_contrlSpinStun.SetRange(0, 23);
		m_contrlSpinStun.SetPos(0);
	}

	//Minuten-Spin Einstellungen
	pWnd = GetDlgItem(IDC_MIN);
	if(pWnd != NULL)
	{
		m_contrlSpinMin.SetBuddy( pWnd);
		m_contrlSpinMin.SetRange(0, 59);
		m_contrlSpinMin.SetPos(0);
	}
	 
	InitialParam();
}

void CStunEingab::OnChangeTag() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	
	//if().....
	InitialParam();
}

void CStunEingab::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	//Prüfung, daß es unseren Slider ist
	CWnd* pSld = GetDlgItem(IDC_SLIDER);
	if((pScrollBar != NULL)&&(pSld == pScrollBar))
	{
		int iSumme = m_contrlSlider.GetPos();
		m_nStunden = iSumme / 60;
		m_nMin = iSumme - (m_nStunden * 60);
		UpdateData(FALSE);

		ShowGehalt();
	}
	
	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CStunEingab::OnChangeMin() 
{
	// TODO: Add your control notification handler code here

	OnChangeStunMin();
}

void CStunEingab::OnChangeStun() 
{
	// TODO: Add your control notification handler code here
	
	OnChangeStunMin();
}


void CStunEingab::OnSelchangeMonat() 
{
	// TODO: Add your control notification handler code here
	int i = m_contrlMonatCombBox.GetCurSel();
	TRACE1("Monat N %d ist ausgewahlt\n", i);
}


void CStunEingab::ShowGehalt(void )
{
 	UpdateData(TRUE);

	if(m_iAnzeigFormat == 1)
	{
		m_dGehalt =0;
		m_dStundSumme = 0;
	}
	else
	{
		m_dStundSumme = m_nStunden + m_nMin/60.;
		m_dGehalt = m_dStundSumme; //Vorläufige Lösung!!
	}
	
	UpdateData(FALSE);
}
void CStunEingab::OnChangeStunMin() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	int iSumme = m_nStunden * 60 + m_nMin;
	m_contrlSlider.SetPos(iSumme);	
 	ShowGehalt();
}

void CStunEingab::InitialParam() 
{
	m_nMin = 0;
	m_nStunden = 0;
	m_contrlSlider.SetPos(0);
 	UpdateData(FALSE);
	ShowGehalt();
}


void CStunEingab::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}