// Waechter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWaechter dialog

class CWaechter : public CDialog
{
// Construction
public:
	CWaechter(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWaechter)
	enum { IDD = IDD_WAECHTER };
	CString	m_sName;
	CString	m_sPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaechter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWaechter)
	afx_msg void OnHilfe();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangePassword();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

//Klassenvariable
public: 
	BOOL m_bResult;
};
