// ViBuroDoc.cpp : implementation of the CViBuroDoc class
//

#include "stdafx.h"
#include "ViBuro.h"

#include "ViBuroDoc.h"
#include "ArbeitsTag.h"
#include "Arbeitszeitlist.h"
#include "StunEingab.h"
#include <stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

UINT CViBuroDoc::m_nCountInstance = 0;
/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc

IMPLEMENT_DYNCREATE(CViBuroDoc, CDocument)

BEGIN_MESSAGE_MAP(CViBuroDoc, CDocument)
	//{{AFX_MSG_MAP(CViBuroDoc)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc construction/destruction

CViBuroDoc::CViBuroDoc()
{
	// TODO: add one-time construction code here
			
	m_nCountInstance++;
}

CViBuroDoc::~CViBuroDoc()
{
	
	m_nCountInstance--;
	if(m_nCountInstance == 0)
		theApp.m_bIsArbeitsListe = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc serialization

void CViBuroDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_iJahr << m_iMonat;
	}
	else
	{
		// TODO: add loading code here

		ar >> m_iJahr >> m_iMonat;
	}
	m_mapArbZeit.Serialize(ar);
	
	SetModifiedFlag(FALSE);
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
	afxDump << "\n m_iJahr = " << m_iJahr;
	afxDump << "\n m_iMonat = " << m_iMonat;
	afxDump << "\n m_mapArbZeit. = ";
	m_mapArbZeit.Dump(afxDump);
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViBuroDoc commands

BOOL CViBuroDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	
	if(theApp.m_bIsArbeitsListe)
		return FALSE;		 //Versuch ein zweites Dokument zu öffnen

	CFile file;
					   
	CFileStatus status;
	if(!file.GetStatus(lpszPathName, status )) //Datei existiert nicht
	{

		CString sTmp1 = "ViBuro erstellt für Sie ein neues Dokument: ";
		sTmp1 += lpszPathName;

		AfxMessageBox(sTmp1);

		if(!file.Open(lpszPathName, CFile::modeCreate
			|CFile::modeReadWrite))
		{
			TRACE("Problem beim Datei Öffnen \n");
			return FALSE;
		}
	
	file.Close();
	
	}
	
	m_iJahr = theApp.m_nNewJahr;
	m_iMonat = theApp.m_nNewMonat;

	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	
//	theApp.m_bAddSitzungAutomat = FALSE;
	theApp.m_bIsArbeitsListe = TRUE;
	return TRUE;
}


void CViBuroDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(IsModified());
}

void CViBuroDoc::SetTitle( )
{
	CString sDocumentName = "Arbeitszeit für ";
	char sTmp[10];
	_itoa(m_iMonat, sTmp, 10);
	sDocumentName += sTmp;
	sDocumentName += " / ";
	_itoa(m_iJahr, sTmp, 10);
	sDocumentName += sTmp;
	CDocument::SetTitle(sDocumentName);
}
BOOL CViBuroDoc::SaveModified() 
{
	// TODO: Add your specialized code here and/or call the base class
	POSITION pos = GetFirstViewPosition();
	CStunEingab* pView = (CStunEingab*)GetNextView(pos);
	if(pView != NULL)
	{
		pView->VorSchliessen();
	}

	return CDocument::SaveModified();
}