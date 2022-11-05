//Mitarb.h
//Die Deklaration der Klasse CMitarbeiter
#ifndef __MITARB_H__
#define __MITARB_H__
#include "Person.h"
class CMitarbeiter : public CPerson   
{
public:
	CMitarbeiter();  //Default Konstruktor
	virtual double  GetGehalt() const;
	void SetDienst(char* pszDienst);
	void TypeAuskunft(void) const;
	~CMitarbeiter(); //Destruktor

private:

	static int m_iGehaltBasis;  //Private Datenmitglieder
	static int m_iAltKoeffizient;

protected:
	char m_szDienst[30];
};
 
#endif //__MITARB_H__