//Person.h
//Die Klasse CPerson - Deklaration
#ifndef __PERSON_H__
#define __PERSON_H__
#include "Datum.h"
class CPerson   
{
public:
	CPerson();  //Default Konstruktor
	void SetName(char* pszName); 
	void SetVorname(char* pszVorname); 
	void SetGebDatum(int iJahr, int iMonat, int iTag); 
	int GetAlt(int iCurrJahr, int iCurrMonat, int iCurrTag) const; 
	int GetAlt() const;
	void TypeAuskunft() const;
	~CPerson(); //Destruktor
private:
	char m_pszName[30];  //Private Datenmitglieder
	char m_pszVorname[30];
	CDatum *m_pGebTag;
};

//Macro:

#define SET_PERSONAL_DATEN(p) {					\
	if(p == NULL)								\
		return;									\
	p->SetGebDatum(theApp.m_nNameJahr,			\
		theApp.m_nNameMonat, theApp.m_nNameTag);\
}	

#endif //__PERSON_H__