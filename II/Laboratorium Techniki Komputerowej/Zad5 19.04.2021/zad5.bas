TCCR1B.1 = 1 'ustawienie pierwszego bitu rejestru TCCR1B na 1
TCCR0B.0 = 1 'ustawienie zerowegoo bitu rejestru TCCR0B na 1
TCCR0B.1 = 1 'ustawienie pierwszego bitu rejestru TCCR0B na 1

TIMSK0.1 = 1

DDRA = &B11111111    'ustawienie calego portu A jako wyjscie
DDRB = &B1011     'ustawienie portu PB2 jako wejscie,a PB1, 3 i 4 jako wyjscie; DDRB - ustawiamy cos w B
PORTB = &B1111       'ustawienie wszystkich bitów na stan wysoki
MCUCR.1 = 1       'ustawiamy ISC01 jako 1, reszta pozostaje jako  0 - ustawilismy przerwanie INT0 na zbocze opadajace
SREG.7 = 1     'zezwolenie na wykonywanie przerwan - ustawienie 7 bitu rejestru SREG jako 1
GIMSK.6 = 1       'ustawiamy 6 bit rejestru GIMSK jako 1, co pozwala nam na wykonanie zewnetrznego przerwania INT0

DIM L as byte  'zadeklarowanie zmiennej L typu bajt
DIM H as byte  'zadeklarowanie zmiennej H typu bajt
DIM D as word  'zadeklarowanie zmiennej D typu word
DIM I as byte  'zadeklarowanie zmiennej I typu bajt, ktora bedzie sluzyc jako licznik


DIM k(5) as Byte    'Wyœwietlanie litery "T", tworzymy 5 bajtów

k(1) = &B10000000   'Zapalamy odpowiednie okienka
k(2) = &B10000000
k(3) = 255
k(4) = &B10000000
k(5) = &B10000000

ON INT0 wyswietl
ON OC0A pasek



do    'petla nieskonczona; jedynie przerwanie INT0 powoduje wyjscie z niej

loop

end

wyswietl:   'wyswietl zmienia wartosc PORTA na wartosci zmiennych odpowiadajacych kolumnom

L = TCNT1L  'zapisywanie licznika do zmiennej L (lower)
H = TCNT1H  'zapisywanie licznika do zmiennej H (higher)

TCNT1L = 0  'zerowanie TCNT1L
TCNT1H = 0  'zerowanie TCNT1H

D = 256*H
D = H + L
D = D/1024  'podzielenie D przez 1024, bo 8*128 = 1024

OCR0A = Low(D)   'zapisanie nizszych bitów zmiennej D do rejestru OCR0A,
                 'który odpowiada za porównywanie z wartoscia licznika TCNT0

I = 1 'ustawienie wartosci zmiennej I jako 1

return


pasek:   'etykieta pasek i obsluga przerwania OC0A

IF I<6 THEN    'jesli I jest mniejsze niz 6 to ustawiamy PORTA jako k(I)
   PORTA = k(I)
ELSE
   PORTA = 0   'jesli I jest wieksze lub rowne 6 to ustawiamy PORTA jako 0
END IF

INCR I  'zwiekszenie wartosci zmiennej I o 1

return