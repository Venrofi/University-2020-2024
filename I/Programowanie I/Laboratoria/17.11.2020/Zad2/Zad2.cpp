// Zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double wzor(double x)
{
    return pow(x, 2) - 9;
}

double bisekcja(double(*fun)(double x), double e, double a, double b)
{
    double m = (a + b) / 2;

    while (abs(b - a) >= 2 * e)
    {
        if (fun(m) == 0)
        {
            return m;
        }
        else
        {
            if (fun(a) * fun(m) < 0)
            {
                b = m;
            }
            else
            {
                a = m;
            }
            m = (a + b) / 2;
        }
    }
    return m;
}



int main()
{
    //cout<<wzor(2);

    cout<< bisekcja(wzor, 0.001, -1, 5);

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
