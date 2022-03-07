// Zadanka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int ile_bitow_roznicy(unsigned int a, unsigned int b)
{
	//int i = 0;
	//int j = 0;
	int licznik = 0;

	int tab_bin_1[32];
	int tab_bin_2[32];
	/*
	while (a)
	{
		tab_bin_1[i++] = a % 2;
		a /= 2;
	}
	while (b)
	{
		tab_bin_2[j++] = b % 2;
		b /= 2;
	}
	*/
	for (int i = 0; i < 32; i++)
	{
		tab_bin_1[i] = a % 2;
		a /= 2;
	}

	for (int i = 0; i < 32; i++)
	{
		tab_bin_2[i] = b % 2;
		b /= 2;
	}

	cout << "Postac binarna liczby a: ";
	for (int z = 31; z >= 0; z--)
	{
		cout << tab_bin_1[z];
		if (z % 8 == 0)
		{
			cout << " ";
		}
	}

	cout << endl << "Postac binarna liczby b: ";
	for (int z = 31; z >= 0; z--)
	{
		cout << tab_bin_2[z];
		if (z % 8 == 0)
		{
			cout << " ";
		}

		if (tab_bin_1[z] ^ tab_bin_2[z])
		{
			licznik++;
		}
	}

	return licznik;
}
	enum Platforma {
		PS4 = 0, PS5, Xbox, Switch, PC
	};

	struct Gra {
		string tytul;
		string wydawca;
		unsigned int rokWydania;
		unsigned int cena;
		Platforma platforma;
		void info()
		{
			cout << "Informacje o grze:" << endl;
			cout << tytul << ", " << wydawca << ", " << rokWydania << endl;
			cout << "Cena: " << cena << ", " << platforma<<", ";

			switch (platforma)
			{
				case 0:
					cout << "PS4";
					break;
				case 1:
					cout << "PS5";
					break;
				case 2:
					cout << "Xbox";
					break;
				case 3:
					cout << "Switch";
					break;
				case 4:
					cout << "PC";
					break;

				default:
					cout << "XD";
					break;
			}
			cout << endl;

		}
	};
	/*
	void Gra::info()
	{
		cout << "Informacje o grze:" << endl;
		cout << tytul << ", " << wydawca << ", " << rokWydania << endl;
		cout << "Cena: " << cena << ", " << platforma << endl;
	}
	*/

int main()
{	   
	//cout<<endl<< "Liczby roznia sie na "<<ile_bitow_roznicy(16, 18)<<" bitach.";
	Gra W3{ "Wiedzmin 3", "CDP RED", 2015, 120, PC };
	W3.info();

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
