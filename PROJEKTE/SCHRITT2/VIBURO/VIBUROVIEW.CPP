// ViBuroView.cpp : implementation of the CViBuroView class
//

#include "stdafx.h"
#include "ViBuro.h"

#include "ViBuroDoc.h"
#include "ViBuroView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViBuroView

IMPLEMENT_DYNCREATE(CViBuroView, CView)

BEGIN_MESSAGE_MAP(CViBuroView, CView)
	//{{AFX_MSG_MAP(CViBuroView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViBuroView construction/destruction

CViBuroView::CViBuroView()
{
	// TODO: add construction code here

}

CViBuroView::~CViBuroView()
{
}

BOOL CViBuroView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CViBuroView drawing

void CViBuroView::OnDraw(CDC* pDC)
{
	CViBuroDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CViBuroView diagnostics

#ifdef _DEBUG
void CViBuroView::AssertValid() const
{
	CView::AssertValid();
}

void CViBuroView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CViBuroDoc* CViBuroView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViBuroDoc)));
	return (CViBuroDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViBuroView message handlers
