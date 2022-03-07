#include <iostream>

using namespace std;

class Auto
{
private:
    int numer;
    char id;
    static char ID;

public:
    Auto()
    {
        id = ID++;
        numer = 0;
        cout << "Auto(): " << id << numer << endl;
    }
    Auto(int a)
    {
        id = ID++;
        numer = a;
        cout << "Auto(int): " << id << numer << endl;
    }
    ~Auto()
    {
        cout << "Usuwam: " << id << numer << endl;
    }
};

char Auto::ID = 'A';

Auto auto1;

int main()
{
    {
        Auto auto3 = Auto();
        Auto auto4 = Auto();
    }
    Auto* auto5 = new Auto();
    Auto* auto6 = new Auto(6);

    delete auto5;
    delete auto6;

    Auto* auto7 = new Auto(7);
    delete auto7;

    Auto auto9(9);
}

Auto auto2(2);