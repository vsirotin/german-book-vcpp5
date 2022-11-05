//Arbeitszeitlist.h
// Klasse für die Arbeitszeit pro Tag: Deklaration
#ifndef __ARBEITSZEITLISTE_H__
#define __ARBEITSZEITLISTE_H__

class CArbeitszeitlist : public CObject
{
	DECLARE_SERIAL (CArbeitszeitlist)

public:
	
	CArbeitszeitlist();
	~CArbeitszeitlist();
	
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
#endif //__ARBEITSZEITLISTE_H__
