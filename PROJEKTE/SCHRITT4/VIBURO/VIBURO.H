// ViBuro.h : main header file for the VIBURO application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class CEdDoc;  //F�r die Deklaration der Klassenvariablen

/////////////////////////////////////////////////////////////////////////////
// CViBuroApp:
// See ViBuro.cpp for the implementation of this class
//

class CViBuroApp : public CWinApp
{
public:
	CMultiDocTemplate* m_pDocTemplateBericht;
	CMultiDocTemplate* m_pDocTemplateAufgaben;
	CEdDoc* m_pBerichtDoc;
	CEdDoc* m_pAufgabenDoc;

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
extern CViBuroApp theApp; 
