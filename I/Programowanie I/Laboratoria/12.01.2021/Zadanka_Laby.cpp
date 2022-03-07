// Zadanka_Laby.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>

using namespace std;

void wypiszLiczby(int start)
{
    if (start > 0)
    {   
        cout << start << " ";
        wypiszLiczby(start - 5);
    }
    
    cout << start << " ";

}

void trojkat(int tab[], int rozmiar)
{
    if (rozmiar > 1)
    {
        int* liczby = new int[rozmiar - 1];

        for (int i = 0; i < rozmiar - 1; i++)
        {
            liczby[i] = tab[i] + tab[i + 1];
        }
        trojkat(liczby, rozmiar - 1);

        delete[] liczby;
    }

    for (int i = 0; i < rozmiar; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void zad_3(string zbior)
{

}

int main()
{
    //wypiszLiczby(6);
    int liczby[] = { 0,1,2,3,4 };
    //trojkat(liczby, 5);

    zad_3("abc");

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
