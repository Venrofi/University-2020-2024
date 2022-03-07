#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class Obiekt
{
public:
	virtual void pole() = 0;

	virtual ~Obiekt()
	{
		cout << "Wirtualny destruktor" << endl;
	}
};

void oblicz(Obiekt* wsk)
{
	wsk->pole();
}

class Kolo : public Obiekt
{
private:
	float r;
public:
	Kolo(float r)
	{
		this->r = r;
	}
	virtual ~Kolo()
	{
		cout << "Destruktor Kolo" << endl;
	}
	virtual void pole()
	{
		cout << "Pole kola wynosi: "<< r * r * M_PI<< endl;
	}
};

class Kwadrat : public Obiekt
{
private:
	float a;
public:
	Kwadrat(float a)
	{
		this->a = a;
	}
	virtual ~Kwadrat()
	{
		cout << "Destruktor Kwadrat" << endl;
	}
	virtual void pole()
	{
		cout << "Pole kwadratu wynosi: " << a * a << endl;
	}
};

class Walec : public Kolo
{
private:
	float r,H;
public:
	Walec(float r, float H): Kolo(r)
	{
		this->r = r;
		this->H = H;
	}
	virtual ~Walec()
	{
		cout << "Destruktor Walec" << endl;
	}
	virtual void pole()
	{
		cout << "Pole walca wynosi: " << 2*M_PI*r*(r + H) << endl;
	}
};

class Szescian : public Kwadrat
{
private:
	float a;
public:
	Szescian(float a): Kwadrat(a)
	{
		this->a = a;
	}
	virtual ~Szescian()
	{
		cout << "Destruktor Szescian" << endl;
	}
	virtual void pole()
	{
		cout << "Pole szescianu wynosi: " << 6 * a * a << endl;
	}
};


int main()
{
	Kolo kolo(3);
	Kwadrat kwadrat(5);
	Walec walec(11, 10);
	Szescian szescian(10);
	Obiekt* wsk;

	wsk = &kolo;
	wsk->pole();
	oblicz(wsk);
	cout << endl;

	wsk = &kwadrat;
	wsk->pole();
	oblicz(wsk);
	cout << endl;

	wsk = &walec;
	wsk->pole();
	oblicz(wsk);
	cout << endl;

	wsk = &szescian;
	wsk->pole();
	oblicz(wsk);
	cout << endl;
}
