#include "funkcje.h"

int liczba(int a)
{
    int suma = 0;

    while (a != 0)
    {
        suma += a % 10;
        a = a / 10;
    }

    return suma;
}


int NWD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return a;
}

bool czyPierwsza(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

void wypiszPierwsze()
{
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                
            }
        }
    }
}


int potega(int podstawa, int wykladnik)
{
    int wynik = podstawa;
    wynik *= podstawa;

    return wynik;
}

double potega(double podstawa, int wykladnik)
{
    double wynik = podstawa;
    wynik *= podstawa;

    return wynik;
}

void potega(int& wynik, int podstawa, int wykladnik)
{
    int x = podstawa;
    for (int i = 1; i < wykladnik; i++)
    {
        x *= podstawa;
    }
    wynik = x;
}