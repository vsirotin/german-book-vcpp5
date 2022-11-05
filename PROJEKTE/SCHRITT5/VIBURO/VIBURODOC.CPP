// ViBuroDoc.cpp : implementation of the CViBuroDoc class
//

#include "stdafx.h"
#include "ViBuro.h"

#include "ViBuroDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc

IMPLEMENT_DYNCREATE(CViBuroDoc, CDocument)

BEGIN_MESSAGE_MAP(CViBuroDoc, CDocument)
	//{{AFX_MSG_MAP(CViBuroDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc construction/destruction

CViBuroDoc::CViBuroDoc()
{
	// TODO: add one-time construction code here

}

CViBuroDoc::~CViBuroDoc()
{
}

BOOL CViBuroDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc serialization

void CViBuroDoc::Serialize(CArchive& ar)
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
// CViBuroDoc diagnostics

#ifdef _DEBUG
void CViBuroDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CViBuroDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc commands
