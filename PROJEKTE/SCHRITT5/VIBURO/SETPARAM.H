// SetParam.h : header file
//

#ifndef __SETPARAM_H__
#define __SETPARAM_H__

/////////////////////////////////////////////////////////////////////////////
// CAddSitzungSeite dialog

class CAddSitzungSeite : public CPropertyPage
{
	DECLARE_DYNCREATE(CAddSitzungSeite)

// Construction
public:
	CAddSitzungSeite();
	~CAddSitzungSeite();

// Dialog Data
	//{{AFX_DATA(CAddSitzungSeite)
	enum { IDD = IDD_PROPPAGE1 };
	int		m_iAddSitzungAutomat;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAddSitzungSeite)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAddSitzungSeite)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CPassSeite dialog

class CPassSeite : public CPropertyPage
{
	DECLARE_DYNCREATE(CPassSeite)

// Construction
public:
	CPassSeite();
	~CPassSeite();

// Dialog Data
	//{{AFX_DATA(CPassSeite)
	enum { IDD = IDD_PROPPAGE2 };
	CString	m_sPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPassSeite)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPassSeite)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CBankSeite dialog

class CBankSeite : public CPropertyPage
{
	DECLARE_DYNCREATE(CBankSeite)

// Construction
public:
	CBankSeite();
	~CBankSeite();

// Dialog Data
	//{{AFX_DATA(CBankSeite)
	enum { IDD = IDD_PROPPAGE3 };
	CString	m_sBLZ;
	CString	m_sGeldInstitut;
	CString	m_sKontoStadt;
	CString	m_sKonto;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CBankSeite)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CBankSeite)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CAddresSeite dialog

class CAddresSeite : public CPropertyPage
{
	DECLARE_DYNCREATE(CAddresSeite)

// Construction
public:
	CAddresSeite();
	~CAddresSeite();

// Dialog Data
	//{{AFX_DATA(CAddresSeite)
	enum { IDD = IDD_PROPPAGE4 };
	CString	m_sPLZ;
	CString	m_sStadt;
	CString	m_sStrasse;
	CString	m_sTelefon;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAddresSeite)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAddresSeite)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CNameSeite dialog

class CNameSeite : public CPropertyPage
{
	DECLARE_DYNCREATE(CNameSeite)

// Construction
public:
	CNameSeite();
	~CNameSeite();

// Dialog Data
	//{{AFX_DATA(CNameSeite)
	enum { IDD = IDD_PROPPAGE5 };
	UINT	m_nNameJahr;
	UINT	m_nNameMonat;
	CString	m_sName;
	UINT	m_nNameTag;
	CString	m_sVorname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CNameSeite)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CNameSeite)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CJobSeite dialog

class CJobSeite : public CPropertyPage
{
	DECLARE_DYNCREATE(CJobSeite)

// Construction
public:
	CJobSeite();
	~CJobSeite();

// Dialog Data
	//{{AFX_DATA(CJobSeite)
	enum { IDD = IDD_PROPPAGE6 };
	CComboBox	m_comboboxJob;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CJobSeite)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CJobSeite)
	afx_msg void OnSelchangeJobCombo();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



#endif // __SETPARAM_H__
