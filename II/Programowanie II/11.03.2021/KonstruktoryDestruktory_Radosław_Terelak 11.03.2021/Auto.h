#pragma once

#include <iostream>

using namespace std;

class Auto
{
private:
	string marka, model;
	int rok_produkcji;

public:
	Auto();
	void wypisz_dane();
};