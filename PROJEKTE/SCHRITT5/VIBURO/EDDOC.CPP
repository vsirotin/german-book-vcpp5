// EdDoc.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "EdDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEdDoc

IMPLEMENT_DYNCREATE(CEdDoc, CDocument)

CEdDoc::CEdDoc()
{
}

BOOL CEdDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CEdDoc::~CEdDoc()
{
}


BEGIN_MESSAGE_MAP(CEdDoc, CDocument)
	//{{AFX_MSG_MAP(CEdDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEdDoc diagnostics

#ifdef _DEBUG
void CEdDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEdDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEdDoc serialization

void CEdDoc::Serialize(CArchive& ar)
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
// CEdDoc commands


