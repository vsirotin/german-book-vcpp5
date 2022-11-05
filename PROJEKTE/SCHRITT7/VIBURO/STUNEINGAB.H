// StunEingab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStunEingab form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "Leiter.h"
#include "Mitarb.h"
#include "Freimitb.h"
#include "Person.h"


class CStunEingab : public CFormView
{
protected:
	void SetBilanz(BOOL bBilanz);
	BOOL GetBilanz();
	CStunEingab();           // protected constructor used by dynamic creation
	
	DECLARE_DYNCREATE(CStunEingab)

// Form Data
public:
	BOOL IsInput();
	BOOL IsHeute();

	UINT m_nMonatDauer;
	UINT m_nMonat;
	void ShowGehalt(void );

	void VorSchliessen(); 
	
	//{{AFX_DATA(CStunEingab)
	enum { IDD = IDD_MAIN };
	CComboBox	m_contrlMonatCombBox;
	CSpinButtonCtrl	m_contrlSpinStun;
	CSpinButtonCtrl	m_contrlSpinMin;
	CSliderCtrl	m_contrlSlider;
	CSpinButtonCtrl	m_contrlSpinTag;
	UINT	m_nTag;
	UINT	m_nStunden;
	UINT	m_nMin;
	int		m_iAnzeigFormat;
	UINT	m_nJahr;
	double	m_dGehalt;
	double	m_dStundSumme;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void OnChangeStunMin();
	void InitialParam();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStunEingab)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CStunEingab();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CStunEingab)
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnAnzeigJa();
	afx_msg void OnAnzeigNein();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChangeMin();
	afx_msg void OnChangeStun();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnUpdateFilePrintSetup(CCmdUI* pCmdUI);
	afx_msg void OnChangeTag();
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
//afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);

//	afx_msg void OnContextHelp();
private:
	CLeiter* m_pLeiter;
	CMitarbeiter* m_pMitarbeiter;
	CFreiMitarbeiter* m_pFreiMitarbeiter;

	BOOL m_bBilanz;

	UINT m_nBasisStun;
	UINT m_nBasisMin;
};

/////////////////////////////////////////////////////////////////////////////
