#include <iostream>

using namespace std;

int main()
{
    int wyb0{}, wyb1{};
    float temp_in{}, temp_out{};
    double cash{};
    char restart{};
  do
  {
      cout << "KALKULATOR TEMPERATUR I WALUT" << endl;
      cout << "1. KALKULATOR TEMPERATUR" << endl;
      cout << "2. KALKULATOR WALUT" << endl;
      cin >> wyb0;
      switch(wyb0)
      {
        case 1:
            cout << "KALKULATOR TEMPERATUR" << endl;
            cout << "1. Celsjusze na Fahrenheity" << endl;
            cout << "2. Fahrenheity na Celsjusze" << endl;
            cin >> wyb1;
            switch(wyb1)
            {
                case 1:
                    cout << "Podaj temperature w Celsjuszach: "; cin >> temp_in;
                    temp_out = (9 / 5) * temp_in + 32;
                    cout << "Temperatura w Fahrenheitach wynosi: " << temp_out << endl;
                    break;
                case 2:
                    cout << "Podaj temperature w Fahrenheitach: "; cin >> temp_in;
                    temp_out = (temp_in - 32) * (5 / 9);
                    cout << "Temperatura w Celsjuszach wynosi: " <<  temp_out << endl;
                    break;
                default: 
                    cout << "Blad!" << endl;
            }
            break;
        case 2:
            cout << "KALKULATOR WALUT" << endl;
            cout << "Aktualny kurs V-DOLARA to: 116.78987" << endl;
            cout << "Ile cebulionow chcesz wymienic? " << endl;
            cin >> cash;
            cash *= 116.78987;
            cout << "Ilość V-Dolarow po wymianie: " << cash << endl;
            break;  
        default:
            cout << "Blad!" << endl;
            break;
      }
    cout << "Uruchomic ponownie program? (Y/y)" << endl;
    cin >> restart;
  }while(restart == 'Y' || restart == 'y');
  
}
