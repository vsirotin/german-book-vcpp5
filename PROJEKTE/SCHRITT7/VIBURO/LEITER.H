//Leiter.h
//Die Klasse CLeiter - Deklaration
#ifndef __LEITER_H__
#define __LEITER_H__
#include "Mitarb.h"

class CLeiter : public CMitarbeiter   
{
public:
	CLeiter();  //Default Konstruktor
	virtual double  GetGehalt() const;
	~CLeiter(); //Destruktor

private:

	static int m_iGehaltLeiterErgaenzung;  //Private Datenmitglieder
};

#endif __LEITER_H__