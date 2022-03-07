/* Zadanie:
    1) wywołaj szablon funkcji max().
    2) Na jego podstawie zbuduj szablon zwracający wartość największą z trzech podanych argumentów.
    3) Zbuduj szablon klasy walec i utwórz w nim szablon metody obliczającej pole powierzchni dla różnych typów danych. 
    Ciało metody powinno znaleźć się poza klasą.*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

template <typename Typ>
Typ max_of_3(Typ a, Typ b, Typ c)
{
    if (max(a,b) > max(b,c)) return max(a,b);
    else return max(b,c);
}

template <typename Typ>
class Walec
{
    Typ r, h;
public:
    Walec(Typ r, Typ h)
    {
        this->r = r;
        this->h = h;
    }
    Walec()
    {
        r = 2;
        h = 2;
    }

    Typ walec_pole(Typ r, Typ h);
    Typ walec_pole_2();
};

template <typename Typ>
Typ Walec<Typ>::walec_pole(Typ r, Typ h)
{
    return 2 * M_PI * r * (r + h);
}

template <typename Typ>
Typ Walec<Typ>::walec_pole_2()
{
    return 2 * M_PI * r * (r + h);
}

int main()
{
    cout << "MAX (1,2): "<< max(1,2) << endl;
    cout << "MAX (1,2,3): "<< max_of_3(1, 2, 3) << endl;
    cout << "MAX (1.5 , 2.9 , 3.1): " << max_of_3(1.5, 2.9, 3.1) << endl;
    cout << endl;

    Walec<int>walec_1(3, 2);
    cout << "Pole walca_1 wynosi: "<< walec_1.walec_pole(3,2)<<endl;
    cout << "Pole walca_1 wynosi: " << walec_1.walec_pole_2() << endl;
    cout << endl;

    Walec<double>walec_2(7.1, 3.2);
    cout << "Pole walca_2 wynosi: " << walec_2.walec_pole(7.1, 3.2) << endl;
    cout << "Pole walca_2 wynosi: " << walec_2.walec_pole_2() << endl;
    cout << endl;

    Walec<float>walec_3;
    cout << "Pole walca_3 wynosi: " << walec_3.walec_pole_2() << endl;
}
