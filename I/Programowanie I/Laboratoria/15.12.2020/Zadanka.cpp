#include <iostream>

using namespace std;

struct osoba
{
    string imie;
    string nazwisko;
    int wiek;
    osoba* kolejna;
    void info();
};
void osoba::info()
{
    cout << "Imie: " << imie << ", Nazwisko: " << nazwisko << ", Wiek: " << wiek << endl;
}
struct ListaOsob
{
    osoba* pierwsza{};
    void dodaj(osoba*);
    void usun(int nr);
    void drukujListe();
};

void ListaOsob::drukujListe()
{
    osoba* o = pierwsza;

    while (o)
    {
        o->info();
        o = o->kolejna;
    }
}

void ListaOsob::dodaj(osoba* o)
{

}

void ListaOsob::usun(int nr)
{

}
int main()
{
    
    osoba* AJ = new osoba;
    AJ->imie = "Artur";
    AJ->nazwisko = "Janus";
    AJ->wiek = 35;

    osoba* AM = new osoba;
    AM->imie = "Andrzej";
    AM->nazwisko = "Miszczyk";
    AM->wiek = 44;

    osoba* GG = new osoba;
    GG->imie = "Gustaw";
    GG->nazwisko = "Gromek";
    GG->wiek = 40;
    
    ListaOsob lista;
    lista.pierwsza = nullptr;

    lista.dodaj(AJ);
    lista.dodaj(AM);
    lista.dodaj(GG);

    lista.drukujListe();

    //cout << "-- USUWANKO --" << endl;
    //lista.usun(2);
    //lista.drukujListe();


}
