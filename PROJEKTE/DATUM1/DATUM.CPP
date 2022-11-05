//Datum.cpp
//
//Die Klasse CDatum  - Implementation
#include "datum.h"

CDatum::CDatum(int iJahr, int iMonat,  int iTag) // Konstruktor
{
	m_iJahr = iJahr;
	m_iMonat = iMonat;
	m_iTag = iTag;
}

int CDatum::GetDifferenz(int iCurrJahr, int CurrMonat, int iCurrTag)
{
	//Diese Funktion berechnet die Zahl der vollen Jahren der 
	//Differenz zwischen dem durch die Paramter vorgebenen Datum
	//und dem in der Klasse festgelegtem Datum. 

	int iRes;
	iRes = iCurrJahr - m_iJahr;
	
	if(m_iMonat > CurrMonat)
		return iRes - 1;
	else if(m_iTag > iCurrTag)
		return iRes - 1;
	else
		return iRes;
}
	CDatum::~CDatum(){}; //Destruktor
