// ViBuro.h : main header file for the VIBURO application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class CEdDoc;  //Für die Deklaration der Klassenvariablen

/////////////////////////////////////////////////////////////////////////////
// CViBuroApp:
// See ViBuro.cpp for the implementation of this class
//

class CViBuroApp : public CWinApp
{
public:
	UINT m_nSek;
	
	CString m_sPassword;
	
	BOOL m_bAddSitzungAutomat;
	
	CString	m_sBLZ;
	CString	m_sGeldInstitut;
	CString	m_sKontoStadt;
	CString	m_sKonto;
	
	UINT	m_nNameJahr;
	UINT	m_nNameMonat;
	CString	m_sName;
	UINT	m_nNameTag;
	CString	m_sVorname;

	CString	m_sPLZ;
	CString	m_sStadt;
	CString	m_sStrasse;
	CString	m_sTelefon;

	int m_iJobCode;

	CMultiDocTemplate* m_pDocTemplateBericht;
	CMultiDocTemplate* m_pDocTemplateAufgabe;
	CEdDoc* m_pBerichtDoc;
	CEdDoc* m_pAufgabeDoc;
	BOOL m_bIamAdministrator;

   	CTimeSpan m_timeSitzungDauer;
	BOOL m_bTimeInitialized;

	CViBuroApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViBuroApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CViBuroApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//Globaler Zeiger:

extern CViBuroApp theApp; 

//////////////////////////////////////////////////////////////
//Macro zum Aktivieren und Deaktivieren eines Fensters

#define SET_DLG_CTRL_STATE(nID,bState)	{	\
	CWnd* pWnd = GetDlgItem(nID);			\
	if(pWnd != NULL)						\
		pWnd->EnableWindow(bState);			\
};
