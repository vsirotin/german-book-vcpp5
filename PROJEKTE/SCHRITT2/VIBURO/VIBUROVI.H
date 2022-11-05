// ViBuroView.h : interface of the CViBuroView class
//
/////////////////////////////////////////////////////////////////////////////

class CViBuroView : public CView
{
protected: // create from serialization only
	CViBuroView();
	DECLARE_DYNCREATE(CViBuroView)

// Attributes
public:
	CViBuroDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViBuroView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CViBuroView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViBuroView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ViBuroView.cpp
inline CViBuroDoc* CViBuroView::GetDocument()
   { return (CViBuroDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
