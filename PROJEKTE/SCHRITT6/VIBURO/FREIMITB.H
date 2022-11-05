//Freimitb.h
//Die Klasse CFreiMitarbeiter - Deklaration
#ifndef __FREIMITB_H__
#define __FREIMITB_H__

class CFreiMitarbeiter : public CMitarbeiter   
{
public:
	CFreiMitarbeiter();  //Default Konstruktor
	double  GetStundGehalt(double dMin) const;
	~CFreiMitarbeiter(); //Destruktor

	
};

#endif __FREIMITB_H__