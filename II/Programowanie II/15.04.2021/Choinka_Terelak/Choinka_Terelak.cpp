  /*
    Utwórz w konsoli choinkę wykorzystując w tym celu symbol "*".
    Choinka ma wyglądać jak poniżej.
    wytyczne dotyczące choinki:
    - choinka ma wyglądać jak na rysunku ale dać możliwość wyboru użytkownikowi parametru początkowego,
    - użytkownik podaje liczbę linii w bloku 1,
    - blok 2 i 3 są o 2  linie większe,
    - stopka jest długości pierwszego bloku,
    - na łączeniu bloków 1 i 2 linia bloku 2 jest o 2 gwiazdki krótsza od zakończenia bloku 1,
    - na łączeniu bloków 2 i 3 linia bloku 3 jest o 6 gwiazdek krótsza od zakończenia bloku 2.

    Radosław Terelak®
*/

#include <iostream>
#include <iomanip>

using namespace std;


void drukuj_gwiazdki(int ilosc)
{
    for (int i = 0; i < ilosc; i++)
    {
        cout << "*";
    }
    cout << endl;
}
int main()
{
    int wysokosc;
    do
    {
        cout << "Podaj wysokosc (3-12): ";
        
        while (!(cin >> wysokosc))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Podaj liczbe z zakresu 3-12: ";
        }
    } while (wysokosc > 12 || wysokosc < 3);
    
    system("cls");

    cout << "Oto choinka o wysokosci bazowej " << wysokosc << endl;
    cout << endl << endl;

    int przestrzen = 4 * wysokosc;
    int ile_gwiazdek = 1;

    for (int i = 1; i <= wysokosc; i++)
    {
        cout << setw(przestrzen);
        drukuj_gwiazdki(ile_gwiazdek);

        ile_gwiazdek += 2;
        przestrzen -= 1;
    }

    przestrzen += 2;
    ile_gwiazdek -= 4;

    for (int i = 1; i <= wysokosc + 2; i++)
    {
        cout << setw(przestrzen);
        drukuj_gwiazdki(ile_gwiazdek);

        ile_gwiazdek += 2;
        przestrzen -= 1;
    }
    przestrzen += 4;
    ile_gwiazdek -= 8;

    for (int i = 1; i <= wysokosc + 2; i++)
    {
        cout << setw(przestrzen);
        drukuj_gwiazdki(ile_gwiazdek);

        ile_gwiazdek += 2;
        przestrzen -= 1;
    }

    przestrzen = 4*wysokosc;
    ile_gwiazdek = 1;

    for (int i = 1; i <= wysokosc; i++)
    {
        cout << setw(przestrzen);
        drukuj_gwiazdki(ile_gwiazdek);
    }
}