//Datum1.cpp
//Projekt Datum1 - Hauptmodul
//
//--------------Demonstration der CDatum Klasse--------------
//
#include "iostream.h"
#include "datum.h"

void main()
{
	CDatum einGeburtstag(1972, 11, 24);
	int iDif = einGeburtstag.GetDifferenz(1996, 12, 15);

	cout << iDif;
	cout <<'\n';
	cout << einGeburtstag.GetDifferenz(1973, 11, 23);
	cout <<'\n';
	cout << einGeburtstag.GetDifferenz(1973, 11, 25);
	cout <<'\n';
}
