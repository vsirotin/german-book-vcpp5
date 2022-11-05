//StundenList.h
// Klasse für Arbeit mit Arbeitszeit: Deklaration
#ifndef __STUNDENLIST_H__
#define __STUNDENLIST_H__

class CStundenList : public CObject
{
	DECLARE_SERIAL (CStundenList)

public:
	
	CStundenList();
	~CStundenList();
	
	int GetMin(UINT nTag);
	int GetSumme();
	void DeleteTag(UINT nTag);
	
	void InsertOrChangeTag(UINT nTag, UINT nMin);

	void Serialize(CArchive& ar);

private:
	CMapWordToOb m_map;
	
public:

#ifdef _DEBUG
	void Dump(CDumpContext& dc) const;
#endif //_DEBUG

};
#endif //__STUNDENLIST_H__
