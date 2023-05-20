using namespace System;
ref class ModeleParc
{
public:
	void dateModel(long id, String^ model, double valoare, int an, String^ carburant, String^ status);
    void actualizeazaPret(double pretNou);
	void afiseazaModel();
	double pretOrdonare();
	ModeleParc(long id, String^ model, double valoare, int an, String^ carburant, String^ status);
	void ModeleVandute(long id, String^ status);
private:
	long nrID;
	String^ marca;
	double pret;
	int anFabricatie;
	String^ combustibil;
	long nrID_vandut;
	String^ disponibilitate;
};
