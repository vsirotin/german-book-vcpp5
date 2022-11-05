//Person.cpp
//Die Klasse CPerson  - Implementation

#include "stdafx.h"
#include "ViBuro.h"
#include <iostream.h>
#include <string.h>
#include "datum.h"
#include "person.h"

CPerson::CPerson() // Default Konstruktor
{
	m_pGebTag = NULL;
}

void CPerson::SetName(char* pszName) 
{
	strncpy(m_pszName,pszName,30);
	return;
}

void CPerson::SetVorname(char* pszVorname) 
{
	strncpy(m_pszVorname,pszVorname,30);
	return;
}

void CPerson::SetGebDatum(int iJahr, int iMonat, int iTag)
{
	if(m_pGebTag != NULL)
		delete m_pGebTag;

	m_pGebTag = new CDatum(iJahr, iMonat, iTag);
	return;
}

int CPerson::GetAlt(int iCurrJahr, int CurrMonat, int iCurrTag)	const
{
	if(m_pGebTag != NULL)
	{
		int iRes = m_pGebTag->GetDifferenz(iCurrJahr, 
			CurrMonat, iCurrTag);
		return iRes;
	}
	else
		return -1;
}

int CPerson::GetAlt() const
{
	// Achtung! Dies ist eine vorläufige Lösung!
	int iCurrJahr = 1996;
	int iCurrMonat = 12;
	int iCurrTag = 10;

	return GetAlt(iCurrJahr, iCurrMonat, iCurrTag);
}
	
void CPerson::TypeAuskunft(void) const
{
 /*
	cout << "Name: \t\t";
	cout <<  m_pszName;
	cout <<  "\n";
	
	cout << "Vorname: \t";
	cout <<  m_pszVorname;
	cout <<  "\n";

	cout << "Lebensalter: \t";
	cout <<  GetAlt();
	cout <<  "\n";
  */
	
}


CPerson::~CPerson() //Destruktor
{
	if(m_pGebTag != NULL)
	{
		delete m_pGebTag;
		m_pGebTag = NULL;
	}
 }
