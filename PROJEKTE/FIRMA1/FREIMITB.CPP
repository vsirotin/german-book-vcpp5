//Freimitb.cpp
//Die Klasse  CFreiMitarbeiter - Implementation

#include "iostream.h"
#include "string.h"
#include "datum.h"
#include "person.h"
#include "mitarb.h"
#include "freimitb.h"


CFreiMitarbeiter::CFreiMitarbeiter() // Default Konstruktor
{
	cout << "Arbeitet CFreiMitarbeiter::CFreiMitarbeiter()\n";
	strncpy(m_szDienst, "Freier Mitarbeiter", 30);
}

int CFreiMitarbeiter::GetStundGehalt(int iStund) const
{
	cout << "Atbeitet CFreiMitarbeiter::GetStundGehalt()\n";
	int iRes;
	iRes =  GetGehalt() * iStund / 150;
	return iRes;
}

CFreiMitarbeiter::~CFreiMitarbeiter() //Destruktor
{
}
