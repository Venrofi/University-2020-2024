// zad1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Podaj a,b,c: "<<endl;
    cin >> a >> b >> c;

    float delta;
    float x0, x1, x2;

    delta = (b * b) - (4 * a * c);

    if (delta > 0)
    {
        x1 = (-b - sqrt(delta)) / 2 * a;
        x2 = (-b + sqrt(delta)) / 2 * a;
    }

    else if (delta == 0)
    {
        x0 = -b / 2 * a;
    }
                     
    cout << "Funkcja kwadratowa: f(x) = ";
    if (a == 1)
    {
        cout << "x^2";
    }
    else if (a == -1)
    {
        cout << "-x^2";
    }
    else if (a != 0)
    {
        cout << a << "x^2";
    }

    if (b == 1)
    {
        cout << "+x";
    }
    else if (b == -1)
    {
        cout << "-x";
    }
    else if (b != 0)
    {
        cout << b << "x";
    }

    if (c > 0)
    {
        cout <<"+"<< c;
    }
    else if(c < 0)
    {
        cout << c;
    }

    if (delta > 0)
        cout << endl << "Miejsca zerowe: " << x1 << ", " << x2;
    else if (delta == 0)
        cout << endl << "Miejsce zerowe: " << x0;
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
