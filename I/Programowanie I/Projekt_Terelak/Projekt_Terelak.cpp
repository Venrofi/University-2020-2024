/* 
	Projekt - Radosław Terelak® 
	- kalkulator liczb rzymskich
	- generator haseł
	- kalkulator oszczędości
	- gra "Kółko i Krzyżyk"
*/

#include <iostream>
#include <string>
#include <map>
#include <random>
#include <Windows.h>
#include <fstream>
#include <WinBase.h>
#include <iomanip>
#include <algorithm>

using namespace std;

// Kopiowanie do schowka
void do_schowka(const string& s)
{
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());
	if (!hg)
	{
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

//Kółko i krzyżyk
int czy_wygrana(char pola[])
{
	if (pola[1] == pola[2] && pola[2] == pola[3]) //gdy wynik to 1, mamy zwycięzcę 
	{
		return 1;
	}
	else if (pola[4] == pola[5] && pola[5] == pola[6])
	{
		return 1;
	}
	else if (pola[7] == pola[8] && pola[8] == pola[9])
	{
		return 1;
	}
	else if (pola[1] == pola[4] && pola[4] == pola[7])
	{
		return 1;
	}
	else if (pola[2] == pola[5] && pola[5] == pola[8])
	{
		return 1;
	}
	else if (pola[3] == pola[6] && pola[6] == pola[9])
	{
		return 1;
	}
	else if (pola[1] == pola[5] && pola[5] == pola[9])
	{
		return 1;
	}
	else if (pola[3] == pola[5] && pola[5] == pola[7])
	{
		return 1;
	}
	else if (pola[1] != '1' && pola[2] != '2' && pola[3] != '3' && pola[4] != '4' && pola[5] != '5' && pola[6] != '6' && pola[7] != '7' && pola[8] != '8' && pola[9] != '9')
	{
		return 0; //remis
	}
	else
	{
		return -1; //brak zwycięzcy 
	}
}

void rysuj_tablice(char pola[], string tryb, int wynik[], char rewanz)
{
	system("cls");
	cout << "Kolko i krzyzyk" << endl << endl;
	if (tryb == "1") //Tryb pojedynczego gracza
	{
		cout << "Gracz" << " - " << "Bot Marek" << endl;
		cout << setw(4) << "<X>" << setw(9) << "<O>" << endl;
		if (rewanz == 'T' || rewanz == 't')
		{
			cout << setw(5) << wynik[0] << " : " << wynik[1] << endl;
		}
	}
	else //Gra dwuosobowa
	{
		cout << "Gracz 1" << " - " << "Gracz 2" << endl;
		cout <<setw(5) <<"<X>" <<setw(10) << "<O>" << endl;
		if (rewanz == 'T' || rewanz == 't')
		{
			cout << setw(7) << wynik[0] << " : " << wynik[1] << endl;
		}
	}
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << pola[1] << "  |  " << pola[2] << "  |  " << pola[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << pola[4] << "  |  " << pola[5] << "  |  " << pola[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << pola[7] << "  |  " << pola[8] << "  |  " << pola[9] << endl;

	cout << "     |     |     " << endl << endl;
}
void kolko_krzyzyk_start()
{
	system("cls");
	string wybor_input;

	cout << "Witaj w grze Kolko i Krzyzyk!" << endl;
	cout << "1. Tryb pojedynczego gracza." << endl << "2. Tryb dla dwoch graczy.";;
	do
	{
		cout <<endl<< "Aby wybrac wprowadz 1-2 i zatwierdz enterem: ";
		getline(cin, wybor_input);
	} while (wybor_input != "1" && wybor_input != "2");
	

	if (wybor_input == "1") //gra jednosobowa
	{
		char rewanz{}; //czy chcemy zagrać kolejny raz
		int wynik[2]{}; //tabela wyników wszystkich rozegranych starć

		do
		{
			char pola[10] = { 'x','1','2','3','4','5','6','7','8','9' }; //pierwszy element nie jest używany dla łatwiejszej numeracji od 1 zmiast od 0
			int gracz = 0; // numer gracza, po wejściu do pętli zmienia się na 1
			int wybor_pola; //wybór pola, które ma zostać zaznaczone
			char znak; //znak jakim posługuje się gracz/bot
			int rezultat; //wynik pojedynku
			int wybory[30]{}; //wybory są zapisywane aby wyeliminować prawdopodobieństwo popełnienia błędu przez bota
			int i = 0; //indeks pozycji do zapisu wyborów gracza

			random_device device;
			mt19937 generator(device()); //generowanie liczb losowych
			uniform_int_distribution<int> losuj_pole(1,9);
			do
			{
				gracz++;
				rysuj_tablice(pola, wybor_input, wynik, rewanz);
				if (gracz % 2 == 1) //wybór gracza który ma obecnie wybierać pole
				{
					gracz = 1;
				}
				else
				{
					gracz = 2;
				}

				if (gracz == 1)
				{
					cout << "Gracz podaje cyfre: ";
					while (!(cin >> wybor_pola) || (wybor_pola > 9) || (wybor_pola < 1)) //podawanie cyfry z zakresu 1-9
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "Podaj poprawna wartosc! : ";
					}
					znak = 'X';

					if (i < 30)
					{
						wybory[i] = wybor_pola; //przechowuje wybory gracza
						i++;
					}
				}
				else
				{
					wybor_pola = losuj_pole(generator);

					while (std::any_of(std::begin(wybory), std::end(wybory), [=](int n) {return n == wybor_pola; })) //sprawdza czy w tablicy jest już wylosowana liczba, jeśli tak - losuje nową
					{
						wybor_pola = losuj_pole(generator);
					}
					if (i < 30)
					{
						wybory[i] = wybor_pola; //przechowuje wybory bota
						i++;
					}

					cout << "Bot Marek podaje cyfre: " << wybor_pola << endl;
					cin.ignore();
					cin.get();
					znak = 'O';
				}

				if (wybor_pola == 1 && pola[1] == '1') //jeśli pole jest dostępne to zostaje przypisane graczowi/botowi
				{
					pola[1] = znak;
				}
				else if (wybor_pola == 2 && pola[2] == '2')
				{
					pola[2] = znak;
				}
				else if (wybor_pola == 3 && pola[3] == '3')
				{
					pola[3] = znak;
				}
				else if (wybor_pola == 4 && pola[4] == '4')
				{
					pola[4] = znak;
				}
				else if (wybor_pola == 5 && pola[5] == '5')
				{
					pola[5] = znak;
				}
				else if (wybor_pola == 6 && pola[6] == '6')
				{
					pola[6] = znak;
				}
				else if (wybor_pola == 7 && pola[7] == '7')
				{
					pola[7] = znak;
				}
				else if (wybor_pola == 8 && pola[8] == '8')
				{
					pola[8] = znak;
				}
				else if (wybor_pola == 9 && pola[9] == '9')
				{
					pola[9] = znak;
				}
				else //jeśli pole wybrane przez gracza/bota zostało już wcześniej przypisane ruch jest nieprawidłowy
				{
					if (gracz == 1)
					{
						cin.ignore();
						cout << "Niedozwolony ruch!" << endl;
						cin.get();
					}
					else
					{
						cout << "Niedozwolony ruch!" << endl;
						cin.get();
					}
				}
				rezultat = czy_wygrana(pola);

			} while (rezultat == -1); //dopóki nie ma wygranej, bądź remisu

			if (rezultat == 1) //wygrana
			{
				if (gracz % 2 == 1)
				{
					wynik[gracz - 1]++;
					rysuj_tablice(pola, wybor_input, wynik, rewanz);
					cout << endl << "Wygral Gracz!" << endl;
				}
				else
				{
					wynik[gracz - 1]++;
					rysuj_tablice(pola, wybor_input, wynik, rewanz);
					cout << endl << "Wygral Bot Marek!" << endl;
				}
			}
			else //remis
			{
				wynik[0]++;
				wynik[1]++;
				rysuj_tablice(pola, wybor_input, wynik, rewanz);
				cout << endl << "REMIS!" << endl;
			}

			cout << "Rewanz? (T/N): ";
			cin >> rewanz;

		} while (rewanz == 'T' || rewanz == 't');
	}
	else //gra dwuosobowa
	{
		char rewanz{}; //czy chcemy zagrać kolejny raz
		int wynik[2]{}; //tabela wyników wszystkich rozegranych starć

		do
		{
			char pola[10] = { 'x','1','2','3','4','5','6','7','8','9' }; //pierwszy element nie jest używany dla łatwiejszej numeracji od 1 zmiast od 0
			int gracz = 0; // numer gracza, po wejściu do pętli zmienia się na 1
			int wybor_pola; //wybór pola przez gracza, które ma zostać zaznaczone
			char znak; //znak jakim posługuje się gracz
			int rezultat; //wynik pojedynku

			do
			{
				gracz++;
				rysuj_tablice(pola, wybor_input, wynik, rewanz);
				if (gracz % 2 == 1) //wybór gracza który ma obecnie wybierać pole
				{
					gracz = 1;
				}
				else
				{
					gracz = 2;
				}

				cout << "Gracz " << gracz << " podaje cyfre: ";
				while (!(cin >> wybor_pola) || (wybor_pola > 9) || (wybor_pola < 1)) //podawanie cyfry z zakresu 1-9
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Podaj poprawna wartosc! : ";
				}

				if (gracz == 1) //wybór odpowiedniego znaku
				{
					znak = 'X';
				}
				else
				{
					znak = 'O';
				}

				if (wybor_pola == 1 && pola[1] == '1') //jeśli pole jest dostępne to zostaje przypisane graczowi
				{
					pola[1] = znak;
				}
				else if (wybor_pola == 2 && pola[2] == '2')
				{
					pola[2] = znak;
				}
				else if (wybor_pola == 3 && pola[3] == '3')
				{
					pola[3] = znak;
				}
				else if (wybor_pola == 4 && pola[4] == '4')
				{
					pola[4] = znak;
				}
				else if (wybor_pola == 5 && pola[5] == '5')
				{
					pola[5] = znak;
				}
				else if (wybor_pola == 6 && pola[6] == '6')
				{
					pola[6] = znak;
				}
				else if (wybor_pola == 7 && pola[7] == '7')
				{
					pola[7] = znak;
				}
				else if (wybor_pola == 8 && pola[8] == '8')
				{
					pola[8] = znak;
				}
				else if (wybor_pola == 9 && pola[9] == '9')
				{
					pola[9] = znak;
				}
				else //jeśli pole wybrane przez gracza zostało już wcześniej przypisane ruch jest nieprawidłowy
				{
					cin.ignore();
					cout << "Niedozwolony ruch!" << endl;
					cin.get();
				}
				rezultat = czy_wygrana(pola);

			} while (rezultat == -1); //dopóki nie ma wygranej, bądź remisu

			if (rezultat == 1)
			{
				wynik[gracz - 1]++;
				rysuj_tablice(pola, wybor_input, wynik, rewanz);
				cout << endl << "Wygral Gracz " << gracz << "!" << endl;
			}
			else
			{
				wynik[0]++;
				wynik[1]++;
				rysuj_tablice(pola, wybor_input, wynik, rewanz);
				cout << endl << "REMIS!" << endl;
			}

			cout << "Rewanz? (T/N): ";
			cin >> rewanz;

		} while (rewanz == 'T' || rewanz == 't');
	}
}

// Kalkulator oszczędności
void kalkulator_oszczednosci()
{
	system("cls");
	// Obecna data i godzina
	SYSTEMTIME st;
	GetSystemTime(&st);

	long double kapital, cel;
	double oprocentowanie;
	int rok = st.wYear; //obecny rok

	cout << "Podaj Twoj kapital poczatkowy (PLN): ";
	while (!(cin >> kapital) || (kapital < 1) || (kapital > 1000000000))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Podaj realna wartosc: ";
	}
	cout << endl << "Podaj jaka kwote chcesz zgromadzic (PLN): ";
	while (!(cin >> cel) || (cel <= kapital) || (cel > 100000000000))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Podaj realna wartosc: ";
	}
	cout << endl << "Podaj oprocentowanie (%): ";
	while (!(cin >> oprocentowanie) || (oprocentowanie < 0) || (oprocentowanie > 50))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Podaj realna wartosc: ";
	}

	int ile_lat = 0;
	ofstream wyniki("Symulacja_Oszczednosci.txt"); //otwarcie pliku
	wyniki << "Kapitał początkowy: " << kapital <<" PLN"<< endl << "Cel: " << cel <<" PLN"<< endl << "Oprocentowanie: " << oprocentowanie << " %" << endl<<endl;
	cout << endl;
	while (kapital < cel)
	{
		kapital = (kapital * oprocentowanie) / 100 + kapital;
		ile_lat++;

		cout <<fixed<< rok + ile_lat << ": "<<setprecision(2)<< kapital << " PLN" << endl;
		wyniki << fixed << rok + ile_lat << ": " << setprecision(2) << kapital << " PLN" << endl;
	}
	cout << endl << "Cel zostanie osiagniety w " << rok + ile_lat << " roku." << endl;
	wyniki << endl << "Cel zostanie osiagnięty w " << rok + ile_lat << " roku." << endl;
	wyniki.close();

	ifstream sprawdzam("Symulacja_Oszczednosci.txt");
	if (sprawdzam.is_open())
	{
		cout << endl << "Dane zostaly poprawnie umieszczone w pliku :)" << endl;
		sprawdzam.close();
	}
	else
	{
		cout << endl << "Wystapil blad zapisu do pliku :(" << endl;
	}
	cout << endl << "Nacisnij Enter aby kontynuowac..";
	cin.ignore();
	cin.ignore();
}
//Generator haseł
string generator_hasel(int parametr)
{
	int dlugosc; // długość hasła
	string haslo{}; // wygenerowane hasło
	random_device device;
	mt19937 generator(device()); //generowanie liczb losowych

	switch (parametr)
	{
	case 1: // tylko litery
	{
		string litery = "ABCDEFGHIJKLMNOPQRSTUWVWXYZabcdefghijklmnopqrstuvwxyz";
		cout << "Podaj dlugosc hasla (5-30): ";
		while (!(cin >> dlugosc) || (dlugosc < 5) || (dlugosc > 30))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Podaj dlugosc hasla (5-30): ";
		}

		uniform_int_distribution<int> losuj_litere(0, litery.length());

		for (int i = 0; i < dlugosc; i++)
		{
			haslo += litery[losuj_litere(generator)];
		}

		do_schowka(haslo); //kopiowanie hasła do schowka użytkownika

		return haslo;
		break;
	}
	case 2: // litery, cyfry
	{
		string litery = "ABCDEFGHIJKLMNOPQRSTUWVWXYZabcdefghijklmnopqrstuvwxyz";
		string cyfry = "0123456789";

		cout << "Podaj dlugosc hasla (5-30): ";
		while (!(cin >> dlugosc) || (dlugosc < 5) || (dlugosc > 30))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Podaj dlugosc hasla (5-30): ";
		}

		uniform_int_distribution<int> losuj_litere(0, litery.length());
		uniform_int_distribution<int> losuj_cyfre(0, cyfry.length());
		uniform_int_distribution<int> ile_cyfr(1, dlugosc / 2);
		uniform_int_distribution<int> pozycja(0, dlugosc);

		for (int i = 0; i < dlugosc; i++) //wypełniam literami
		{
			haslo += litery[losuj_litere(generator)];
		}
		for (int i = 0; i < ile_cyfr(generator); i++) // losuje indeksy ciągu znaków i podmieniam ich wartości losową cyfrą
		{
			haslo[pozycja(generator)] = cyfry[losuj_cyfre(generator)];
		}

		do_schowka(haslo); //kopiowanie hasła do schowka użytkownika

		return haslo;
		break;
	}
	case 3: // litery, cyfry, znaki specjalne
	{
		string litery = "ABCDEFGHIJKLMNOPQRSTUWVWXYZabcdefghijklmnopqrstuvwxyz";
		string cyfry = "0123456789";
		string znaki_specjalne = "!@#$%^&*()_+";

		cout << "Podaj dlugosc hasla (5-30): ";
		while (!(cin >> dlugosc) || (dlugosc < 5) || (dlugosc > 30))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Podaj dlugosc hasla (5-30): ";
		}

		uniform_int_distribution<int> losuj_litere(0, litery.length());
		uniform_int_distribution<int> losuj_cyfre(0, cyfry.length());
		uniform_int_distribution<int> losuj_znak(0, znaki_specjalne.length());

		uniform_int_distribution<int> ile_cyfr(1, dlugosc / 2);
		uniform_int_distribution<int> ile_znakow(1, dlugosc / 2);

		uniform_int_distribution<int> pozycja(0, dlugosc);

		for (int i = 0; i < dlugosc; i++) //wypełniam literami
		{
			haslo += litery[losuj_litere(generator)];
		}
		for (int i = 0; i < ile_cyfr(generator); i++) // losuje indeksy ciągu znaków i podmieniam ich wartości losową cyfrą
		{
			haslo[pozycja(generator)] = cyfry[losuj_cyfre(generator)];
		}
		for (int i = 0; i < ile_znakow(generator); i++) // losuje indeksy ciągu znaków i podmieniam ich wartości losowym znakiem specjalnym
		{
			haslo[pozycja(generator)] = znaki_specjalne[losuj_znak(generator)];
		}

		do_schowka(haslo); //kopiowanie hasła do schowka użytkownika

		return haslo;
		break;
	}
	default:
		cout << ":((" << endl;
		break;
	}

}
void generator_hasel_start()
{
	int wybor{}; // wybór parametru
	string kontynuacja; // czy generować kolejne hasła
	system("cls");

	cout << "Z czego ma sie skladac Twoje haslo?" << endl;
	cout << "1. Tylko litery" << endl;
	cout << "2. Litery i cyfry" << endl;
	cout << "3. Litery, cyfry i znaki specjalne" << endl;
	cout << "Wybierz 1-3 i zatwierdz: ";

	while (!(cin >> wybor) || (wybor < 1) || (wybor > 3))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Prosze podac cyfre z zakresu 1-3: ";
	}

	switch (wybor)
	{
	case 1:
		cout << endl << "Oto wygenerowane haslo: " <<generator_hasel(wybor)<<endl;
		break;
	case 2:
		cout << endl << "Oto wygenerowane haslo: " << generator_hasel(wybor) << endl;
		break;
	case 3:
		cout << endl << "Oto wygenerowane haslo: " << generator_hasel(wybor) << endl;
		break;
	default:
		cout << ":((" << endl;
		break;
	}
	cout << endl << "Haslo zostalo skopiowane do schowka!" << endl;
	cin.ignore();
	cout << endl << "Czy chcesz wygenerowac kolejne haslo? (T/N)";
	getline(cin, kontynuacja);
	if (kontynuacja[0] == 'T' || kontynuacja[0] == 't')
	{
		generator_hasel_start();
	}
}

// Kalkulator liczb rzymskich
int rzym_na_dec(string liczba_rzym) 
{
	map<char, int> tablica_wartosci;
	int dlugosc = liczba_rzym.length();

	tablica_wartosci['I'] = 1;
	tablica_wartosci['V'] = 5;
	tablica_wartosci['X'] = 10;
	tablica_wartosci['L'] = 50;
	tablica_wartosci['C'] = 100;
	tablica_wartosci['D'] = 500;
	tablica_wartosci['M'] = 1000;

	int wynik = 0;
	int obecna{};
	int poprzednia{};

	while (dlugosc--)
	{
		obecna = tablica_wartosci[liczba_rzym[dlugosc]];
		if (obecna >= poprzednia)
		{
			poprzednia = obecna;
			wynik += obecna;
		}
		else
		{
			poprzednia = obecna;
			wynik -= obecna;
		}
	}

	return wynik;
}

string dec_na_rzym(int liczba_dec)
{
	map<int, string> tablica_wartosci;

	tablica_wartosci[0] = 'M';
	tablica_wartosci[1] = 'D';
	tablica_wartosci[2] = 'C';
	tablica_wartosci[3] = 'L';
	tablica_wartosci[4] = 'X';
	tablica_wartosci[5] = 'V';
	tablica_wartosci[6] = 'I';

	int liczby[7] = { 1000, 500, 100, 50, 10, 5, 1 };
	string wynik{};
	int i = 0;

	if ((liczba_dec > 3999) || (liczba_dec <= 0)) // zakres 1-3999 
	{
		return wynik;
	}
	
	while (liczba_dec > 0 && i < 7) // jest 7 znaków rzymskich
	{
		if (liczba_dec >= liczby[i]) // jeśli liczba jest większa/równa od jednej z wartości znaku rzymskiego
		{
			liczba_dec -= liczby[i];
			wynik.append(tablica_wartosci[i]);
		}
		else if ((i % 2 == 0) && (i < 5) && (liczba_dec >= liczby[i] - liczby[i + 2]) ) // warunek na 9xx/9x/9; znak większy od "V" i tylko parzysty, liczba jest z przedziału np. 90-100, 
		{
			liczba_dec -= (liczby[i] - liczby[i + 2]);
			wynik.append(tablica_wartosci[i + 2]);
			wynik.append(tablica_wartosci[i]);
			i++;
		}
		else if ((i % 2 == 1) && (i < 6) && (liczba_dec >= liczby[i] - liczby[i + 1]) )// warunek na 4xx/4x/4; znak większy od "I" i tylko nieparzysty, liczba z przedziału np. 40-50
		{
			liczba_dec -= (liczby[i] - liczby[i + 1]);
			wynik.append(tablica_wartosci[i + 1]);
			wynik.append(tablica_wartosci[i]);
			i++;
		}
		else //jeśli nie ma żadnej liczby z danych przedziałów przejdź dalej
		{
			i++;
		}
	}

	return wynik;
}

int kalkulator_oblicz(string liczba_1, string liczba_2, char znak)
{
	int liczba_1_dec = rzym_na_dec(liczba_1);
	int liczba_2_dec = rzym_na_dec(liczba_2);

	//cout <<endl <<liczba_1_dec << ", " << liczba_2_dec << endl;

	switch (znak)
	{
	case '+':
		return liczba_1_dec + liczba_2_dec;
	case '-':
		return liczba_1_dec - liczba_2_dec;
	case '*':
		return liczba_1_dec * liczba_2_dec;
	case '/':
		return liczba_1_dec / liczba_2_dec;
	default:
		return 0;
	}
}

void kalkulator_start()
{
	string liczba_1, liczba_2; //liczby podawane przez użytkownika
	string znak_input{};
	char znak; //właściwy znak operacji podany przez użytkownika
	string wynik_zamiana; //czy zamienić na postać dziesiętną
	int wynik; //wynik operacji
	int licznik_operacji = 0; //licznik ilości operacji do numeracji historii
	string kontunuacja; //czy prowadzić kolejne obliczenia
	string wyswietl_historie; 
	string historia_rzym = "HISTORIA: \n";

	do
	{
		system("cls");
		licznik_operacji++;

		cout << "Podaj pierwsza liczbe (zapis rzymski): ";
		do
		{
			cin >> liczba_1;
			if (liczba_1 != dec_na_rzym(rzym_na_dec(liczba_1)))
			{
				cout << "Podana liczba nie istnieje w alfabecie rzymskim! Podaj poprawna: ";
			}
		} while (liczba_1 != dec_na_rzym(rzym_na_dec(liczba_1))); // sprawdzam czy zapis liczby jest poprawny poprzez konwersję na dziesiętną i ponownie na rzymską

		cout << "Podaj druga liczbe (zapis rzymski): ";
		do
		{
			cin >> liczba_2;
			if (liczba_2 != dec_na_rzym(rzym_na_dec(liczba_2)))
			{
				cout << "Podana liczba nie istnieje w alfabecie rzymskim! Podaj poprawna: ";
			}
		} while (liczba_2 != dec_na_rzym(rzym_na_dec(liczba_2))); // sprawdzam czy zapis liczby jest poprawny poprzez konwersję na dziesiętną i ponownie na rzymską
		
		cin.ignore();
		do
		{
			cout << "Podaj znak operacji (+, -, *, /): ";
			getline(cin, znak_input);
		} while (znak_input != "+" && znak_input != "-" && znak_input != "*" && znak_input != "/");
		
		znak = znak_input[0];

		wynik = kalkulator_oblicz(liczba_1, liczba_2, znak);

		if (wynik < 4000 && wynik > 0) //jeśli wynik operacji jest spoza zakresu 1-3999 nie wypisze postaci rzymskiej
		{
			cout << endl << "Wynik operacji to: " << dec_na_rzym(wynik);
			cout << endl << "Zamienic na postac dziesietna? (T/N)";
			getline(cin, wynik_zamiana);
			if (wynik_zamiana == "T" || wynik_zamiana == "t")
			{
				cout << "Wynik w postaci dziesietnej: " << wynik;
			}
			historia_rzym += to_string(licznik_operacji)+". "+liczba_1+" "+znak+" "+liczba_2+" = "+dec_na_rzym(wynik)+"\n";
		}
		else
		{
			cout << endl << "Wynik operacji nie moze byc zapisany w postaci rzymskiej.." << endl << "Oto wynik w postaci dziesietnej: " << wynik;
			historia_rzym += to_string(licznik_operacji) + ". " + liczba_1 + " " + znak + " " + liczba_2 + " = "+ to_string(wynik) + "\n";
		}
		cout << endl << "Czy chcesz wykonac kolejne dzialanie? (T/N)";
		cin >> kontunuacja;
	} while (kontunuacja == "T" || kontunuacja == "t");
	cin.ignore();
	cout << "Czy chcesz wyswietlic historie Twoich operacji? (T/N)";
	getline(cin, wyswietl_historie);
	if (wyswietl_historie == "T" || wyswietl_historie == "t")
	{
		cout << endl << historia_rzym << endl;
	}
	cout <<endl<< "Nacisnij enter aby kontunuowac..";
	cin.ignore();

}

//Start
void start()
{
	int wybor;
	cout << "Z czego chcialbys skorzystac?" << endl<<endl;
	cout << "1. Kalkulator liczb rzymskich" << endl << "2. Generator hasel" << endl << "3. Kalkulator oszczednosci" << endl << "4. Kolko i krzyzyk"<<endl<<"5. Zamknij program";
	cout << endl << endl;

	cout << "Aby wybrac wprowadz liczbe 1-5 i zatwierdz enterem: ";
	while (!(cin >> wybor) || (wybor < 1) || (wybor > 5))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout <<endl<< "Aby wybrac wprowadz liczbe 1-5 i zatwierdz enterem: ";
	}
	switch(wybor)
	{
	case 1: //kalkulator liczb rzymskich
		kalkulator_start();
		system("cls");
		start();
		break;
	case 2: //generator haseł
		generator_hasel_start();
		system("cls");
		start();
		break;
	case 3: //kalkulator oszczędności
		kalkulator_oszczednosci();
		system("cls");
		start();
		break;
	case 4: //kółko i krzyżyk 
		cin.ignore();
		kolko_krzyzyk_start();
		system("cls");
		start();
		break;
	case 5: //wyjście
		system("cls");
		cout << "Adios!" << endl;
		break;
	default:
		cout << ":((" << endl;
		break;
	}
}

int main()
{
	start();

	return 0;
}