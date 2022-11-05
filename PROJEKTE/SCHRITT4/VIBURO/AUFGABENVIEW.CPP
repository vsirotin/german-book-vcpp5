// AufgabenView.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "AufgabenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAufgabenView

IMPLEMENT_DYNCREATE(CAufgabenView, CEditView)

CAufgabenView::CAufgabenView()
{
}

CAufgabenView::~CAufgabenView()
{
	theApp.m_pAufgabenDoc = NULL;
}


BEGIN_MESSAGE_MAP(CAufgabenView, CEditView)
	//{{AFX_MSG_MAP(CAufgabenView)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAufgabenView drawing

void CAufgabenView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CAufgabenView diagnostics

#ifdef _DEBUG
void CAufgabenView::AssertValid() const
{
	CEditView::AssertValid();
}

void CAufgabenView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAufgabenView message handlers

void CAufgabenView::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

void CAufgabenView::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);

}

