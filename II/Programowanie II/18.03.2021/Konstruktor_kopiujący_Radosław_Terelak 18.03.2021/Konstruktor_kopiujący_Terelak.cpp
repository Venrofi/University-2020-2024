#include <iostream>

using namespace std;

class Klasa_A
{
public:
    int radek = 34;
    int* wsk = &radek;

    Klasa_A()
    {
        cout << "Konstruktor Klasy A" << endl;
    }
    virtual ~Klasa_A()
    {
        cout << "Destruktor Klasy A" << endl;
    }
};

class Klasa_B
{
public:
    Klasa_B()
    {
        cout << "Konstruktor Klasy B" << endl;
    }
    virtual ~Klasa_B()
    {
        cout << "Destruktor Klasy B" << endl;
    }
    Klasa_B(const Klasa_B& radek)
    {
        cout << "Konstruktor Kopiujacy Klasy B" << endl;
    }

    int radek = 35;
    int* wsk = &radek;
};

int main()
{
    Klasa_A obiekt_1;
    Klasa_A obiekt_2(obiekt_1);

    cout << endl;
    cout << "Wskaznik Obiektu 1 jest w: " << obiekt_1.wsk << endl;
    cout << "Wskaznik Obiektu 2 jest w: " << obiekt_2.wsk << endl;
    cout << endl;

    Klasa_B obiekt_3;
    Klasa_B obiekt_4(obiekt_3);

    cout << endl;
    cout << "Wskaznik Obiektu 3 jest w: " << obiekt_3.wsk << endl;
    cout << "Wskaznik Obiektu 4 jest w: " << obiekt_4.wsk << endl;
    cout << endl;

    return 0;
}
