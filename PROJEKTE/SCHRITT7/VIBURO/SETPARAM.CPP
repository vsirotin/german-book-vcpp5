// SetParam.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "SetParam.h"
#include "ViBuro.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CAddSitzungSeite, CPropertyPage)
IMPLEMENT_DYNCREATE(CPassSeite, CPropertyPage)
IMPLEMENT_DYNCREATE(CBankSeite, CPropertyPage)
IMPLEMENT_DYNCREATE(CAddresSeite, CPropertyPage)
IMPLEMENT_DYNCREATE(CNameSeite, CPropertyPage)
IMPLEMENT_DYNCREATE(CJobSeite, CPropertyPage)


/////////////////////////////////////////////////////////////////////////////
// CAddSitzungSeite property page

CAddSitzungSeite::CAddSitzungSeite() : CPropertyPage(CAddSitzungSeite::IDD)
{
	//{{AFX_DATA_INIT(CAddSitzungSeite)
	m_iAddSitzungAutomat = -1;
	//}}AFX_DATA_INIT

	if(theApp.m_bAddSitzungAutomat == TRUE)
		m_iAddSitzungAutomat = 1;
	else
		m_iAddSitzungAutomat = 0;

}

CAddSitzungSeite::~CAddSitzungSeite()
{
}

void CAddSitzungSeite::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddSitzungSeite)
	DDX_Radio(pDX, IDC_SITZUNG_ADD_JA, m_iAddSitzungAutomat);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddSitzungSeite, CPropertyPage)
	//{{AFX_MSG_MAP(CAddSitzungSeite)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPassSeite property page

CPassSeite::CPassSeite() : CPropertyPage(CPassSeite::IDD)
{
	//{{AFX_DATA_INIT(CPassSeite)
	m_sPassword = _T("");
	//}}AFX_DATA_INIT

	m_sPassword = theApp.m_sPassword;

}

CPassSeite::~CPassSeite()
{
}

void CPassSeite::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassSeite)
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPassSeite, CPropertyPage)
	//{{AFX_MSG_MAP(CPassSeite)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBankSeite property page

CBankSeite::CBankSeite() : CPropertyPage(CBankSeite::IDD)
{
	//{{AFX_DATA_INIT(CBankSeite)
	m_sBLZ = _T("");
	m_sGeldInstitut = _T("");
	m_sKontoStadt = _T("");
	m_sKonto = _T("");
	//}}AFX_DATA_INIT

	m_sBLZ = theApp.m_sBLZ;
	m_sGeldInstitut = theApp.m_sGeldInstitut;
	m_sKontoStadt = theApp.m_sKontoStadt;
	m_sKonto = theApp.m_sKonto;
}

CBankSeite::~CBankSeite()
{
}

void CBankSeite::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBankSeite)
	DDX_Text(pDX, IDCBankBLZ, m_sBLZ);
	DDX_Text(pDX, IDCBankGELDINSTITUT, m_sGeldInstitut);
	DDX_Text(pDX, IDCBankSTADT, m_sKontoStadt);
	DDX_Text(pDX, IDCBankKONTO, m_sKonto);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBankSeite, CPropertyPage)
	//{{AFX_MSG_MAP(CBankSeite)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CAddresSeite property page

CAddresSeite::CAddresSeite() : CPropertyPage(CAddresSeite::IDD)
{
	//{{AFX_DATA_INIT(CAddresSeite)
	m_sPLZ = _T("");
	m_sStadt = _T("");
	m_sStrasse = _T("");
	m_sTelefon = _T("");
	//}}AFX_DATA_INIT

	m_sPLZ = theApp.m_sPLZ;
	m_sStadt = theApp.m_sStadt;
	m_sStrasse = theApp.m_sStrasse;
	m_sTelefon = theApp.m_sTelefon;
}

CAddresSeite::~CAddresSeite()
{
}

void CAddresSeite::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddresSeite)
	DDX_Text(pDX, IDC_ADRES_PLZ, m_sPLZ);
	DDX_Text(pDX, IDC_ADRES_STADT, m_sStadt);
	DDX_Text(pDX, IDC_ADRES_STRASSE, m_sStrasse);
	DDX_Text(pDX, IDC_ADRES_TELEFON, m_sTelefon);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddresSeite, CPropertyPage)
	//{{AFX_MSG_MAP(CAddresSeite)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CNameSeite property page

CNameSeite::CNameSeite() : CPropertyPage(CNameSeite::IDD)
{
	//{{AFX_DATA_INIT(CNameSeite)
	m_nNameJahr = 0;
	m_nNameMonat = 0;
	m_sName = _T("");
	m_nNameTag = 0;
	m_sVorname = _T("");
	//}}AFX_DATA_INIT

	m_sName = theApp.m_sName;
	m_sVorname = theApp.m_sVorname;
	m_nNameJahr = theApp.m_nNameJahr;
	m_nNameMonat = theApp.m_nNameMonat;
	m_nNameTag = theApp.m_nNameTag;

}

CNameSeite::~CNameSeite()
{
}

void CNameSeite::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNameSeite)
	DDX_Text(pDX, IDC_NAME_JAHR, m_nNameJahr);
	DDV_MinMaxUInt(pDX, m_nNameJahr, 1900, 2000);
	DDX_Text(pDX, IDC_NAME_MONAT, m_nNameMonat);
	DDV_MinMaxUInt(pDX, m_nNameMonat, 1, 12);
	DDX_Text(pDX, IDC_NAME_NAME, m_sName);
	DDX_Text(pDX, IDC_NAME_TAG, m_nNameTag);
	DDV_MinMaxUInt(pDX, m_nNameTag, 1, 31);
	DDX_Text(pDX, IDC_NAME_VORNAME, m_sVorname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNameSeite, CPropertyPage)
	//{{AFX_MSG_MAP(CNameSeite)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CJobSeite property page

CJobSeite::CJobSeite() : CPropertyPage(CJobSeite::IDD)
{
	//{{AFX_DATA_INIT(CJobSeite)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CJobSeite::~CJobSeite()
{
}

void CJobSeite::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJobSeite)
	DDX_Control(pDX, IDC_JOB_COMBO, m_comboboxJob);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJobSeite, CPropertyPage)
	//{{AFX_MSG_MAP(CJobSeite)
	ON_CBN_SELCHANGE(IDC_JOB_COMBO, OnSelchangeJobCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



void CJobSeite::OnSelchangeJobCombo() 
{
	// TODO: Add your control notification handler code here
	
	theApp.m_iJobCode = m_comboboxJob.GetCurSel();
	theApp.WriteProfileInt("Tätigkeit", "JobCode", theApp.m_iJobCode);

 }

BOOL CJobSeite::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	m_comboboxJob.SetCurSel(theApp.m_iJobCode);

	if(theApp.m_bIamAdministrator != TRUE)
		SET_DLG_CTRL_STATE(IDC_JOB_COMBO, FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddSitzungSeite::OnOK() 
{
	// TODO: Add your specialized code here and/or call the base class

	int iAddAutomat = 0;
		if(m_iAddSitzungAutomat == 1)
		{
			theApp.m_bAddSitzungAutomat = TRUE;
			iAddAutomat = 1;
		}
		else
			theApp.m_bAddSitzungAutomat = FALSE;
	
	CPropertyPage::OnOK();
}

