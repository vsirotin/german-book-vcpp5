// Option.h : header file
//
// This class defines custom modal property sheet 
// COptionSheet.
 
#ifndef __OPTION_H__
#define __OPTION_H__

#include "SetParam.h"

/////////////////////////////////////////////////////////////////////////////
// COptionSheet

class COptionSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(COptionSheet)

// Construction
public:
	COptionSheet(CWnd* pParentWnd = NULL);

// Attributes
public:
	CAddSitzungSeite m_Page1;
	CPassSeite m_Page2;
	CBankSeite m_Page3;
	CAddresSeite m_Page4;
	CNameSeite m_Page5;
	CJobSeite m_Page6;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COptionSheet();

// Generated message map functions
protected:
	//{{AFX_MSG(COptionSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __OPTION_H__