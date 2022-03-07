// Zadanka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct osoba {
    string imie;
    string nazwisko;
    int wiek;
    void info()
    {
        cout << "Imie: " << imie << endl << "Nazwisko: " << nazwisko << endl << "Wiek: " << wiek << endl;
    }
};

void zapiszOsobe(osoba o, string plik)
{
    ofstream zapis(plik);

    zapis << o.imie << endl;
    zapis << o.nazwisko << endl;
    zapis << "Wiek: "<< o.wiek << endl;

    zapis.close();
}

void wczytajOsobe(string plik)
{
    ifstream odczyt(plik);
    osoba student2;
    string wiersz{};
    if (odczyt.is_open())
    {
        getline(odczyt, wiersz);
        student2.imie = wiersz;

        getline(odczyt, wiersz);
        student2.nazwisko = wiersz;

        getline(odczyt, wiersz);
        wiersz = wiersz.substr(5);
        student2.wiek = stoi(wiersz);
    }
    student2.info();
}

bool polacz(string plikA, string plikB, string wynik)
{
    wynik = plikA + plikB;
    cout << endl << wynik;
    if (wynik.length() == plikA.length() + plikB.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    osoba student;
    student.imie = "Marek";
    student.nazwisko = "Nowak";
    student.wiek = 23;

    zapiszOsobe(student, "witam.txt");
    wczytajOsobe("witam.txt");

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
