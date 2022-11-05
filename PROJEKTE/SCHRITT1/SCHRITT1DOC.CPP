// Schritt1Doc.cpp : implementation of the CSchritt1Doc class
//

#include "stdafx.h"
#include "Schritt1.h"

#include "Schritt1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSchritt1Doc

IMPLEMENT_DYNCREATE(CSchritt1Doc, CDocument)

BEGIN_MESSAGE_MAP(CSchritt1Doc, CDocument)
	//{{AFX_MSG_MAP(CSchritt1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSchritt1Doc construction/destruction

CSchritt1Doc::CSchritt1Doc()
{
	// TODO: add one-time construction code here

}

CSchritt1Doc::~CSchritt1Doc()
{
}

BOOL CSchritt1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSchritt1Doc serialization

void CSchritt1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSchritt1Doc diagnostics

#ifdef _DEBUG
void CSchritt1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSchritt1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSchritt1Doc commands
