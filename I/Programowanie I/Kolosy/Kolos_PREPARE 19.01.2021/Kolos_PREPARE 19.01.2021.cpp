// Kolos_PREPARE 19.01.2021.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;



//GRUPA 1?

struct punkt2D
{
    double x;
    double y;

    int numerCwiartki() 
    {
        if (x > 0 && y > 0) return 1;
        if (x < 0 && y > 0) return 2;
        if (x < 0 && y < 0) return 3;
        if (x > 0 && y < 0) return 4;
        if (x == 0 || y == 0) return -1;
    }

    double norma()
    {
        return sqrt(x * x + y * y);
    }

    double wspKierunkowy()
    {
        return (y / x);
    }

    void wypisz()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    void zapiszDoPliku(string nazwaPliku)
    {
        ofstream zapis(nazwaPliku);
        if (zapis.is_open())
        {
            zapis << "(" << x << ", " << y << ")" << endl;
            zapis.close();
        }
    }
};

double sredniaFunkcji(double (*fun)(double), double a, double b, int n)
{
    double zakres = b - a;
    double skok = zakres / n;
    double srednia{};
    int licznik{};

    for (double i = a; i <= b; i += skok)
    {
        cout << "i: " << i << " f(i): " << fun(i) << endl;
        srednia += fun(i);
        licznik++;
    }
    srednia /= n;

    ofstream zapis("gr_1_wynik.txt", ios::app);
    if (zapis.is_open())
    {
        zapis << "n = " << n << " Średnia: " << srednia << endl;
    }
    cout<<endl<< "Srednia: " << srednia <<" ILE: "<< licznik << endl<<endl;

    return srednia;
}
void zad_3_GR1()
{
    ifstream odczyt("tekst.txt");
    if (odczyt.is_open())
    {
        char wyraz[100];
        int ile_wyrazow{};
        while (odczyt >> wyraz)
        {
            ile_wyrazow++;
        }
        string* tekst = new string[ile_wyrazow];
        int i = 0;
        odczyt.clear();
        odczyt.seekg(0, ios::beg);

        while (odczyt >> wyraz && i < ile_wyrazow)
        {
            if (wyraz[0] != 'A' && wyraz[0] != 'a'&&
                wyraz[0] != 'E'&& wyraz[0] != 'e'&&
                wyraz[0] != 'I'&& wyraz[0] != 'i'&&
                wyraz[0] != 'O'&& wyraz[0] != 'o'&&
                wyraz[0] != 'U'&& wyraz[0] != 'u'&&
                wyraz[0] != 'Y'&& wyraz[0] != 'y')
            {
                tekst[i] = wyraz;
                i++;
            }
        }

        for (int j = 0; j < i; j++)
        {
            cout << tekst[j] << " ";
        }

        delete[] tekst;
        odczyt.close();
    }
}

//GRUPA 2?
struct wektor3D
{
    double x;
    double y;
    double z;

    double dlugoscWektora()
    {
        return sqrt(x*x + y*y + z*z);
    }
    double iloczynSkalarny(wektor3D w)
    {
        return x * w.x + y * w.y + z * w.z;
    }
    void wypisz()
    {
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }
    void zapiszDoPliku(string nazwaPliku)
    {
        ofstream zapis(nazwaPliku);
        if (zapis.is_open())
        {
            zapis << "[" << x << ", " << y << ", " << z << "]" << endl;
            zapis.close();
        }
    }

};

double *minFunkcji(double (*fun)(double), double a, double b, int n)
{
    // b-a = zakres na którym działamy, dzieląc go przez n otrzymujemy wartość poszczególnej części
    //znaleźć MIN funkcji, czyli dla każdego f(n) znaleźć wartość i porównywać 

    double zakres = b - a;
    double punkt = zakres / n;
    double wspolrzedne[2]{};
    double min_y = fun(a);
    double min_x = a;
    int licznik = 0;
    cout << "Zakres: " << zakres << endl << "Punkt: " << punkt << endl << "MIN Poczatek X-Y: " << min_x << " - " << min_y << endl;

    for (double i = a; i <= b; i+= punkt)
    {
        cout << "i: " << i << " f(i): "<< fun(i) << endl;
        if (fun(i) < min_y)
        {
            min_y = fun(i);
            min_x = i;
            //cout << "ZMIANA! Nowe X-Y: " << min_x << " - " << min_y << endl;
        }
        licznik++;
    }
    wspolrzedne[0] = min_x;
    wspolrzedne[1] = min_y;

    cout << endl << "FINAL KORDY: " << wspolrzedne[0] << " - " << wspolrzedne[1] << endl;
    cout << "ILE: " << licznik << endl;

    ofstream zapis("wynik.txt", ios::app);
    if (zapis.is_open())
    {
        zapis << "n = " << n << " MIN: " << fun(wspolrzedne[0]) << ", (" << wspolrzedne[0] << ", " << wspolrzedne[1] << ")" << endl;
        zapis.close();
    }

    return wspolrzedne;
}

double f(double x)
{
    return x * x * sin(x);
}

void zad_3()
{
    ifstream odczyt("tekst.txt");
    if (odczyt.is_open())
    {
        char wyraz[100];
        int ile_wyrazow{};
        while (odczyt >> wyraz)
        {
            ile_wyrazow++;
        }
        string* tekst = new string[ile_wyrazow/2];
        bool drugi = false;
        int i = 0;

        odczyt.clear();
        odczyt.seekg(0, ios::beg);

        while (odczyt >> wyraz && i < ile_wyrazow/2)
        {
            if (drugi == true)
            {
                drugi = false;
                tekst[i] = wyraz;
                i++;
            }
            else
            {
                drugi = true;
            }
        }

        for (int j = 0; j < i; j++)
        {
            cout << tekst[j] << " ";
        }

        delete[] tekst;
        odczyt.close();
    }
}

int main()
{
    //Grupa 2?
    //Zad 1
    wektor3D jedyneczka;
    jedyneczka.x = 3;
    jedyneczka.y = 5;
    jedyneczka.z = 8;

    wektor3D dwujka;
    dwujka.x = 1;
    dwujka.y = 13;
    dwujka.z = 4;

    //cout << jedyneczka.dlugoscWektora() << endl;
    //cout << jedyneczka.iloczynSkalarny(dwujka) << endl;
    //jedyneczka.wypisz();
    //jedyneczka.zapiszDoPliku("siema.txt");

    //Zad 2
    minFunkcji(f, 3, 9, 5);
    //minFunkcji(f, 3, 9, 10);
    //minFunkcji(f, 3, 9, 50);

    //Zad3
    //zad_3();

    //Grupa 1?

    //Zad1
    punkt2D mariusz;

    mariusz.x = 3;
    mariusz.y = 4;
    /*cout << mariusz.norma() << endl;
    cout << mariusz.numerCwiartki() << endl;
    cout << mariusz.wspKierunkowy() << endl;
    mariusz.wypisz();
    mariusz.zapiszDoPliku("gr1.txt");*/

    sredniaFunkcji(f, 3, 9, 5);
    //sredniaFunkcji(f, 3, 9, 10);
    //sredniaFunkcji(f, 3, 9, 50);
    //zad_3_GR1();

}