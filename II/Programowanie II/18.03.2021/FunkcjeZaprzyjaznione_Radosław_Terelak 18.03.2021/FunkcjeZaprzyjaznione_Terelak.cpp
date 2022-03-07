#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Punkt;
class Kolo
{
public:
    int x_kolo, y_kolo, r;
    friend bool czyNalezy(const Punkt, const Kolo);
    Kolo()
    {
        cout << "Podaj wspolrzedna X kola: ";
        cin >> x_kolo;
        cout << "Podaj wspolrzedna Y kola: ";
        cin >> y_kolo;
        do
        {
            cout << "Podaj promien kola: ";
            cin >> r;
        } while (r <= 0);
    }
    virtual ~Kolo()
    {
        //cout << endl << "Destrukcja kola!" << endl;
    }
};

class Punkt
{
public:
    int x_pkt, y_pkt;
    friend bool czyNalezy(const Punkt, const Kolo);
    Punkt()
    {
        cout << "Podaj wspolrzedna X punktu: ";
        cin >> x_pkt;
        cout << "Podaj wspolrzedna Y punktu: ";
        cin >> y_pkt;
    }
    virtual ~Punkt()
    {
        //cout << endl << "Destrukcja punktu!" << endl;
    }
};

bool czyNalezy(Punkt punkt_a, Kolo srodek)
{
    float dlugosc_odcinka = sqrt(
        pow((srodek.x_kolo-punkt_a.x_pkt), 2) + pow((srodek.y_kolo - punkt_a.y_pkt), 2)
    );

    cout << "Wspolrzedne okregu: (" << srodek.x_kolo << ", " << srodek.y_kolo << ")" << endl;
    cout << "Wspolrzedne punktu: (" << punkt_a.x_pkt << ", " << punkt_a.y_pkt << ")" << endl;
    cout << setprecision(2) << "Dlugosc odcinka: "<< dlugosc_odcinka << endl;
    cout << "Dlugosc promienia: " << srodek.r << endl;

    if (dlugosc_odcinka <= srodek.r)
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
    Punkt punkt_1;
    Kolo kolo_1;
    cout << endl << "Sedzia zadecydowal ze punkt.." << endl;
    if (czyNalezy(punkt_1, kolo_1) == true)
    {
        cout << endl << "Punkt nalezy do kola!" << endl;
    }
    else
    {
        cout << endl << "Punkt nie nalezy do kola :(" << endl;
    }
}
