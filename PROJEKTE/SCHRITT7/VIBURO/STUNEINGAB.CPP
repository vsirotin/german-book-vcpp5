// StunEingab.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "StunEingab.h"
#include "Arbeitszeitlist.h"
#include "ViBuroDoc.h"
#include <stdlib.h>
#include <afxpriv.h>
#include "HelpIds.h"

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
	m_nTag = 0;
	m_nStunden = 0;
	m_nMin = 0;
	//}}AFX_DATA_INIT

	m_bBilanz = TRUE;
	m_pFreiMitarbeiter = NULL;
	m_pLeiter = NULL;
	m_pMitarbeiter = NULL;

	if(theApp.m_iJobCode == 0)
	{
		m_pLeiter = new CLeiter;
		SET_PERSONAL_DATEN(m_pLeiter);
	}
	else if(theApp.m_iJobCode == 1)
	{
		m_pMitarbeiter = new CMitarbeiter;
		SET_PERSONAL_DATEN(m_pMitarbeiter);
	}
	else
	{
		m_pFreiMitarbeiter = new CFreiMitarbeiter;
		SET_PERSONAL_DATEN(m_pFreiMitarbeiter);
	}
}

CStunEingab::~CStunEingab()
{
	DELETE_OBJECT(m_pFreiMitarbeiter);
	DELETE_OBJECT(m_pLeiter);
	DELETE_OBJECT(m_pMitarbeiter);
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
	DDV_MinMaxUInt(pDX, m_nJahr, 0, 3000);
	DDX_Text(pDX, IDC_GEHALT, m_dGehalt);
	DDV_MinMaxDouble(pDX, m_dGehalt, 0, 9999999);
	DDX_Text(pDX, IDC_STUN_SUM, m_dStundSumme);
	DDV_MinMaxDouble(pDX, m_dStundSumme, 0, 745);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStunEingab, CFormView)
	//{{AFX_MSG_MAP(CStunEingab)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_ANZEIG_JA, OnAnzeigJa)
	ON_BN_CLICKED(IDC_ANZEIG_NEIN, OnAnzeigNein)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_MIN, OnChangeMin)
	ON_EN_CHANGE(IDC_STUN, OnChangeStun)
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_SETUP, OnUpdateFilePrintSetup)
	ON_EN_CHANGE(IDC_TAG, OnChangeTag)
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
	ON_MESSAGE(WM_COMMANDHELP, OnCommandHelp)
	ON_MESSAGE(WM_HELPHITTEST, OnHelpHitTest)
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
	CViBuroDoc* pDoc = (CViBuroDoc*)GetDocument();	
	if(pDoc == NULL)
		return;
	
	pDoc->SetModifiedFlag(TRUE);
	
	pDoc->InsertOrChangeTag(m_nTag, m_nStunden*60 + m_nMin);
	
	SetBilanz(TRUE);
}

void CStunEingab::OnDel() 
{
	// TODO: Add your control notification handler code here
	CViBuroDoc* pDoc = (CViBuroDoc*)GetDocument();	
	if(pDoc == NULL)
		return;

	pDoc->SetModifiedFlag(TRUE);
	pDoc->DeleteTag(m_nTag);
	
	if(IsHeute())
	{
		m_nBasisStun = 0;
		m_nBasisMin = 0;
	}
	InitialParam();
	SetBilanz(TRUE);
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
	CViBuroDoc* pDoc = (CViBuroDoc*)GetDocument();	
	if(pDoc == NULL)
		return;

	m_nJahr = pDoc->m_iJahr;
	m_nMonat = pDoc->m_iMonat - 1;

	m_nMonatDauer = ::GetMonatDauer(m_nJahr, m_nMonat + 1);

	m_nTag = (UINT)theApp.m_Heute.GetDay();
	
	if(!IsHeute())
		m_nTag = 1;

	pDoc->SetTitle();
	SetBilanz(TRUE);
	
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

	SetTimer(ID_TIMER_STUN_EINGAB, 1000, NULL);
}

void CStunEingab::OnChangeTag() 
{
	// TODO: Add your control notification handler code here
	InitialParam();
	ShowGehalt();
}

void CStunEingab::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	//Prüfung, daß ist unser Slider ist
	CWnd* pSld = GetDlgItem(IDC_SLIDER);
	if((pScrollBar != NULL)&&(pSld == pScrollBar))
	{
		int iSumme = m_contrlSlider.GetPos();
		m_nStunden = iSumme / 60;
		m_nMin = iSumme - (m_nStunden * 60);
		UpdateData(FALSE);

		ShowGehalt();
		
		SetBilanz(FALSE);
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
		CViBuroDoc* pDoc = (CViBuroDoc*)GetDocument();	
		
		if(pDoc == NULL)
			return;
				
		m_dStundSumme =  pDoc->GetSumme()/60.;
		m_dStundSumme -= pDoc->GetMin(m_nTag)/60.;
		m_dStundSumme += m_nStunden + m_nMin/60. + theApp.m_nSek/3600.;
		
		if(m_pLeiter != NULL)
			m_dGehalt = m_pLeiter->GetGehalt(); 
		else if(m_pMitarbeiter != NULL)
			m_dGehalt = m_pMitarbeiter->GetGehalt();
		else
			m_dGehalt = m_pFreiMitarbeiter->GetStundGehalt(m_dStundSumme);

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

	SetBilanz(FALSE);
}

void CStunEingab::InitialParam() 
{
	UpdateData(TRUE);
	
	m_nMin = 0;
	m_nStunden = 0;

	CViBuroDoc* pDoc = (CViBuroDoc*)GetDocument();	
	if(pDoc == NULL)
		return;

	int iMin = pDoc->GetMin(m_nTag);
	if(iMin > 0)
	{
		m_nStunden = (UINT)iMin/60;
		m_nMin = (UINT)iMin - 60*(m_nStunden);
	}
	
	m_contrlSlider.SetPos(m_nStunden * 60 + m_nMin);
	
 	UpdateData(FALSE);
	ShowGehalt();
}

void CStunEingab::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	if(nIDEvent == ID_TIMER_STUN_EINGAB)
	{	
		static BOOL bAltAddSitzungAutomat = FALSE;
	   	
		if(theApp.m_bAddSitzungAutomat == TRUE)
		{  
		
			if(IsInput())
				return;

			if(!IsHeute())
				return;
		
		
			if(bAltAddSitzungAutomat == FALSE)
			{
			// manuell eingetragene Sitzungsdauer auslesen
				m_nBasisStun = m_nStunden;
				m_nBasisMin = m_nMin;
			};
		
			int iStun = theApp.m_timeSitzungDauer.GetHours();
			int iMin = theApp.m_timeSitzungDauer.GetMinutes();
			theApp.m_nSek = (UINT)theApp.m_timeSitzungDauer.GetSeconds();
			
			m_nStunden = (UINT)iStun + m_nBasisStun;
			m_nMin = (UINT)iMin + m_nBasisMin;
			if(m_nMin > 59)
			{
			   m_nStunden++;
			   m_nMin -= 60;
			}
			UpdateData(FALSE);

			ShowGehalt();
		}
		
		bAltAddSitzungAutomat = theApp.m_bAddSitzungAutomat;
		SetBilanz(FALSE);
	}
	

	CFormView::OnTimer(nIDEvent);
}



void CStunEingab::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if(bActivate == TRUE)
	{
		if(IsHeute())
		{
			if(theApp.m_bAddSitzungAutomat == FALSE)
			{
				SET_DLG_CTRL_STATE(IDC_TAG, TRUE);
				SET_DLG_CTRL_STATE(IDC_STUN, TRUE);
				SET_DLG_CTRL_STATE(IDC_MIN, TRUE);
				SET_DLG_CTRL_STATE(IDC_SLIDER, TRUE);
			}
			else
			{
				SET_DLG_CTRL_STATE(IDC_TAG, FALSE);
				SET_DLG_CTRL_STATE(IDC_STUN, FALSE);
				SET_DLG_CTRL_STATE(IDC_MIN, FALSE);
				SET_DLG_CTRL_STATE(IDC_SLIDER, FALSE);
			}
		}
		else
		{ // Eingabe nicht für Heute
			SET_DLG_CTRL_STATE(IDC_TAG, TRUE);
			SET_DLG_CTRL_STATE(IDC_STUN, TRUE);
			SET_DLG_CTRL_STATE(IDC_MIN, TRUE);
			SET_DLG_CTRL_STATE(IDC_SLIDER, TRUE);

		}
	}
	CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}



BOOL CStunEingab::IsInput()
{
		UpdateData(TRUE);
		BOOL bRes = FALSE;
   
		if(m_nJahr < 1996)
		{
			bRes = TRUE;
			return bRes;
		}	
		
		if((m_nTag < 1)||(m_nTag > m_nMonatDauer))
		{
			bRes = TRUE;
			return bRes;
		}

		if((m_nStunden < 0)||(m_nStunden > 23))
		{
			bRes = TRUE;
			return bRes;
		}

		if((m_nMin < 0)||(m_nMin > 59))
		{
			bRes = TRUE;
			return bRes;
		}

		return bRes;
}
void CStunEingab::OnUpdateFilePrintSetup(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}


BOOL  CStunEingab::IsHeute()
{

	if((UINT)theApp.m_Heute.GetYear() != m_nJahr)
		return FALSE;

	if((UINT)theApp.m_Heute.GetMonth() != m_nMonat + 1)
		return FALSE;

	if((UINT)theApp.m_Heute.GetDay() != m_nTag)
		return FALSE;

	return TRUE;
}

BOOL CStunEingab::GetBilanz()
{
	return m_bBilanz;
}

void CStunEingab::SetBilanz(BOOL bBilanz)
{
	m_bBilanz = bBilanz;
	SET_DLG_CTRL_STATE(IDC_ADD, !m_bBilanz);

}

void CStunEingab::VorSchliessen() 
{
//Diese Methode wird vor dem Schließen des Hauptdialogs aufgerufen.
	KillTimer(ID_TIMER_STUN_EINGAB);
	
	if(!GetBilanz())
	{
		CString sTmp("Wollen Sie Ihre letze Eingabe für ");
		
		char sTmp1[10];
		_itoa(m_nTag, sTmp1, 10);
		sTmp += sTmp1;
		sTmp += " / ";
		_itoa(m_nMonat + 1, sTmp1, 10);
		sTmp += sTmp1;
		sTmp += " / ";
		_itoa(m_nJahr, sTmp1, 10);
		sTmp += sTmp1;
		sTmp += " sichern?";

		if(AfxMessageBox(sTmp, MB_OKCANCEL) == IDOK)
		{
			OnAdd();	
		}
	}
	return;
}


LRESULT CStunEingab::OnCommandHelp(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	
	theApp.WinHelp(IDD_MAIN + HID_BASE_RESOURCE);
	return TRUE;
}

LRESULT CStunEingab::OnHelpHitTest(WPARAM wParam, LPARAM lParam) 
{

	int iHelpID = IDD_MAIN + HID_BASE_RESOURCE;
	
	//Ermittlung der Koordinaten des Mauszeigers
 
	POINT Point;
		
	Point.x = (LONG)LOWORD(lParam);
	Point.y = (LONG)HIWORD(lParam);
	
	LPPOINT  lpPoint = &Point;
	
//-----Dieser Abschnitt sollte für jedes Steuerelement wiederholt werden,
//-----wofür am besten ein Macro verwendet wird.

	CWnd* pWndDlgItem = GetDlgItem(IDC_SPIN_TAG);

	//Es wird ermittelt, ob der Mauszeiger über einem Steuerelement steht
	if(pWndDlgItem != NULL)
		{
			RECT Rect;
			LPRECT lpRect = &Rect;
			pWndDlgItem->GetWindowRect( lpRect );
			ClientToScreen(lpPoint);
			if((Rect.left < Point.x )&&(Point.x < Rect.right)
				&&(Rect.top < Point.y)&&(Point.y < Rect.bottom))
			{

				iHelpID = HIDC_SPIN_TAG;
			}
		}

	//------------------Ende des Abschnittes ----------------------

	return (LRESULT)iHelpID;
}