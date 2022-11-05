// Schritt1View.cpp : implementation of the CSchritt1View class
//

#include "stdafx.h"
#include "Schritt1.h"

#include "Schritt1Doc.h"
#include "Schritt1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSchritt1View

IMPLEMENT_DYNCREATE(CSchritt1View, CView)

BEGIN_MESSAGE_MAP(CSchritt1View, CView)
	//{{AFX_MSG_MAP(CSchritt1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSchritt1View construction/destruction

CSchritt1View::CSchritt1View()
{
	// TODO: add construction code here

}

CSchritt1View::~CSchritt1View()
{
}

BOOL CSchritt1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSchritt1View drawing

void CSchritt1View::OnDraw(CDC* pDC)
{
	
	CSchritt1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

  	pDC->TextOut( 0, 0, "Guten Tag,...");

}

/////////////////////////////////////////////////////////////////////////////
// CSchritt1View diagnostics

#ifdef _DEBUG
void CSchritt1View::AssertValid() const
{
	CView::AssertValid();
}

void CSchritt1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSchritt1Doc* CSchritt1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSchritt1Doc)));
	return (CSchritt1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSchritt1View message handlers
