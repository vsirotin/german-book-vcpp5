//ArbeitsTag.h
// Klasse für Arbeit mit Arbeitszeit: Implementation
#include "stdafx.h"
#include "ViBuro.h"
#include "ArbeitsTag.h"

IMPLEMENT_SERIAL(CArbeitsTag, CObject, 0);

CArbeitsTag::CArbeitsTag(){};

CArbeitsTag::CArbeitsTag(UINT nTag)
{
	m_nTag = nTag;
	m_nMin = 0;
};

void CArbeitsTag::SetMin(UINT nMin)
{
	m_nMin = nMin;
};

UINT CArbeitsTag::GetMin()
{
	return m_nMin;
};

void CArbeitsTag::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
		ar << m_nTag << m_nMin;
	else
		ar >> m_nTag >> m_nMin;
};


UINT CArbeitsTag::GetTag()
{
	return m_nTag;
}
