#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

void zad_9()
{
    string nazwa_pliku;
    cout << "Podaj nazwe pliku: ";
    cin >> nazwa_pliku;

    ifstream plik(nazwa_pliku); //otwieram rządany plik
    if (plik.is_open())
    {
        vector<string> slowa; //tworzę vector na wszystkie wyrazy
        char znak; //pojedyncze znaki
        string slowo; //pojedyncze wyrazy

        locale loc; //potrzebne do przekształcenia wyrazów na małe litery

        while (plik.get(znak))
        {
            if (znak == ' ' || znak == '\n') //jeśli spacja bądź enter
            {
                //cout << "DL: " << slowo.length() << endl;
                for (int i = slowo.length(); i > 0; i--) //szukam w słowie znaków przestankowych zaczynając od końca
                {
                    if (slowo[i] == '!' || slowo[i] == '?' || slowo[i] == '.' || slowo[i] == ',' || slowo[i] == ':' || slowo[i] == '-')
                    {
                        slowo.pop_back(); //jeśli znajdę to usuwam
                    }
                }

                for (int i = 0; i < slowo.length(); i++) //zamieniam słowo bez znaków przestankowych na takie tylko z małych liter
                {
                    slowo[i] = tolower(slowo[i], loc);
                }
                slowa.push_back(slowo); //dodaje gotowe słowo do vectora słów
                slowo = ""; //"zeruje" słowo
                znak = '\0'; //"zeruje" znak
            }
            else
            {
                slowo += znak; //jeśli kolejnym znakiem nie była spacja bądź enter to dodaje dany znak do słowa
            }
        }
        vector<string> slowa_unikaty; //tworzę kolejny vector na unikatowe słowa

        sort(slowa.begin(), slowa.end()); //sortuje słowa
        slowa_unikaty = slowa; //przypisuje posortowane słowa do nowego wektora z unikatami

        vector<int> liczba_duplikatow(slowa_unikaty.size()); //tworzę vector int'ów na zliczanie duplikatów o wielkości równej ilości słów

        slowa_unikaty.erase( unique( slowa_unikaty.begin(), slowa_unikaty.end() ), slowa_unikaty.end() ); //usuwam duplikaty

        //cout << endl << "SL_U: " << slowa_unikaty.size() << ", SL: " << slowa.size() << ", LD: " << liczba_duplikatow.size()<<endl;
        
        cout << endl << "Slowa wystepujace w pliku oraz liczba ich wystapien: " << endl;
        for (int i = 0; i < slowa_unikaty.size(); i++) //dla każdego słowa, które nie jest duplikatem sprawdzam czy w pierwotnym vectorze jest jakiś duplikat
        {
            for (int j = 0; j < slowa.size(); j++)
            {
                if (slowa_unikaty[i] == slowa[j]) //jeśli jest to liczba duplikatów się zwiększa
                {
                    liczba_duplikatow[i]++;
                }

            }
            cout << slowa_unikaty[i]<<" : "<<liczba_duplikatow[i] << endl; //wypisuje unikatowe słowa oraz liczbę ich wystąpień w pliku
        }
    }
    else
    {
        cout << endl << "Nieudane otwarcie pliku o nazwie < " << nazwa_pliku <<" >" << endl; //jeśli podamy złą nazwę to proces się nie wykona

    }
}
void zad_8(string nazwa_pliku, string slowo_a, string slowo_b)
{
    //wczytywanie słowo po słowie; jeśli wystąpi słowo "a" to zastąp je słowem "b".
    ifstream plik(nazwa_pliku);
    string tekst;
    char znak;

    if (plik.is_open())
    {
        while (plik.get(znak))
        {
            tekst += znak;
        }

        cout << tekst << endl;

        while (tekst.find(slowo_a) != string::npos)
        {
            tekst.replace(tekst.find(slowo_a), slowo_a.length(), slowo_b);
        }
        plik.close();

        cout << endl << tekst;

        ofstream zapis(nazwa_pliku);
        zapis << tekst;
        zapis.close();
    }

}
void zad_6(string nazwa_pliku) //Zapisuje plik w odwrotnej kolejności znaków
{
    ifstream plik(nazwa_pliku);
    string tekst;
    char znak;

    if (plik.is_open())
    {
        while (plik.get(znak))
        {
            tekst += znak;
        }

        ofstream zapis("zad_6.txt");

        reverse(tekst.begin(), tekst.end());
        zapis << tekst;

        plik.close();
        zapis.close();
    }
}
void zad_5(string nazwa_pliku)
{
    ifstream plik(nazwa_pliku);
    ofstream zapis("wynik.txt");
    if (plik.is_open())
    {
        char znak_1;
        char znak_2;
        int ilosc_znakow{};
        while (plik >> znak_1)
        {
            ilosc_znakow++;
        }
        plik.clear();
        plik.seekg(0, ios::beg);

        plik >> znak_1;
        plik >> znak_2;

        for (int i = 0; i < ilosc_znakow; i++)
        {
            if (znak_1 == 10 && znak_2 == 13)
            {
                zapis << znak_2;
            }
            else
            {
                zapis << znak_1;
            }
            znak_1 = znak_2;
            plik >> znak_2;
        }
    }
    plik.close();
    zapis.close();
}
void zad_4(string nazwa_pliku) //program zliczający ilość wyrazów, cyfr, linii, liter i bajtów
{
    cout << "Statystyka pliku: " << nazwa_pliku << endl;
    ifstream plik(nazwa_pliku, ios::binary);
    plik.seekg(0, ios::end);
    int rozmiar_pliku = plik.tellg();
    plik.close();

    ifstream plik_2(nazwa_pliku, ios::in);
    int liczba_cyfr{};
    int liczba_liter{};
    int liczba_wyrazow{};
    int liczba_wierszy{};

    if (plik_2.is_open())
    {
        char znak;
        while (plik_2 >> znak)
        {
            if (znak >= 48 && znak <= 57)
            {
                liczba_cyfr++;
            }
            if (znak >= 65 && znak <= 90 || znak >= 97 && znak <= 122)
            {
                liczba_liter++;
            }
        }
        plik_2.clear();
        plik_2.seekg(0, ios::beg);

        char wyraz[100];
        while (plik_2 >> wyraz)
        {
            liczba_wyrazow++;
        }

        plik_2.clear();
        plik_2.seekg(0, ios::beg);

        char wiersz[10000];
        while (plik_2.getline(wiersz, 10000))
        {
            liczba_wierszy++;
        }
    }
    plik_2.close();

    cout << "Ilosc bajtow: " << rozmiar_pliku << endl;
    cout << "Liczba liter: " << liczba_liter << endl;
    cout << "Liczba cyfr: " << liczba_cyfr << endl;
    cout << "Liczba wyrazow: " << liczba_wyrazow << endl;
    cout << "Liczba wierszy: " << liczba_wierszy << endl;
}

bool zad_3_porownaj(string a, string b) //porównywanie dwóch słów potrzebne do sortowania alfabetycznego; Zwraca 1 gdy string b jest dalej w alfabecie
{
    return a < b;
}
void zad_3() // Program który pobiera słowa do "/ready" i sortuje je alfabetycznie. Są krótsze niż 20 znaków i jest ich mniej niż 100.
{
    vector<string>slowa;
    string slowo_input;
    int i = 0;
    do
    {
        getline(cin, slowo_input);
        if (slowo_input != "/ready" && slowo_input.size() < 20)
        {
            slowa.push_back(slowo_input);
            i++;
        }
    } while (slowo_input != "/ready" && i < 100);
    i = 0;

    cout << endl << "Przed sortowaniem: " << endl;
    while (i < slowa.size())
    {
        cout << slowa[i] << endl;
        i++;
    }
    i = 0;

    sort(slowa.begin(), slowa.end(), zad_3_porownaj);

    cout << endl << "Po sortowaniu: " << endl;
    while (i < slowa.size())
    {
        cout << slowa[i] << endl;
        i++;
    }
}
void zad_2(int n) //Napisz program, który po pobraniu z linii poleceń liczby naturalnej narysuje na ekranie spiralę o boku n.
{
    char** tablica = new char* [n];
    for (int i = 0; i < n; i++) tablica[i] = new char[n]; //tworzenie dynamicznej tablicy dwuwymiarowej

    int x_start = 0;
    int y_start = 0;
    int x_end = n;
    int y_end = n;

    while (x_start < x_end && y_start < y_end)
    {
        for (int i = y_start; i < y_end; i++)
        {
            tablica[x_start][i] = '*';
            //cout << tablica[x_start][i];
        }
        x_start++;

        for (int i = x_start; i < x_end; i++) 
        {
            tablica[i][y_end - 1] = '*';
        }
        y_end--;

        if (x_start < x_end)
        {
            for (int i = y_end - 1; i >= 1; i--)
            {
                tablica[x_end - 1][i] = '*';
            }
            x_end--;
        }

        if (y_end < y_start)
        {
            for (int i = x_end - 1; i >= x_start; i--)
            {
                tablica[i][y_start] = '*';
            }
            y_start++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tablica[j][i];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) delete[] tablica[i]; //usuwanie tablicy dwuwymiarowej
}
char zad_1() // Napisz program, który generuje losowy znak ze zbioru liter {a, b, c, . . . , z}.
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> losuj_litere(97, 122);
    char litera = losuj_litere(generator);

    return litera;
}
int main()
{
    //zad_4("Symulacja_Oszczednosci.txt");
    //zad_5("test.txt");
    //zad_6("test.txt");
    //zad_8("test.txt", "Siema", "Narra");
    zad_9();
}

