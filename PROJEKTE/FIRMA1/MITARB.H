//mitarb.h
//Die Deklaration der Klasse CMitarbeiter

class CMitarbeiter : public CPerson   
{
public:
	CMitarbeiter();  //Default Konstruktor
	virtual int  GetGehalt() const;
	void SetDienst(char* pszDienst);
	void TypeAuskunft(void) const;
	~CMitarbeiter(); //Destruktor

private:

	static int m_iGehaltBasis;  //Private Datenmitglieder
	static int m_iAltKoeffizient;

protected:
	char m_szDienst[30];
};