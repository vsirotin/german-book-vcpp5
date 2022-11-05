//Mitarb.cpp
//Die Klasse CMitarbeiter  - Implementation
#include "stdafx.h"
#include "ViBuro.h"
#include <string.h>
#include <iostream.h>
#include "datum.h"
#include "person.h"
#include "mitarb.h"

int CMitarbeiter :: m_iGehaltBasis = 4000;
int CMitarbeiter :: m_iAltKoeffizient = 20;


CMitarbeiter::CMitarbeiter() // Default Konstruktor
{
	// cout << "Arbeitet CMitarbeiter::CMitarbeiter()\n";
	strncpy(m_szDienst, "Mitarbeiter",30);
}

double CMitarbeiter::GetGehalt() const
{
	// cout << "Arbeitet CMitarbeiter::GetGehalt()\n";
	int iLebensAlt = GetAlt();
	if(iLebensAlt > 0)
	{
		double dRes;
		dRes = m_iAltKoeffizient * iLebensAlt + m_iGehaltBasis;
		return dRes;
	}
	return 0;
}

void CMitarbeiter::SetDienst(char* pszDienst)
{
	strncpy(m_szDienst, pszDienst, 30);
}

CMitarbeiter::~CMitarbeiter() //Destruktor
{

}

void CMitarbeiter::TypeAuskunft(void) const
{
	/*
	cout << "\n -------Mitarbeiter:------- \n";
	CPerson:: TypeAuskunft();
	cout << "Dienst: \t";
	cout <<  m_szDienst;
	cout <<"\n"; 
	*/
}
