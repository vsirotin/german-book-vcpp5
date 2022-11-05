//Datum.h
//Die Klasse CDatum - Deklaration

class CDatum   
{
public:
	CDatum(int iJahr, int iMonat,  int iTag); // Konstruktor
	int GetDifferenz(int iCurrJahr, int CurrMonat, int iCurrTag); 
	~CDatum(); //Destruktor
private:
	int m_iJahr;  //Private Datenmitglieder
	int m_iMonat;
	int m_iTag;
};