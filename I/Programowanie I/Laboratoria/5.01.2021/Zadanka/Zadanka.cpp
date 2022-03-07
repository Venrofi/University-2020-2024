#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void otworzFun(string nazwaPliku, int n)
{
    double* argumenty;
    argumenty = new double[n + 1];

    double* wartosci;
    wartosci = new double[n + 1];
    
    fstream plik;
    plik.open(nazwaPliku);

    char dane[100];
    for (int i = 0; i < n; i++)
    {
        plik >> dane;
        argumenty[i] = stod(dane);

        plik >> dane;
        wartosci[i] = stod(dane);

        cout << "f("<<argumenty[i]<<") = " << wartosci[i]<<endl;
    }

    cout << endl << endl << "Pochodne: " << endl;
    for (int i = 0; i < n-1; i++)
    {
        cout << "f'(" << argumenty[i] << ") = " << (wartosci[i+1] - wartosci[i])/(argumenty[i+1] - argumenty[i]) << endl;
    }

    plik.close();
    delete[] wartosci;
    delete[] argumenty;
}

void zapiszFun(double (*f)(double x), double a, double b, int n, string nazwaPliku)
{
    fstream plik;
    plik.open(nazwaPliku, ios::out);

    for (double i = a; i <= b; i += ((b - a) / n))
    {
        //cout << i << "\t" << f(i) << endl;
        plik << i << "\t" << f(i) << endl;
    }

    plik.close();
}

double f(double x)
{
    return x * x;
}

int main()
{
    //zapiszFun(f, -2, 10, 240, "test.txt");
    //otworzFun("test.txt", 240);

    zapiszFun(f, 0, 5, 5, "test2.txt");
    otworzFun("test2.txt", 5);
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
