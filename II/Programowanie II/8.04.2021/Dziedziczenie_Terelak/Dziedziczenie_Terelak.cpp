//Utwórz klasę bazową, klasę do niej pochodną oraz klasę pochodną do klasy pochodnej.
//Napisz program, dzięki któremu sprawdzisz dostęp do elementów klasy bazowej dla metod i obiektów klas pochodnych.
//Dziedziczeniu przypisz atrybuty private, protected oraz public. W ramach każdej klasy utwórz atrybuty private, protected oraz public.
//Wyniki testów zapisz w utworzonej przez siebie tabeli.

#include <iostream>

using namespace std;

class Bazowa {
private:
    int baza_1;
protected:
    int baza_2;
public:
    void metoda_baza();
    int baza_3;
};

class Dziedzic_I: public Bazowa {
private:
    int dziedzic_1;
protected:
    int dziedzic_2;
public:
    void metoda_Dziedzic_I();
    int dziedzic_3;
};

class Dziedzic_II : public Dziedzic_I {
private:
    int dziedzic_4;
protected:
    int dziedzic_5;
public:
    int dziedzic_6;
    void metoda_Dziedzic_II();
};


void Bazowa::metoda_baza()
{
    cout << endl << "Uruchamiam Baza!" << endl;

    baza_1 = 1;
    baza_2 = 2;
    baza_3 = 3;

    cout << endl << "Zamykam baza!" << endl;
}
void Dziedzic_I::metoda_Dziedzic_I()
{
    cout << endl << "Uruchamiam Dziedzic_I!" << endl;

    baza_1 = 1;
    baza_2 = 2;
    baza_3 = 3;

    dziedzic_1 = 4;
    dziedzic_2 = 5;
    dziedzic_3 = 6;

    metoda_baza();

    cout << endl << "Zamykam Dziedzic_I!" << endl;
}

void Dziedzic_II::metoda_Dziedzic_II()
{
    cout << endl << "Uruchamiam Dziedzic_II!" << endl;

    baza_1 = 1;
    baza_2 = 2;
    baza_3 = 3;

    dziedzic_1 = 4;
    dziedzic_2 = 5;
    dziedzic_3 = 6;
    
    dziedzic_4 = 7;
    dziedzic_5 = 8;
    dziedzic_6 = 9;

    cout << endl << "Zamykam Dziedzic_II!" << endl;
}

int main()
{
    cout << endl << "Uruchamiamy program! Tworzymy obiekty klasy bazowej oraz dwoch dziedzicznych.."<<endl;

    Bazowa bazka;
    Dziedzic_I dzie_1;
    Dziedzic_II dzie_2;

    int radek;
    
    dzie_1.metoda_baza();
    dzie_2.metoda_baza();

    cout << endl << "Wywolujemy metody klas dziedzicznych.. " << endl;
    
    dzie_1.metoda_Dziedzic_I();
    dzie_2.metoda_Dziedzic_II();

    radek = bazka.baza_1;
    radek = bazka.baza_3;
    radek = bazka.baza_3;

    radek = dzie_1.baza_1;
    radek = dzie_1.baza_2;
    radek = dzie_1.baza_3;
    radek = dzie_1.dziedzic_1;
    radek = dzie_1.dziedzic_2;
    radek = dzie_1.dziedzic_3;

    radek = dzie_2.baza_1;
    radek = dzie_2.baza_2;
    radek = dzie_2.baza_3;
    radek = dzie_2.dziedzic_1;
    radek = dzie_2.dziedzic_2;
    radek = dzie_2.dziedzic_3;
    radek = dzie_2.dziedzic_4;
    radek = dzie_2.dziedzic_5;
    radek = dzie_2.dziedzic_6;

}
