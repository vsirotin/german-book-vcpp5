//Leiter.cpp
//Die Klasse CLeiter - Implementation

#include "stdafx.h"
#include "ViBuro.h"
#include <iostream.h>
#include <string.h>
#include "datum.h"
#include "person.h"
#include "mitarb.h"
#include "leiter.h"

int CLeiter :: m_iGehaltLeiterErgaenzung = 6000;

CLeiter::CLeiter() // Default Konstruktor
{
	//cout << "Arbeitet CLeiter::CLeiter() \n";
	strncpy(m_szDienst, "Leiter", 30);
}

double CLeiter::GetGehalt() const
{
	//cout << "Arbeitet CLeiter::GetGehalt()\n";
	double dRes;
	dRes =  CMitarbeiter::GetGehalt() + m_iGehaltLeiterErgaenzung;
	return dRes;
}

CLeiter::~CLeiter() //Destruktor
{

}

