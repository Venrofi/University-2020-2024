// Zad1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generuj_losowe_liczby(int* wsk, int rozmiar, int a, int b)
{
    for (int i = 0; i < rozmiar; i++)
    {
        int losowa = (rand() % (b - a)) + a;
        *wsk = losowa;
        wsk++;
    }
}

void wypisz_liczby(int* wsk, int rozmiar)
{
    cout << "[";
    for (int i = 0; i < rozmiar; i++)
    {
        cout << *wsk; 
        if (i != rozmiar - 1)
        {
            cout << ", ";
        }
        wsk++;
    }
    cout << "]";
}

int max(int* wsk, int rozmiar)
{
    int MAX = *wsk;
    for (int i = 0; i < rozmiar; i++)
    {
        if (*wsk > MAX)
        {
            MAX = *wsk;
        }
        wsk++;
    }
    return MAX;
}

void formatuj(char* s)
{
    int ascii;
    char zdanie_fixed[1024];
    
    for (int i = 0; i < 1024; i++)
    {
        ascii = int(*s);

        if (ascii > 96 && ascii< 123)
        {
            zdanie_fixed[i] = ascii-32;
        }
        else
        {
            zdanie_fixed[i] = ascii;
        }
        s++;

    }
    cout << zdanie_fixed;
}

void kwadraty(int* t1, int* t2, int n)
{
    for (int i = 0; i < n; i++)
    {
        *t1 = *t2 * *t2;
        cout << *t1<<", ";
        t1++;
        t2++;
    }

}
int main()
{
    srand(time(NULL));

    int liczby[10]{};
    int* wskaz = liczby;

    char zdanie[1024]{};
    //cout << "Podaj zdanie: ";
    //cin.getline(zdanie, 1024);

    //formatuj(&zdanie[0]);

    int tab1[10]{};
    int tab2[10] = { 1,2,3,4,5,6,7,8,9,10 };
    kwadraty(tab1, tab2, 10);

    //generuj_losowe_liczby(wskaz,10, 5, 100);
    //wypisz_liczby(wskaz, 10);
    //cout <<endl<<"MAX: "<< max(wskaz, 10);

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
