// Zad1_Statki.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;

void ustaw_statki(int plansza[10][10])
{
    random_device device; 
    mt19937 generator(device());

    uniform_int_distribution<int> losuj_xy(0,9);
    uniform_int_distribution<int> losuj_kierunek(1, 4);

    // 1 - lewo, 2 - prawo, 3 - góra, 4 - dół
    // statki: x1 4 -> x2 3 - > x3 2 -> x4 1
    
    int x = losuj_xy(generator);
    int y = losuj_xy(generator);
    int kierunek = losuj_kierunek(generator);
    bool set_4 = false;
    bool set_3 = false;
    
    cout << "USTAW STATKI" << endl;    
    
    /* Losowanie 4-masztowca */

    cout << endl << "IV" << endl;
    cout << "X: " << x << " Y: " << y << endl;

    while (set_4 == false)
    {
        cout << "Kierunek: " << kierunek;
        
        if (kierunek == 1 && plansza[y][x - 3] == 0 && x > 2) //lewo
        {
            plansza[y][x] = 4;
            plansza[y][x - 1] = 4;
            plansza[y][x - 2] = 4;
            plansza[y][x - 3] = 4;
            set_4 = true;

            if (x != 3)
            {
                plansza[y][x - 4] = -1;
                if (y != 0)
                {
                    plansza[y - 1][x - 4] = -1;
                }
                if (y != 9)
                {
                    plansza[y + 1][x - 4] = -1;
                }

            }
            if (x != 9)
            {
                plansza[y][x + 1] = -1;
                if (y != 0)
                {
                    plansza[y + 1][x + 1] = -1;
                }
                if (y != 9)
                {
                    plansza[y - 1][x + 1] = -1;
                }
            }
            if (y != 0)
            {
                plansza[y - 1][x] = -1;
                plansza[y - 1][x - 1] = -1;
                plansza[y - 1][x - 2] = -1;
                plansza[y - 1][x - 3] = -1;
            }
            if (y != 9)
            {
                plansza[y + 1][x] = -1;
                plansza[y + 1][x - 1] = -1;
                plansza[y + 1][x - 2] = -1;
                plansza[y + 1][x - 3] = -1;
            }

        }
        else if (kierunek == 2 && plansza[y][x + 3] == 0 && x < 7) //prawo
        {
            plansza[y][x] = 4;
            plansza[y][x + 1] = 4;
            plansza[y][x + 2] = 4;
            plansza[y][x + 3] = 4;
            set_4 = true;

            if (x != 6)
            {
                plansza[y][x + 4] = -1;
                if (y != 0)
                {
                    plansza[y - 1][x + 4] = -1;
                }
                if (y != 9)
                {
                    plansza[y + 1][x + 4] = -1;
                }

            }
            if (x != 0)
            {
                plansza[y][x - 1] = -1;
                if (y != 0)
                {
                    plansza[y + 1][x - 1] = -1;
                }
                if (y != 9)
                {
                    plansza[y - 1][x - 1] = -1;
                }
            }
            if (y != 0)
            {
                plansza[y - 1][x] = -1;
                plansza[y - 1][x + 1] = -1;
                plansza[y - 1][x + 2] = -1;
                plansza[y - 1][x + 3] = -1;
            }
            if (y != 9)
            {
                plansza[y + 1][x] = -1;
                plansza[y + 1][x + 1] = -1;
                plansza[y + 1][x + 2] = -1;
                plansza[y + 1][x + 3] = -1;
            }
        }
        else if (kierunek == 3 && plansza[y - 3][x] == 0 && y > 2) //gora
        {
            plansza[y][x] = 4;
            plansza[y-1][x] = 4;
            plansza[y-2][x] = 4;
            plansza[y-3][x] = 4;
            set_4 = true;

            if (y != 3)
            {
                plansza[y - 4][x] = -1;
                if (x != 0)
                {
                    plansza[y - 4][x - 1] = -1;
                }
                if (x != 9)
                {
                    plansza[y - 4][x + 1] = -1;
                }

            }
            if (y != 9)
            {
                plansza[y + 1][x] = -1;
                if (x != 0)
                {
                    plansza[y + 1][x - 1] = -1;
                }
                if (x != 9)
                {
                    plansza[y + 1][x + 1] = -1;
                }
            }
            if (x != 0)
            {
                plansza[y][x - 1] = -1;
                plansza[y - 1][x - 1] = -1;
                plansza[y - 2][x - 1] = -1;
                plansza[y - 3][x - 1] = -1;
            }
            if (x != 9)
            {
                plansza[y][x + 1] = -1;
                plansza[y - 1][x + 1] = -1;
                plansza[y - 2][x + 1] = -1;
                plansza[y - 3][x + 1] = -1;
            }

           
        }
        else if (kierunek == 4 && plansza[y + 3][x] == 0 && y < 7) //dol
        {
            plansza[y][x] = 4;
            plansza[y+1][x] = 4;
            plansza[y+2][x] = 4;
            plansza[y+3][x] = 4;
            set_4 = true;

            if (y != 0)
            {
                plansza[y - 1][x] = -1;
                if (x != 0)
                {
                    plansza[y - 1][x - 1] = -1;
                }
                if (x != 9)
                {
                    plansza[y - 1][x + 1] = -1;
                }

            }
            if (y != 6)
            {
                plansza[y + 4][x] = -1;
                if (x != 0)
                {
                    plansza[y + 4][x - 1] = -1;
                }
                if (x != 9)
                {
                    plansza[y + 4][x + 1] = -1;
                }
            }
            if (x != 0)
            {
                plansza[y][x - 1] = -1;
                plansza[y + 1][x - 1] = -1;
                plansza[y + 2][x - 1] = -1;
                plansza[y + 3][x - 1] = -1;
            }
            if (x != 9)
            {
                plansza[y][x + 1] = -1;
                plansza[y + 1][x + 1] = -1;
                plansza[y + 2][x + 1] = -1;
                plansza[y + 3][x + 1] = -1;
            }
        }
        else
        {
            cout << " ZLY!"<<endl;
            kierunek = losuj_kierunek(generator);
        }
    }

    cout <<endl<<"III"<< endl;
    /* Losowanie dwóch 3-masztowców */

    int licznik_zmian_3 = 0;

    for (int i = 0; i < 2; i++)
    {
        kierunek = losuj_kierunek(generator);
        x = losuj_xy(generator);
        y = losuj_xy(generator);
        set_3 = false;
        licznik_zmian_3 = 0;

        cout << "X: " << x << " Y: " << y << endl;

        while (set_3 == false)
        {
            cout << "Kierunek: " << kierunek;

            if (kierunek == 1 && plansza[y][x - 2] == 0 && x > 1) //lewo
            {
                plansza[y][x] = 3;
                plansza[y][x - 1] = 3;
                plansza[y][x - 2] = 3;
                set_3 = true;

                if (x != 2)
                {
                    plansza[y][x - 3] = -1;
                    if (y != 0)
                    {
                        plansza[y - 1][x - 3] = -1;
                    }
                    if (y != 9)
                    {
                        plansza[y + 1][x - 3] = -1;
                    }

                }
                if (x != 9)
                {
                    plansza[y][x + 1] = -1;
                    if (y != 0)
                    {
                        plansza[y + 1][x + 1] = -1;
                    }
                    if (y != 9)
                    {
                        plansza[y - 1][x + 1] = -1;
                    }
                }
                if (y != 0)
                {
                    plansza[y - 1][x] = -1;
                    plansza[y - 1][x - 1] = -1;
                    plansza[y - 1][x - 2] = -1;
                }
                if (y != 9)
                {
                    plansza[y + 1][x] = -1;
                    plansza[y + 1][x - 1] = -1;
                    plansza[y + 1][x - 2] = -1;
                }

            }
            else if (kierunek == 2 && plansza[y][x + 2] == 0 && x < 8) //prawo
            {
                plansza[y][x] = 3;
                plansza[y][x + 1] = 3;
                plansza[y][x + 2] = 3;
                set_3 = true;

                if (x != 7)
                {
                    plansza[y][x + 3] = -1;
                    if (y != 0)
                    {
                        plansza[y - 1][x + 3] = -1;
                    }
                    if (y != 9)
                    {
                        plansza[y + 1][x + 3] = -1;
                    }

                }
                if (x != 0)
                {
                    plansza[y][x - 1] = -1;
                    if (y != 0)
                    {
                        plansza[y + 1][x - 1] = -1;
                    }
                    if (y != 9)
                    {
                        plansza[y - 1][x - 1] = -1;
                    }
                }
                if (y != 0)
                {
                    plansza[y - 1][x] = -1;
                    plansza[y - 1][x + 1] = -1;
                    plansza[y - 1][x + 2] = -1;
                }
                if (y != 9)
                {
                    plansza[y + 1][x] = -1;
                    plansza[y + 1][x + 1] = -1;
                    plansza[y + 1][x + 2] = -1;
                }

            }
            else if (kierunek == 3 && plansza[y - 2][x] == 0 && y > 1) //gora
            {
                plansza[y][x] = 3;
                plansza[y - 1][x] = 3;
                plansza[y - 2][x] = 3;
                set_3 = true;

                if (y != 2)
                {
                    plansza[y - 3][x] = -1;
                    if (x != 0)
                    {
                        plansza[y - 3][x - 1] = -1;
                    }
                    if (x != 9)
                    {
                        plansza[y - 3][x + 1] = -1;
                    }

                }
                if (y != 9)
                {
                    plansza[y + 1][x] = -1;
                    if (x != 0)
                    {
                        plansza[y + 1][x - 1] = -1;
                    }
                    if (x != 9)
                    {
                        plansza[y + 1][x + 1] = -1;
                    }
                }
                if (x != 0)
                {
                    plansza[y][x - 1] = -1;
                    plansza[y - 1][x - 1] = -1;
                    plansza[y - 2][x - 1] = -1;
                }
                if (x != 9)
                {
                    plansza[y][x + 1] = -1;
                    plansza[y - 1][x + 1] = -1;
                    plansza[y - 2][x + 1] = -1;
                }
            }
            else if (kierunek == 4 && plansza[y - 2][x] == 0 && y < 8) //dol
            {
                plansza[y][x] = 3;
                plansza[y + 1][x] = 3;
                plansza[y + 2][x] = 3;
                set_3 = true;

                if (y != 0)
                {
                    plansza[y - 1][x] = -1;
                    if (x != 0)
                    {
                        plansza[y - 1][x - 1] = -1;
                    }
                    if (x != 9)
                    {
                        plansza[y - 1][x + 1] = -1;
                    }

                }
                if (y != 7)
                {
                    plansza[y + 3][x] = -1;
                    if (x != 0)
                    {
                        plansza[y + 3][x - 1] = -1;
                    }
                    if (x != 9)
                    {
                        plansza[y + 3][x + 1] = -1;
                    }
                }
                if (x != 0)
                {
                    plansza[y][x - 1] = -1;
                    plansza[y + 1][x - 1] = -1;
                    plansza[y + 2][x - 1] = -1;
                }
                if (x != 9)
                {
                    plansza[y][x + 1] = -1;
                    plansza[y + 1][x + 1] = -1;
                    plansza[y + 2][x + 1] = -1;
                }
            }
            else
            {
                cout << " ZLY!" << endl;
                kierunek = losuj_kierunek(generator);
                licznik_zmian_3++;
                if (licznik_zmian_3 > 10)
                {
                    x = losuj_xy(generator);
                    y = losuj_xy(generator);
                    licznik_zmian_3 = 0;
                    cout << "X: " << x << " Y: " << y << endl;
                }
            }
        }
        cout << endl;
    }

}
int main()
{
    //cout << distribution(generator) << endl;

    int plansza[10][10] = {};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            plansza[i][j] = 0;
            //cout << plansza[i][j] << " ";
        }
        //cout << endl;
    }

    ustaw_statki(plansza);

    cout<<endl<<endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout.width(2);
            cout << plansza[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (plansza[i][j] > 0)
            {
                cout <<"x ";
            }
            else {
                cout << "- ";
            }
        }
        cout << endl;
    }

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
