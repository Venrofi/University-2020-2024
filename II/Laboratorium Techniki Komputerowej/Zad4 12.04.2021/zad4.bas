TCCR1B.1 = 1   'Ustawienie prescalera licznika 16-bitowego na wartoœæ 8

DDRA = 255
DDRB = &B1011    'Ustawienie PB2 jako wejœcie, reszta jako wyjœcie
PORTB = &B1111   'Wszystkie ustawiamy na stan wysoki
MCUCR.1 = 1  'Ustawiliœmy aby przerwanie INT0 na zbocze opadaj¹ce
SREG.7 = 1   'Zezwolenie na wykonywanie przerwañ musi byæ w³¹czone
GIMSK.6 = 1  'Zezwolenie na wykonywanie przerwania INT0



DIM H as Byte
DIM L as Byte
DIM D as Word

ON INT0 wyswietl   'Dodajemy przerwanie

do

loop

end

wyswietl:

L = TCNT1L
H = TCNT1H     'Zliczanie licznika

TCNT1H = 0
TCNT1L = 0     'Zerowanie

D = H*256
D = D+L

PORTA = H      'Wyœwietlanie najwa¿niejszych 8 bitów


return
