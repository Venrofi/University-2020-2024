#include <iostream>

/*
    Napisz odpowiedni kod, dzięki któremu będziesz w stanie odpowiedzieć na poniższe pytania:
    1) Czy funkcja zaprzyjaźniona jest kopiowana wraz z kopią obiektu?
    2) Czy kopiowanie funkcji zaprzyjaźnionej wraz z kopią obiektu wymaga konstruktora kopiującego?
    3) Czy dla tworzonego obiektu, będącego kopią innego obiektu, uruchamiany jest konstruktor?
*/

using namespace std;


class Numero_Due;
class Numero_Uno
{
private:
    int numer;
    char id;
    static char ID;
public:
    friend void strada(Numero_Uno& uno, Numero_Due& due);

    Numero_Uno()
    {
        id = ID++;
        numer = 0;
        cout << "Domyslny Numero_Uno(): " << id << numer << endl;
    }
    virtual ~Numero_Uno()
    {
        cout << "Usuwam Numero_Uno(): " << id << numer << endl;
    }
};

class Numero_Due
{
private:
    int numer;
    char id;
    static char ID;

public:
    friend void strada(Numero_Uno& uno, Numero_Due& due);

    Numero_Due()
    {
        id = ID++;
        numer = 1;
        cout << "Domyslny Numero_Due(): " << id << numer << endl;
    }
    Numero_Due(const Numero_Due& radek) :id(radek.id), numer(radek.numer)
    {
        cout << "Skopiowany Numero_Due(): " << id << numer << endl;
    }
    virtual ~Numero_Due()
    {
        cout << "Usuwam Numero_Due(): " << id << numer << endl;
    }
};

void strada(Numero_Uno& uno, Numero_Due& due)
{
    cout << "Funkcja zaprzyjazniona dla obiektow: " << uno.id << uno.numer << " i " << due.id << due.numer << endl;
}
char Numero_Uno::ID = 'A';
char Numero_Due::ID = 'a';

int main()
{
    Numero_Uno jedyneczka;
    Numero_Uno dwa(jedyneczka); //kopia

    Numero_Due trzy;
    Numero_Due cztery(trzy); //kopia

    cout << endl << "Original: " << endl;
    strada(jedyneczka, trzy);

    cout << endl << "Copy: " << endl;
    strada(dwa, cztery);

    cout << endl;
/*
    1) Czy funkcja zaprzyjaźniona jest kopiowana wraz z kopią obiektu?
        Nie - funckja nie zawiera się w danej klasie, kopiuje się jedynie sama deklaracja przyjaźni, a nie funkcja sama w sobie.
    2) Czy kopiowanie funkcji zaprzyjaźnionej wraz z kopią obiektu wymaga konstruktora kopiującego? 
        Nie wymaga. W klasie pierwszej nie ma takiego a i tak się wyowłuje.
    3) Czy dla tworzonego obiektu, będącego kopią innego obiektu, uruchamiany jest konstruktor?
        Tak jeśli jest konst kopiujący, a jeśli go nie ma to się nie wywoła.
*/
}
