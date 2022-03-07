// Zadanie:
// Napisz program wykorzystujący mechanizm "try throw catch".Program powinien:
// 1) zawierać funkcję dzielenia z obsługą wyjątku dzielenia przez zero.
// 2) zawierać funkcję modulo z obsługą wyjątku gdzie wprowadzone dwie zmienne są równe bądz są swoimi wielokrotnościami.

// W sytuacji kiedy wprowadzane dane są prawidłowe, program powinien wyświetlać wyniki. 
// W sytuacji gdy dane są niedozwolone powinien pojawić się stosowny komunikat. 
// Obsługa obu wyjątków ma działać niezależnie od siebie (wywołanie komunikatu wyjątku dla jednej funkcji nie może powodować zatrzymania działania drugiej funkcji).

#include <iostream>

using namespace std;

double dzielenie(double a, double b)
{
    if (b == 0)
    {
        string error = "Dzielenie przez 0!";
        throw error;
    }

    return a / b;
}

int modulo(int a, int b)
{
    if (b == 0)
    {
        string error = "Nieprawidlowe dane!";
        throw error;

    }
    else if (a == 0)
    {
        return 0;
    }
    else if (a == b)
    {
        string error = "Liczby sa rowne!";
        throw error;
    }
    else if (a % b == 0 || b % a == 0)
    {
        string error = "Liczby sa wielokrotnosciami!";
        throw error;
    }
    return a % b;
}

int main()
{
    int x, y;
    cout << "Podaj dwie liczby: ";
    cin >> x >> y;

    cout<<"Dzielenie: "<<endl;
    try
    {
        cout << "Wynik: " << dzielenie(x, y) << endl;
    }
    catch (string error_dzielenie)
    {
        cout << "Wyjatek: " << error_dzielenie << endl;
    }
    cout << endl << "Modulo: " << endl;
    try
    {
        cout << "Wynik: " << modulo(x, y) << endl;
    }
    catch (string error_modulo)
    {
        cout << "Wyjatek: " << error_modulo << endl;
    }

    return 0;
}
