//freimitb.h
//Die Klasse CFreiMitarbeiter - Deklaration

class CFreiMitarbeiter : public CMitarbeiter   
{
public:
	CFreiMitarbeiter();  //Default Konstruktor
	int  GetStundGehalt(int iStund) const;
	~CFreiMitarbeiter(); //Destruktor

	
};
