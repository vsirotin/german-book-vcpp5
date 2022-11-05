// ViBuroDoc.h : interface of the CViBuroDoc class
//
#ifndef __VIBURODOC_H__
#define __VIBURODOC_H__
/////////////////////////////////////////////////////////////////////////////
#include "Arbeitszeitlist.h"

class CViBuroDoc : public CDocument
{
protected: // create from serialization only
	CViBuroDoc();
	DECLARE_DYNCREATE(CViBuroDoc)

// Attributes
public:
	int m_iMonat;
	int m_iJahr;
private:	
	CArbeitszeitlist m_mapArbZeit;
// Operations
public:
	int GetMin(UINT nTag){return m_mapArbZeit.GetMin(nTag);};
	
	int GetSumme(){return m_mapArbZeit.GetSumme();};
	
	void DeleteTag(UINT nTag)
		{m_mapArbZeit.DeleteTag(nTag);};
	
	void InsertOrChangeTag(UINT nTag, UINT nMin)
		{m_mapArbZeit.InsertOrChangeTag(nTag, nMin);};
	
	virtual void SetTitle();
//	virtual void OnCloseDocument()

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViBuroDoc)
	public:
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
;
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CViBuroDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViBuroDoc)
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	static UINT m_nCountInstance;
};

/////////////////////////////////////////////////////////////////////////////
#endif //__VIBURODOC_H__