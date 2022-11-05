// AufgabeView.cpp : implementation file
//

#include "stdafx.h"
#include "ViBuro.h"
#include "AufgabeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAufgabeView

IMPLEMENT_DYNCREATE(CAufgabeView, CEditView)

CAufgabeView::CAufgabeView()
{
}

CAufgabeView::~CAufgabeView()
{
	theApp.m_pAufgabeDoc = NULL;
}


BEGIN_MESSAGE_MAP(CAufgabeView, CEditView)
	//{{AFX_MSG_MAP(CAufgabeView)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAufgabeView drawing

void CAufgabeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CAufgabeView diagnostics

#ifdef _DEBUG
void CAufgabeView::AssertValid() const
{
	CEditView::AssertValid();
}

void CAufgabeView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAufgabeView message handlers

void CAufgabeView::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

void CAufgabeView::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);

}

