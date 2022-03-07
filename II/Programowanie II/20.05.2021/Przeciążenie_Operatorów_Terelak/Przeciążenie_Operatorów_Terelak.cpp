// Zadanie:
// Wybierz cztery operatory, które będziesz przeładowywał(dwa jednoargumentowe oraz dwa dwuargumentowe).
// Następnie napisz funkcje przeładowujące. Każdy typ operatora powinien mieć utworzoną funkcję w postaci funkcji globalnej oraz metody klasy.

#include <iostream>
#include <string>

using namespace std;

class Dane
{
public:
	double a, b;
	string nazwa;
	Dane()
	{
		this->a = 2;
		this->b = 1;
		nazwa = "Radek";
	}
	Dane(string nazwa)
	{
		this->a = 1;
		this->b = 2;
		this->nazwa = nazwa;
	}
	Dane(double a, double b)
	{
		this->a = a;
		this->b = b;
		nazwa = "Radek";
	}

	Dane operator !()
	{
		return Dane(b, a);
	}
	friend Dane operator -(const Dane& d);

	Dane operator >(int x)
	{
		return Dane(a + x, b + x);
	}
	friend ostream& operator <<(ostream& o, const Dane& d);
};


Dane operator -(const Dane& d)
{
	string x = d.nazwa;
	reverse(x.begin(), x.end());
	return Dane(x);
}

ostream& operator <<(ostream& o, const Dane& d)
{
	return o << d.nazwa << ": " << d.a << "; " << d.b << endl;
}

int main()
{
	Dane d1(3, 7);
	cout << d1;
	cout << "Uzycie !: " << endl;
	d1 = !d1;
	cout << d1;
	cout << "Uzycie >: " << endl;
	d1 = d1>5;
	cout << d1 << endl;
	cout << "______________" << endl<<endl;
	Dane d2("Programowanie");
	cout << d2;
	cout << "Uzycie -: " << endl;
	d2 = -d2;
	cout << d2;
}