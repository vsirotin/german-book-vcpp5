//leiter.h
//Die Klasse CLeiter - Deklaration

class CLeiter : public CMitarbeiter   
{
public:
	CLeiter();  //Default Konstruktor
	virtual int  GetGehalt() const;
	~CLeiter(); //Destruktor

private:

	static int m_iGehaltLeiterErgaenzung;  //Private Datenmitglieder
};
