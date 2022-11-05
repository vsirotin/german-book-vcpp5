//Firma1.cpp
//Projekt Firma1 - Hauptmodul

#include "iostream.h"
#include "datum.h"
#include "person.h"
#include "mitarb.h"
#include "leiter.h"
#include "freimitb.h"


void main()
{	 
	int iGehalt;
 	
	CMitarbeiter p1;
	p1.SetName("Santos");
	p1.SetVorname("Julia");
	p1.SetGebDatum(1971,2,14);
	p1.SetDienst("Sekretärin");	
	p1.TypeAuskunft();
	iGehalt = p1.GetGehalt();
	cout << "Gehalt: \t";
	cout <<  iGehalt;
	cout <<"\n\n";
	
	CMitarbeiter p2;
	p2.SetName("Urri");
	p2.SetVorname("Akira");
	p2.SetGebDatum(1968,12,24);
  	p2.TypeAuskunft();
	iGehalt = p2.GetGehalt();
	cout << "Gehalt: \t";
	cout <<  iGehalt;
	cout <<"\n Beliebige Buchstaben- und Eingabetaste drücken\n "; 
	
	char a;
	cin >>a;

	CLeiter p3;
	p3.SetName("Schorman");
	p3.SetVorname("Michael");
	p3.SetGebDatum(1941,7,19);
	p3.TypeAuskunft();
	iGehalt = p3.GetGehalt();
	cout << "Gehalt: \t";
	cout <<  iGehalt;
	cout <<"\n\n";

	CFreiMitarbeiter p4;
	p4.SetName("Newoinovski");
	p4.SetVorname("Gerald");
	p4.SetDienst("Programmierer");
	p4.SetGebDatum(1968,10,11);
	p4.TypeAuskunft();
	iGehalt = p4.GetStundGehalt(145);
	cout << "Gehalt: \t";
	cout <<  iGehalt;

	//Test-Aufruf
	cout << "\n\nDas Gehalt wird mit einer virtuellen Methode berechnet.\n";
	iGehalt = p4.GetGehalt();
	cout << "Gehalt: \t";
	cout <<  iGehalt;
	
	cout <<"\n\n";
}
