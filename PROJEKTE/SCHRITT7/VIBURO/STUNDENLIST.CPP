//CStundenList.h
// Klasse für Arbeit mit Arbeitszeitliste: Implementation
#include "stdafx.h"
#include "ViBuro.h"
#include "StundenList.h"
#include "ArbeitsTag.h"


IMPLEMENT_SERIAL(CStundenList, CObject, 0);

CStundenList :: CStundenList()
{
}

CStundenList :: ~CStundenList()
{
	POSITION pos = m_map.GetStartPosition();
	while(pos != NULL)
	{
		CObject* pObj;
		WORD wKey;
		m_map.GetNextAssoc(pos, wKey, pObj);
		DELETE_OBJECT(pObj);
	}
	m_map.RemoveAll();
};

void CStundenList :: InsertOrChangeTag(UINT nTag, UINT nMin)
{ 	
  	CObject* pTmp =  m_map[(WORD)nTag];
	if(pTmp != NULL)
	{
		((CArbeitsTag*) pTmp)->SetMin(nMin);
		return;
	}

	CArbeitsTag* pTag = new CArbeitsTag(nTag);
	pTag->SetMin(nMin);
	m_map[(WORD)nTag] =  pTag;

#ifdef _DEBUG
	afxDump.SetDepth(1);
	afxDump << &m_map;
#endif //_DEBUG
};

int CStundenList :: GetMin(UINT nTag)
{
	CObject* pObj;
	if(m_map.Lookup((WORD)nTag, pObj))
	{
		return ((CArbeitsTag*)pObj)->GetMin();
	}
	return 0;
};

int CStundenList :: GetSumme()
{
	int iSumme = 0;
	POSITION pos = m_map.GetStartPosition();
	while(pos != NULL)
	{
		CObject* pObj;
		WORD wKey;
		m_map.GetNextAssoc(pos, wKey, pObj);
		
		iSumme += ((CArbeitsTag*)pObj)->GetMin();
	}
	return iSumme;
};

void CStundenList :: DeleteTag(UINT nTag)
{
	CObject* pTmp =  m_map[(WORD)nTag];
	DELETE_OBJECT(pTmp);	
	m_map.RemoveKey((WORD)nTag);
}

void CStundenList::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		int iObjCount = m_map.GetCount();
		ar << iObjCount;
		
		POSITION pos = m_map.GetStartPosition();
		while(pos != NULL)
		{
			CObject* pObj;
			WORD wKey;
			m_map.GetNextAssoc(pos, wKey, pObj);
			((CArbeitsTag*)pObj)->Serialize(ar);
		}
	}
	else
	{
		int iObjCount;
		ar >> iObjCount;
	
		for(int i = 0; i < iObjCount; i++)
		{
			CArbeitsTag tagTmp;
			tagTmp.Serialize(ar);
		
			InsertOrChangeTag(tagTmp.GetTag(), tagTmp.GetMin());	
		}
	}
};

#ifdef _DEBUG

void CStundenList::Dump(CDumpContext& dc)const
{
		int iObjCount = m_map.GetCount();
		afxDump << "\n Anzahl den Objekten = " << iObjCount <<"\n";
		m_map.Dump(afxDump);
}
#endif //_DEBUG
