// ParcAuto.cpp : main project file.
#include "stdafx.h"
#include <iostream>
#include "ModeleParc.h"
#include <algorithm>
#include <vector>
using namespace System;
using namespace std;

int main() {
	const int capacitate_parc = 150;

	array<ModeleParc^>^ stoc = gcnew array<ModeleParc^>(capacitate_parc);

	stoc[1] = gcnew ModeleParc(1, "Volkswagen Passat B8", 15000, 2020, "Benzina", "Disponibil");
	stoc[2] = gcnew ModeleParc(2, "Dacia Logan", 8500, 2015, "Benzina", "Disponibil");
	stoc[3] = gcnew ModeleParc(3, "Volvo XC60", 19500, 2017, "Motorina", "Disponibil");
	stoc[4] = gcnew ModeleParc(4, "Range Rover Evoque", 29500, 2020, "Motorina", "Disponibil");
	stoc[5] = gcnew ModeleParc(5, "BMW X5", 29500, 2020, "Hybrid", "Disponibil");
	
	int numar_stoc = 0;
		for (int i = 0; i < stoc->Length; i++)
		{
			if (stoc[i] != nullptr)
			{
				numar_stoc++;
			}
		}

	int optiune;
	cout << "Bun venit in aplicatia Parcului Auto! Selecteaza o optiune:\n";
	
	do {
		Console::WriteLine("1. Afiseaza modelele stoc");
		Console::WriteLine("2. Introdu autoturism");
		Console::WriteLine("3. Ordoneaza modele dupa pret");
		Console::WriteLine("4. Actualizeaza pret");
		Console::WriteLine("5. Seteaza model vandut");
		Console::WriteLine("0. Iesire");
		Console::WriteLine("Introduceti optiunea: ");
		cin >> optiune;
		switch (optiune)
		{
		case 1:
			for (int i = 1; i <= numar_stoc; i++)
			{
				stoc[i]->afiseazaModel();
			}
			break;
		case 2:
			long id; String^ marca; double pret; int an; String^ combustibil; String^ status;
			Console::WriteLine("Introduceti ID:");
			cin >> id;
			Console::WriteLine("Introduceti marca:");
			marca = Console::ReadLine();
			Console::WriteLine("Introduceti pretul:");
			cin >> pret;
			Console::WriteLine("Introduceti anul fabricatiei:");
			cin >> an;
			Console::WriteLine("Introduceti combustibil:");
			combustibil = Console::ReadLine();
			Console::WriteLine("Introduceti status-ul:");
			status = Console::ReadLine();

			stoc[numar_stoc + 1] = gcnew ModeleParc(numar_stoc + 1, marca, pret, an, combustibil, status);
			numar_stoc++;
			Console::WriteLine("Felicitari, modelul a fost introdus!");
			break;
		case 3: 
			{
				System::String^ ordine;
				Console::WriteLine("Introduceti ordinea de sortare crescator/descrescator:");
				ordine = Console::ReadLine();
				if (ordine == "crescator")
				{
					for (int i = 1; i < numar_stoc; i++)
					{
						for (int j = 1; j < numar_stoc - i - 1; j++)
						{
							if (stoc[j]->pretOrdonare() > stoc[j + 1]->pretOrdonare())
							{
								ModeleParc^ temporar = stoc[j];
								stoc[j] = stoc[j + 1];
								stoc[j + 1] = temporar;
							}
						}
					}
					for (int i = 1; i < numar_stoc; i++){
						stoc[i]->afiseazaModel();
					}
				}
				else if (ordine == "descrescator")
				{
					for (int i = 1; i < numar_stoc; i++)
					{
						for (int j = 1; j < numar_stoc - i; j++)
						{
							if (stoc[j]->pretOrdonare() < stoc[j + 1]->pretOrdonare())
							{
								ModeleParc^ temporar = stoc[j];
								stoc[j] = stoc[j + 1];
								stoc[j + 1] = temporar;
							}
						}
					}
					for (int i = 1; i < numar_stoc; i++)
					{
						stoc[i]->afiseazaModel();
					}
				}
				else {
					Console::WriteLine("Nu ai introdus o optiune valida!");
				}
				break;
			}
            case 4: {
				Console::WriteLine("Introduceti ID-ul masinii pentru care doriti sa actualizati pretul:");
				long ID_pret_actualizat;
				cin >> ID_pret_actualizat;
				Console::WriteLine("Introduceti pretul actualizat:");
				long pret_nou;
				cin >> pret_nou;	
				stoc[ID_pret_actualizat]->actualizeazaPret(pret_nou);
				break;
            }
            case 5: {
				Console::WriteLine("Introduceti ID-ul masinii vandute:");
				long ID_model_vandut;
				cin >> ID_model_vandut;
				Console::WriteLine("Introduceti statusul (Vandut/Rezervat):");
				String^ status;
				status = Console::ReadLine();;	
				stoc[ID_model_vandut]->ModeleVandute(ID_model_vandut, status);
				break;
            }
            case 0:
                cout << "La revedere!\n";
                break;
            default:
                cout << "Nu ai introdus o optiune valida!\n";
                break;
        }
    } while (optiune != 0);

    return 0;
}
