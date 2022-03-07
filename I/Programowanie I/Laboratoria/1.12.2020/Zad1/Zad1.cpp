// Zad1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>

using namespace std;

void statystyka(double liczby[], int rozmiar)
{
    double max = liczby[0];
    double min = liczby[0];
    double mediana{};

    double* liczby2 = new double[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        liczby2[i] = liczby[i];
    }

    for (int i = 0; i < rozmiar; i++)
    {
        if (liczby2[i] > max)
        {
            max = liczby2[i];
        }

        if (liczby2[i] < min)
        {
            min = liczby2[i];
        }
    }

    bool zamiana = true;
    double hilfe{};

    while (zamiana == true)
    {
        zamiana = false;
        for (int i = 0; i < rozmiar-1; i++)
        {
            if (liczby2[i + 1] < liczby2[i])
            {
                hilfe = liczby2[i + 1];
                liczby2[i + 1] = liczby2[i];
                liczby2[i] = hilfe;
                zamiana = true;
            }
        }
    }

    for (int i = 0; i < rozmiar; i++)
    {
        cout << liczby2[i] << ", ";
    }
    

    if (rozmiar % 2 == 0)
    {
        mediana = (liczby2[rozmiar / 2] + liczby2[(rozmiar / 2) + 1]) / 2;
    }
    else
    {
        mediana = liczby2[rozmiar / 2];
    }

    cout << endl << "MAX: " <<max;
    cout << endl << "MIN: " <<min;
    cout << endl << "Mediana: " << mediana;

    delete[] liczby2;

}

void wypiszSlowa(string slowa[], int rozmiar, string fraza)
{
    cout << endl << "Slowa zawierajace fraze 'kot': " << endl;

    for (int i = 0; i < rozmiar; i++)
    {
        if (static_cast<int>(slowa[i].find(fraza)) != -1)
        {
            cout << slowa[i] << endl;
        }
    }
}

void transpond(double **dwa_de, int x, int y)
{
    cout << "Przed transpondowaniem: " << endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << dwa_de[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Po transpondowaniu: " << endl;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << dwa_de[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    /*
    int n;
    cout << "Podaj ilosc liczb: ";
    cin >> n;

    double* liczby = new double[n];

    cout << endl << "Podaj " << n << " liczb: "<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << "tab[ " << i << " ] = ";
        cin >> liczby[i];
    }
    statystyka(liczby, n);

    delete[] liczby;
    */

    /*
    int x;
    cout << "Podaj ilosc slow: ";
    cin >> x;

    string* slowa = new string[x];

    cout << endl << "Podaj " << x << " slow: " << endl;

    for (int i = 0; i < x; i++)
    {
        cout << "Podaj slowo " <<i+1<<": ";
        cin >> slowa[i];
    }

    wypiszSlowa(slowa, x, "kot");
    */
    int x{}, y{};
    cout << "X: ";
    cin >> x;
    
    cout << "Y: ";
    cin >> y;

    double** dwa_de = new double* [x];
    for (int i = 0; i < x; i++)
    {
        dwa_de[i] = new double[y];
        for (int j = 0; j < y; j++)
        {
            cout << "T[" << i << "][" << j << "] = ";
            cin >> dwa_de[i][j];
        }
    }

    transpond(dwa_de, x, y);

    delete[] dwa_de;

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
