//Datum.h
//Die Klasse CDatum - Deklaration
#ifndef __DATUM_H__
#define __DATUM_H__

class CDatum   
{
public:
	CDatum(int iJahr, int iMonat,  int iTag); // Konstruktor
	int GetDifferenz(int iCurrJahr, int CurrMonat, int iCurrTag); 
	~CDatum(); //Destruktor
private:
	int m_iJahr;  //Private Datenmitgliedern
	int m_iMonat;
	int m_iTag;
};

#endif //__DATUM_H__