// EdDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEdDoc document

class CEdDoc : public CDocument
{
protected:
	CEdDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CEdDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEdDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEdDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CEdDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
