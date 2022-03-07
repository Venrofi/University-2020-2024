// BubbleSort.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

void sortowanie(int* liczby, int rozmiar, bool rosnaco = true)
{
    int temp{};
    bool zamiana = true;
    int counter = 0;

    //while (zamiana == true)
    //{
    //    zamiana = false;

    //    for (int i = 0; i < rozmiar-1; i++)
    //    {
    //        //cout << "i: " << liczby[i] << " , i+1: " << liczby[i + 1] << endl;
    //        if ( liczby[i+1] > liczby[i])
    //        {
    //            temp = liczby[i];
    //            liczby[i] = liczby[i+1];
    //            liczby[i+1] = temp;
    //            zamiana = true;
    //            counter++;
    //            //cout <<endl<< "ZAMIANA!";
    //        }
    //    }
    //}

    if (rosnaco == true)
    {
        cout << "Sortowanie malejaco :)" << endl;
        while (zamiana == true)
        {
            zamiana = false;

            for (int i = 0; i < rozmiar-1; i++)
            {
                if (*(liczby + (i + 1)) > * (liczby + i))
                {
                    temp = *(liczby + i);
                    *(liczby + i) = *(liczby + i + 1);
                    *(liczby + i + 1) = temp;
                    zamiana = true;
                    counter++;
                }
            }
        }
    }
    else
    {
        cout << "Sortowanie rosnaco :) " << endl;
        while (zamiana == true)
        {
            zamiana = false;

            for (int i = 0; i < (rozmiar-1) ; i++)
            {
                if (*(liczby + (i+1)) < * (liczby + i))
                {
                    temp = *(liczby + i + 1);
                    *(liczby + i + 1) = *(liczby + i);
                    *(liczby + i) = temp;
                    zamiana = true;
                    counter++;
                }
            }
        }
    }

    cout << "Posortowane liczby: ";
    for (int i = 0; i < rozmiar; i++)
    {
        cout << *(liczby + i);

        if (i < rozmiar - 1)
        {
            cout << ", ";
        }
    }
    cout << endl << "Ilosc zamianek: " << counter;
}


int main()
{
    int liczby[10] = { 10,1,3,0,4,3,7,7,9,1};

    sortowanie(liczby, 10, true);

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
