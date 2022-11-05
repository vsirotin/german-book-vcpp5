//Leiter.cpp
//Die Klasse CLeiter - Implementation

#include "iostream.h"
#include "string.h"
#include "datum.h"
#include "person.h"
#include "mitarb.h"
#include "leiter.h"

int CLeiter :: m_iGehaltLeiterErgaenzung = 6000;

CLeiter::CLeiter() // Default Konstruktor
{
	cout << "Arbeitet CLeiter::CLeiter() \n";
	strncpy(m_szDienst, "Leiter", 30);
}

int CLeiter::GetGehalt() const
{
	cout << "Arbeitet CLeiter::GetGehalt()\n";
	int iRes;
	iRes =  CMitarbeiter::GetGehalt() + m_iGehaltLeiterErgaenzung;
	return iRes;
}

CLeiter::~CLeiter() //Destruktor
{

}
