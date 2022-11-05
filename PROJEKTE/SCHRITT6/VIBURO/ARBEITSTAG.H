//ArbeitsTag.h
// Klasse für Arbeit mit Arbeitszeit: Deklaration
#ifndef __ARBEITSTAG_H__
#define __ARBEITSTAG_H__

class CArbeitsTag : public CObject
{
	DECLARE_SERIAL (CArbeitsTag)

//Attribute
private:
	UINT m_nTag;
	UINT m_nMin;

//Operationen
public:
	
	CArbeitsTag();
	CArbeitsTag(UINT nTag);

	UINT GetTag();
	void SetMin(UINT nMin);
	UINT GetMin();

	void Serialize(CArchive& ar);

#ifdef _DEBUG

	void Dump(CDumpContext& dc)const
	{
		CObject::Dump(dc);
		TRACE2("Tag: %d  Min: %d \n",  m_nTag, m_nMin);
	}
#endif //_DEBUG
};
#endif 
