// Kolokwium 19.01.2021 Radosław Terelak Gr G ®
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

//Zad 1
struct tekst
{
	string txt;

	int liczbaZnakow()
	{
		return txt.length();
	}
	
	int cyfry()
	{
		int liczba_cyfr{};

		for (int i = 0; i < txt.length(); i++)
		{
			if (txt[i] == '0' || txt[i] == '1' || txt[i] == '2' || txt[i] == '3' || txt[i] == '4' ||
				txt[i] == '5' || txt[i] == '6' || txt[i] == '7' || txt[i] == '8' || txt[i] == '9')
			{
				liczba_cyfr++;
			}
		}

		return liczba_cyfr;
	}

	int ileWyrazow()
	{
		int ile_wyrazow{};

		for (int i = 0; i < txt.length(); i++)
		{
			if (txt[i] == ' ' || txt[i] == '\n' || txt[i] == '\t')
			{
				ile_wyrazow++;
			}
		}

		return ile_wyrazow;
	}

	string wyraz(int ind)
	{
		int wyrazy = ileWyrazow();
		string* tablica_wyrazow = new string[ileWyrazow()];
		int pozycja{};

		for (int i = 0; i < ileWyrazow(); i++)
		{
			for (int j = pozycja; j < txt.length(); j++)
			{
				if (txt[j] != '\n' && txt[j] != '\t' && txt[j] != ' ')
				{
					tablica_wyrazow[i] += txt[j];
					pozycja++;
				}
				else
				{
					pozycja++;
					break;
				}
			}
		}
		
		return tablica_wyrazow[ind];
	}
	
	void zamienMiejscami(int ind1, int ind2)
	{
		string* tablica_wyrazow = new string[ileWyrazow()];
		int pozycja{};
		int ile_w = ileWyrazow();

		for (int i = 0; i < ileWyrazow(); i++)
		{
			for (int j = pozycja; j < txt.length(); j++)
			{
				if (txt[j] != '\n' && txt[j] != '\t' && txt[j] != ' ')
				{
					tablica_wyrazow[i] += txt[j];
					pozycja++;
				}
				else
				{
					pozycja++;
					break;
				}
			}
		}

		tablica_wyrazow[ind1].swap(tablica_wyrazow[ind2]);

		txt = {};

		for (int i = 0; i < ile_w; i++)
		{
			txt += tablica_wyrazow[i];
		}

		cout << txt;

		delete[] tablica_wyrazow;
	}

	void zapiszDoPliku(string nazwaPliku)
	{
		ofstream zapis(nazwaPliku);

		if (zapis.is_open())
		{
			int wyrazy = ileWyrazow();
			int pozycja = 0;
			for (int i = 1; i < wyrazy + 1; i++)
			{
				//cout << i << ")" << " ";
				zapis << i << ")" << " ";
				while (zapis << txt && txt[pozycja] != ' ' && txt[pozycja] != '\n' && txt[pozycja] != '\t')
				{
					//cout << txt[pozycja];
					zapis << txt[pozycja];
					pozycja++;
				}
				//cout << endl;
				zapis << endl;
			}

			zapis.close();
		}
	}
};

//Zad2
double metodaProstokatow(double(*f)(double), double a, double b, int n)
{
	double zakres = b - a;
	double skok = zakres / n;
	double suma{};

	for (double i = a; i <= b; i += skok)
	{
		suma += f(i);
	}

	ofstream zapis("wynik.txt", ios::app);
	if (zapis.is_open())
	{
		zapis << "n = " << n << " calka: " << suma * skok<<endl;
	}

	zapis.close();

	return suma * skok;
}

double fun(double x)
{
	return x * x * sin(x);
}


//Zad3
void zad_3()
{
	ifstream odczyt("tekst.txt");
	if (odczyt.is_open())
	{
		string linia;
		int ile_linii{};
		while (!odczyt.eof())
		{
			getline(odczyt, linia);
			ile_linii++;
		}
		string* tekst = new string[ile_linii];
		int i = 0;
		odczyt.clear();
		odczyt.seekg(0, ios::beg);

		while (!odczyt.eof() && i < ile_linii)
		{
			getline(odczyt, tekst[i]);
			ile_linii++;
			i++;
		}

		delete[] tekst;
		odczyt.close();
	}
}

int main()
{
	//Zad1
	tekst zdanko;
	zdanko.txt = "Raz dwa trzy, 2021. Kolokwium Programowanie. ";
	
	cout<<"Liczba znakow: "<< zdanko.liczbaZnakow()<<endl;
	cout << "Ile wyrazow: " << zdanko.ileWyrazow() << endl;
	cout << "Cyfry: " << zdanko.cyfry() << endl;
	cout << "Wyraz indeks 2: " << zdanko.wyraz(2) << endl;
	cout << "Zapis do pliku test.txt" << endl; 
	zdanko.zapiszDoPliku("test.txt");
	zdanko.zamienMiejscami(0, 2);

	cout << endl << endl;
	//Zad2
	cout << "Zad 2, n=10: " << metodaProstokatow(fun, 2, 9, 10) << endl;
	cout << "Zad 2, n=50: " << metodaProstokatow(fun, 2, 9, 50) << endl;
	cout << "Zad 2, n=100: " << metodaProstokatow(fun, 2, 9, 100) << endl;
	
	cout << endl << endl;

	//Zad3
	zad_3();

}
