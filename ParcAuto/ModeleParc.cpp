#include "stdafx.h" 
#include "ModeleParc.h"
#using <mscorlib.dll> 
using namespace std;
using namespace System;
using namespace System::IO;

void ModeleParc::dateModel(long id, String^ model, double valoare, int an, String^ carburant, String^ status)
{
	nrID = id;
	marca = model;
	pret = valoare;
	anFabricatie = an;
	combustibil = carburant;
	disponibilitate = status;
}

void ModeleParc::actualizeazaPret(double pretNou)
{
	pret = pretNou;
}

void ModeleParc::afiseazaModel()
{
	Console::Write("ID: "); 
	Console::WriteLine(nrID);
	Console::Write("Marca: "); 
	Console::WriteLine(marca);
	Console::Write("Pretul este: "); 
	Console::WriteLine(pret);
	Console::Write("Anul fabricatiei: "); 
	Console::WriteLine(anFabricatie);
	Console::Write("Combustibil: "); 
	Console::WriteLine(combustibil);
	Console::Write("Stoc: "); 
	Console::WriteLine(disponibilitate);
}

double ModeleParc::pretOrdonare()
{
	return pret;
}

ModeleParc::ModeleParc(long id, String^ model, double valoare, int an, String^ carburant, String^ status) 
{ 
	nrID = id;
	marca = model;
	pret = valoare;
	anFabricatie = an;
	combustibil = carburant; 
	disponibilitate = status;
}void ModeleParc::ModeleVandute(long id, String^ status)
{
	nrID_vandut = id;
	disponibilitate = status;
}