//Freimitb.cpp
//Die Klasse  CFreiMitarbeiter - Implementation

#include "stdafx.h"
#include "ViBuro.h"
#include <iostream.h>
#include <string.h>
#include "datum.h"
#include "person.h"
#include "mitarb.h"
#include "freimitb.h"


CFreiMitarbeiter::CFreiMitarbeiter() // Default Konstruktor
{
	// cout << "Arbeitet CFreiMitarbeiter::CFreiMitarbeiter()\n";
	strncpy(m_szDienst, "Freier Mitarbeiter", 30);
}

double CFreiMitarbeiter::GetStundGehalt(double dMin) const
{
	// cout << "Atbeitet CFreiMitarbeiter::GetStundGehalt()\n";
	double dRes;
	dRes =  GetGehalt() * dMin / 150;
	return dRes;
}

CFreiMitarbeiter::~CFreiMitarbeiter() //Destruktor
{
}
