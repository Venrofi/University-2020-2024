// Zad1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "L1: " << argv[1] << ", L2: " << argv[3] << endl;
    cout << "Znak: " << argv[2] << endl;
    if (argv[2][0] == 'x')
    {
        cout << atoi(argv[1]) * atoi(argv[3])<<endl;
    }
    else if (argv[2][0] == '+')
    {
        cout << atoi(argv[1]) + atoi(argv[3]) << endl;
    }
    else if (argv[2][0] == '-')
    {
        cout << atoi(argv[1]) - atoi(argv[3]) << endl;
    }
    else if (argv[2][0] == '/')
    {
        if (argv[3][0] != '0')
        {
            cout << atoi(argv[1]) / atoi(argv[3]) << endl;
        }
    }
    else
    {
        cout << "Zle dane";
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
