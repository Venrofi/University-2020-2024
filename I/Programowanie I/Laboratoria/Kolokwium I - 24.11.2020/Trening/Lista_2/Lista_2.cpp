#include <iostream>

using namespace std;

void zad_1(char* imie)
{
	int licznik = 0;
	for (int i = 0; i < strlen(imie); i++)
	{
		if (*(imie + i) == 'a' || *(imie + i) == 'A')
		{
			licznik++;
		}
	}

	cout << "Liczba wystapien A/a: " << licznik;
}

void zad_2(char* imie)
{
	for (int i = strlen(imie); i >= 0; i--)
	{
		cout << *(imie + i);
	}
}

void zad_8()
{
	char alfabet[] = { 'a', 'b', 'c' };
	int licz = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int z = 0; z < 3; z++)
			{
				for (int x = 0; x < 3; x++)
				{
					cout << alfabet[i] << alfabet[j] << alfabet[z] << alfabet[x] <<endl;
					licz++;
				}
			}
		}
	}
	cout << licz;
}

void zad_10()
{
	char ciag[] = "ALA ma KOTA HEHEHEH";
	int i = 0;
	int ilosc[128] = {};

	while (ciag[i])
	{
		++ilosc[ciag[i]];
		++i;
	}

	for (int j = 0; j < 128; j++)
	{
		if (ilosc[j] > 1 && (char)j != ' ')
		{
			cout << (char)j << ": " << ilosc[j] << endl;
		}
	}
}

int zad_12()
{
	char liczba_1[200]{};
	char liczba_2[200]{};

	cin >> liczba_1 >> liczba_2;

	return atoi(liczba_1) + atoi(liczba_2);
}

void zad_13()
{
	int ciag[] = { 4,4,4,1,1,3,2,3,1,1 }; // 1 - góra, 2 - dół, 3 - lewo, 4 - prawo

	char plansza[50][50]{};

	char test = 223;
	int losowa_x = 25;
	int losowa_y = 20;

	plansza[losowa_x][losowa_y] = 223;

	int i = 0;
	bool czy_da_sie = true;

	while (i < (sizeof(ciag)/sizeof(ciag[0])) - 1)
	{
		cout << ciag[i] << endl;
		switch (ciag[i])
		{
			case 1:
				if (plansza[losowa_x][losowa_y + 1] != 223)
				{
					++losowa_y;
					plansza[losowa_x][losowa_y] = 223;
				}
				else
				{
					czy_da_sie = false;
				}
				break;
			case 2:
				if (plansza[losowa_x][losowa_y - 1] != 223)
				{
					--losowa_y;
					plansza[losowa_x][losowa_y] = 223;
				}
				else
				{
					czy_da_sie = false;
				}
				break;
			case 3:
				if (plansza[losowa_x - 1][losowa_y] != 223)
				{
					--losowa_x;
					plansza[losowa_x][losowa_y] = 223;
				}
				else
				{
					czy_da_sie = false;
				}
				break;
			case 4:
				if (plansza[losowa_x + 1][losowa_y] != 223)
				{
					++losowa_x;
					plansza[losowa_x][losowa_y] = 223;
					cout << endl << "X/Y/number: " << losowa_x << ", " << losowa_y << ", " << plansza[losowa_x][losowa_y]<<endl;
				}
				else
				{
					czy_da_sie = false;
				}
				break;
			default:
				cout << "Cos sie popsulo :(" << endl;
				break;
		}
		i++;
	}

	if (czy_da_sie == true)
	{
		for (int x = 0; x < 50; x++)
		{
			for (int y = 0; y < 50; y++)
			{
				//cout << endl << "X/Y: " << x << ", " << y << endl;
				//cout << (int)plansza[x][y];
				if (plansza[x][y] != -33)
				{
					//plansza[x][y] = 32;
					//cout << " ";
				}
				cout << plansza[x][y];
			}
			//cout << endl; :((((((((((((((((((((((
		}
	}

}

void zad_14(char* s, char* t)
{
	int j = 0;
	cout << endl << strlen(t)<<endl;
	for (int i = strlen(t) - 1 ; i >= 0; i--)
	{
		*(s + j) = *(t + i);
		cout << *(s + j);
		j++;
	}
	cout << endl;
}

void zad_kolos_3(int liczba, int podstawa)
{
	int licznik = 0;

	while (liczba != 0)
	{
		cout << liczba % podstawa;
		liczba = liczba / podstawa;
		licznik++;
	}

	cout << endl << "Ilosc potrzebnego miejsca: " << licznik;
}

void zad_15(char *s, char *t)
{
	bool czy_jest = false;

	for (int i = 0; i < strlen(t) - 1; i++)
	{
		//cout << i << endl;
		//cout << strlen(t) << endl;
		if (*(t + i) > 64 && *(t + i) < 91)
		{
			*(t + i) += 32;
			//cout << endl << *(t + i);
		}
		for (int j = 0; j < 10; j++)
		{
			//cout << *(t + i) << ", " << *(s + j) << endl;
			if (*(t + i) == *(s + j))
			{
				//cout << "XD" << endl;
				czy_jest = true;
			}
		}
		if (czy_jest == false)
		{
			if (*(t + i) != ' ')
			{
				*(s + i) = *(t + i);
				cout << *(s + i);
			}
		}
		czy_jest = false;
	}
}

void zad_16(char* s, char* t)
{
	if (strlen(s) != strlen(t))
	{
		cout << "To se ne da :(" << endl;
	}
	else
	{
		char hilfe{};
		bool to_se = true;
		for (int i = 0; i < strlen(s); i++)
		{
			for (int j = 0; j < strlen(s); j++)
			{
				if (*(s + j) == *(t + i))
				{
					hilfe = *(s + i);
					*(s + i) = *(s + j);
					*(s + j) = hilfe;
				}
			}
			//cout << *(s + i);
		}

		for (int i = 0; i < strlen(s); i++)
		{
			if (*(s + i) != *(t + i))
			{
				to_se = false;
			}
		}

		cout << s << " : " << t << endl;
		if (to_se == true)
		{
			cout << "To se da :)) !" << endl;
		}
		else
		{
			cout << "To se ne da :(" << endl;
		}
	}
}

void zad_17(int liczba = 3)
{
	int * tablica = new int[liczba];

	for (int i = 0; i < liczba; i++)
	{
		tablica[i] = i+1;
		cout << tablica[i];
	}
	cout << endl;
	for (int i = 0; i < liczba; i++)
	{
		for (int j = 0; j < liczba; j++)
		{
			for (int z = 0; z < liczba; z++)
			{
				cout << tablica[z] << ", " << tablica[j] << ", " << tablica[i] << endl;
			}

		}
	}


	delete[] tablica;
}

int main()
{
	char imie[] = "Radek";
	char imie_2[6] = {};
	char znaki[] = "81kot";
	char t[] = "Ala ma kota";
	char s[10]{};
	char sl_1[] = "sekret";
	char sl_2[] = "kretes";

	char* wsk = s;
	cout<< sizeof(wsk);
	//zad_1(imie);
	//zad_2(imie);
	//zad_8();
	//zad_10();
	//cout<< zad_12();
	//zad_13();
	//zad_14(imie_2, imie);
	//zad_kolos_3(125, 3);
	//zad_15(s, t);
	//zad_16(sl_1, sl_2);
	//zad_17();


	return 0;
}