// Schritt1View.h : interface of the CSchritt1View class
//
/////////////////////////////////////////////////////////////////////////////

class CSchritt1View : public CView
{
protected: // create from serialization only
	CSchritt1View();
	DECLARE_DYNCREATE(CSchritt1View)

// Attributes
public:
	CSchritt1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSchritt1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSchritt1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSchritt1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Schritt1View.cpp
inline CSchritt1Doc* CSchritt1View::GetDocument()
   { return (CSchritt1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
