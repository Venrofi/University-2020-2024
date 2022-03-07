#include <iostream>

using namespace std;

class Punkt
{
private:
    int radek_punkt = 1;
    
public:
    Punkt()
    {
        cout << "Konstruktor domyslny: punkt" << endl;
    }

    Punkt(int radek_punkt)
    {
        cout << "Konstruktor parametryczny: punkt " << radek_punkt << endl;
    }

    ~Punkt()
    {
        cout << "Destruktor: punkt" << endl;
    }

    friend class Kolo;
    friend class Kwadrat;
};

class Kolo : public Punkt
{
private:
    int radek_kolo = 2;
    
public:
    Kolo()
    {
        cout << "Konstruktor domyslny: kolo" << endl;
    }
    Kolo(int radek_kolo):Punkt(radek_punkt = 1)
    {
        cout << "Konstruktor parametryczny: kolo " << radek_kolo <<endl;
    }
    ~Kolo()
    {
        cout << "Destruktor: kolo" << endl;
    }
    friend class Walec;
};

class Kwadrat : public Punkt
{
private:
    int radek_kwadrat = 2;

public:
    Kwadrat()
    {
        cout << "Konstruktor domyslny: kwadrat" << endl;
    }
    Kwadrat(int radek_kwadrat):Punkt(radek_punkt = 1)
    {
        cout << "Konstruktor parametryczny: kwadrat " << radek_kwadrat <<endl;
    }
    ~Kwadrat()
    {
        cout << "Destruktor: kwadrat" << endl;
    }
    friend class Prostopadloscian;
};

class Walec : public Kolo
{
private:
    int radek_walec = 3;

public:
    Walec()
    {
        cout << "Konstruktor domyslny: walec" << endl;
    }
    Walec(int radek_walec):Kolo(radek_kolo = 2)
    {
        cout << "Konstruktor parametryczny: walec " << radek_walec << endl;
    }
    ~Walec()
    {
        cout << "Destruktor: walec" << endl;
    }
};

class Prostopadloscian : public Kwadrat
{
private:
    int radek_prostopad = 3;

public:
    Prostopadloscian()
    {
        cout << "Konstruktor domyslny: prostopad" << endl;
    }
    Prostopadloscian(int radek_prostopad):Kwadrat(radek_kwadrat = 2)
    {
        cout << "Konstruktor parametryczny: prostopad "<< radek_prostopad << endl;
    }
    ~Prostopadloscian()
    {
        cout << "Destruktor: prostopad" << endl;
    }
};
int main()
{
    Walec walec_1;      //walec domyślny
    cout << endl;
    Walec walec_2(3);       // walec parametryczny
    
    cout << endl;
    
    Prostopadloscian prosto_1;      // prostopad domyślny
    cout << endl;
    Prostopadloscian prosto_2(3);       //prostopad parametryczny

    cout << endl;

}
