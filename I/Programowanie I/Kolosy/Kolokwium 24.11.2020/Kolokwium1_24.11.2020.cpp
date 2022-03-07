// Kolokwium1_24.11.2020.cpp 
// Radosław Terelak

#include <iostream>

using namespace std;

void zad_1(int a, int b, int c)
{
	int delta = (b * b) - (4 * a * c);

	if (delta > 0)
	{
		int x1 = (-b - sqrt(delta)) / 2 * a;
		int x2 = (-b + sqrt(delta)) / 2 * a;

		cout << "Postac iloczynowa: ";
		if (a != 1 && a != -1)
		{
			cout << a;
		}
		else if (a == -1)
		{
			cout << "-";
		}
		
		cout << "(x ";
		if (x1 > 0)
		{
			cout << "+ " << x1<<")(x";
		}
		else
		{
			cout << x1 << ")(x ";
		}

		if (x2 > 0)
		{
			cout << "+ " << x2 << ")";
		}
		else
		{
			cout<<" "<< x2 << ")";
		}
	}
	else if (delta == 0)
	{
		int x1 = -b / 2 * a;
		cout << "Postac iloczynowa: ";
		if (a != 1 && a != -1)
		{
			cout << a;
		}
		else if (a == -1)
		{
			cout << "-";
		}
		if (x1 > 0)
		{
			cout<< "(x + " << x1 << ")(x + " << x1 << ")";
		}
		else
		{
			cout << "(x " << x1 << ")(x " << x1 << ")";
		}
	}
	else
	{
		cout << "Brak postaci iloczynowej";
	}
}

void zmieniajCyfry(char* tekst)
{
	for (int i = 0; i < strlen(tekst); i++)
	{

		if (*(tekst + i) > 47 && *(tekst + i) < 57)
		{
			*(tekst + i) += 1;
		}
		else if (*(tekst + i) == 57)
		{
			*(tekst + i) = 48;
		}
		cout << *(tekst + i);
	}

}

int nww(int a, int b)
{
	int maksi{};

	if (a > b)
	{
		for (int i = 1; i < a; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				maksi = i;
			}
		}
	}
	else 
	{
		for (int i = 1; i < b; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				maksi = i;
			}
		}
	}
	
	return (a * b) / maksi;
}

int main()
{
	cout << "Zadanie 1:" << endl;
	zad_1(1, -1, -6);

	char tekst[] = "To kolokwium jest proste! 1234 Start.";

	cout <<endl<<endl<< "Zadanie 2:" << endl;
	zmieniajCyfry(tekst);
	
	cout<<endl<<endl<<"Zadanie 3:"<<endl<<nww(12, 8);

	return 0;
}

/*
// Zadanie 1 (6 pkt) (efekt 2)
// Napisz program, kt�ry pobiera od u�ytkownika trzy liczby a, b, c, symbolizuj�ce wsp�czynniki
// funkcji kwadratowej. Nast�pnie program wypisuje na ekranie posta� iloczynow� funkcji kwadratowej,
// o ile istnieje (warunek delta > 0). W przypadku, gdy taka posta� nie istnieje program wypisuje komunikat:
// "Brak postaci iloczynowej."
// Wskaz�wka. Posta� iloczynowa funkcji kwadratowej: a(x - x1)(x - x2),
// gdzie x1, x2 s� miejscami zerowymi funkcji kwadratowej.
// Na przyk�ad dla liczb a=1 b=-1 c=-6 program wypisze:
// "Postac iloczynowa: (x - 3)(x + 2)"
// Uwzgl�dni� formatowanie (a = 1, a = -1 oraz znaki miejsc zerowych)

// Zadanie 2 (6 pkt) (efekt 3)
// Napisz funkcj�, kt�ra dla zadanego tekstu w postaci tablicy znakowej (cstring),
// wypisuje ten tekst odpowiednio zmodyfikowany. Modyfikacja polega� ma na zmianie
// znak�w symbolizuj�cych cyfry� na znaki symbolizuj�ce cyfr� o jeden wi�ksz�.
// 0->1  1->2  2->3  3->4  4->5  5->6  6->7  7->8  8->9  9->0
// W przypadku znaku 9 zostanie on zamieniony na 0.
// Deklaracja funkcji: void zmieniajCyfry(char* tekst), gdzie tekst jest
// wska�nikiem do tablicy znak�w.
// Np. dla tekstu (tablicy znakowej przechowuj�cej cstringa): "To kolokwium jest proste! 1234 Start." funkcja wypisze tekst:
//
// "To kolokwium jest proste! 2345 Start."
// U�yj notacji wska�nikowej.

// Zadanie 3 (8 pkt) (efekt 3)
// Napisz funkcj�, kt�rej parametrami s� dwie liczby naturalne. Funkcja zwraca najmniejsz� wsp�ln�
// wielokrotno�� podanych liczb. Najmniejsz� wsp�ln� wielokrotno�ci� dw�ch liczb naturalnych
// nazywamy najmniejsz� liczb� naturln�, kt�ra jest podzielna zar�wno przez pierwsz�,
// jak i drug� liczb�.
// Deklaracja funkcji: int nww(int a, int b);
// np. nww(12, 8) = 24.


// deklaracje funkcji:
void zmieniajCyfry(char* tekst);
int nww(int a, int b);
*/
