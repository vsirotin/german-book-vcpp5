// BerichtView.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "BerichtView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBerichtView

IMPLEMENT_DYNCREATE(CBerichtView, CEditView)

CBerichtView::CBerichtView()
{
}

CBerichtView::~CBerichtView()
{
	theApp.m_pBerichtDoc = NULL;
}


BEGIN_MESSAGE_MAP(CBerichtView, CEditView)
	//{{AFX_MSG_MAP(CBerichtView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBerichtView drawing

void CBerichtView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CBerichtView diagnostics

#ifdef _DEBUG
void CBerichtView::AssertValid() const
{
	CEditView::AssertValid();
}

void CBerichtView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBerichtView message handlers

