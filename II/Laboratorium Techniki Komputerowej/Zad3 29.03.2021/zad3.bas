DDRA = 255
DDRB = &B1011    'Ustawienie PB2 jako wejœcie, reszta jako wyjœcie
PORTB = &B1111   'Wszystkie ustawiamy na stan wysoki
MCUCR.1 = 1  'Ustawiliœmy aby przerwanie INT0 na zbocze opadaj¹ce
SREG.7 = 1   'Zezwolenie na wykonywanie przerwañ musi byæ w³¹czone
GIMSK.6 = 1  'Zezwolenie na wykonywanie przerwania INT0

DIM k_1 as Byte    'Wyœwietlanie litery "T", tworzymy 5 bajtów
DIM k_2 as Byte
DIM k_3 as Byte
DIM k_4 as Byte
DIM k_5 as Byte

k_1 = &B10000000   'Zapalamy odpowiednie okienka
k_2 = &B10000000
k_3 = 255
k_4 = &B10000000
k_5 = &B10000000

ON INT0 wyswietl   'Dodajemy przerwanie

do                 'Pêtla oczekuj¹ca na input przerwania

loop

end

wyswietl:       'Zmiana stanu PORTA na kolejne wartoœci wczeœniej zainicjowane

PORTA = k_1
waitus 400      'pauza na 400 mikrosekund

PORTA = k_2
waitus 400

PORTA = k_3
waitus 400

PORTA = k_4
waitus 400

PORTA = k_5
waitus 400

PORTA = 0     'Wygaszanie wszystkiego

return

