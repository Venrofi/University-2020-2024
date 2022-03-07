#include <iostream>
#include <cstdlib>

using namespace std;

//set 1
void zad_1(int a = -5, int b = 10)
{
	cout << "Zadanie 1"<< endl;
	int suma = 0;

	for (int i = a; i < b; i++)
	{
		if (i % 2 == 1 || i % 2 == -1)
		{
			suma += i;
		}
	}
	cout << "Liczby: " << "a = " << a << ", b = " << b << endl;
	cout << "SUMA: " << suma;
}

void dzielniki(int a = 126, int b = 162)
{
	cout << endl << endl << "Zadanie 2" << endl;
	cout <<"Wspolne dzielniki liczb: a = " << a << ", b = " << b << endl;

	if (a > b)
	{
		for (int i = 1; i < a; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				cout << i<<", ";
			}
		}
	}
	else
	{
		for (int i = 1; i < b; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				cout << i<<", ";
			}
		}
	}
}

void ileRazy(int* cyfry, int rozmiar = 10)
{
	cout << endl<<endl << "Zadanie 3" << endl;
	int ile[10]{};

	for (int i = 0; i < 10; i++)
	{
		int licznik = 0;
		for (int j = 0; j < rozmiar; j++)
		{
			if (*(cyfry + j) == i)
			{
				licznik++;
			}
		}
		*(ile + i) = licznik;
	}

	for (int i = 0; i < 10; i++)
	{
		if (*(ile + i) > 0)
		{
			cout << "Liczba wystapien " << i << " wynosi: " << *(ile + i) << endl;
		}
	}

}

//set2

void zad_4(int a = 3, int n = 5)
{
	for (int i = 0; i <= n; i++)
	{
		cout << a << "^" << i << " = " << pow(a, i);
		if (i != n)
		{
			cout << "," << endl;
		}
		else
		{
			cout << "." << endl;
		}
	}
}

int power(int a, int n)
{
	/*
	int wynik = a;
	for (int i = 1; i < n; i++)
	{
		cout << wynik << endl;
		wynik *= a;
	}
	*/
	if (n > 0)
	{
		return a*power(a,n-1);
	}
	else
	{
		return 1;
	}
}


double odchylenie(double* tab, int rozmiar)
{
	//d = 1 / n * [(x1 - m) ^ 2 + (x2 - m) ^ 2 + ... + (xn - m) ^ 2],

	int suma = 0;

	for (int i = 0; i < rozmiar; i++)
	{
		suma += *(tab + i);
	}
	
	double srednia = suma / rozmiar;
	double farfocel = 0;

	for (int i = 0; i < rozmiar; i++)
	{
		farfocel += (*(tab + i) - srednia) * (*(tab + i) - srednia);
	}

	double d = 1 / (rozmiar * farfocel);

	return d;
}


void szachownica(int rozmiar = 5)
{
	for (int i = 0; i < rozmiar; i++) // pion
	{
			for (int j = 0; j < 3; j++) // 3 wiersze
			{
				for (int z = 0; z < rozmiar; z++) // poziom 
				{
					if ((i+z) % 2 == 0)
					{
						cout << "___";
					}
					else
					{
						cout << "xxx";
					}
				}
				cout << endl;
			}
	}
}
int main()
{
	int a[10] = { 1, 4, 5, 1, 1, 4, 7, 5, 8, 0 };
	double b[10] = { 1, 4, 5, 1, 1, 4, 7, 5, 8, 0 };
	//zad_1();
	//dzielniki();
	//ileRazy(a);

	//zad_4();
	//cout<<power(3, 5);

	//cout << odchylenie(b, 10);
	szachownica();

	return 0;
}