#include <iostream>
#include "Auto.h"

using namespace std;

Auto::Auto() 
{
	marka = "";
	model = "";
	rok_produkcji = 0;
}

void Auto::wypisz_dane()
{
	cout << "Opis samochodu:" << endl << marka << ", " << model << endl << "Rok produkcji: " << rok_produkcji << endl;
}
