DDRB = &B1011 'Ustawienie PB2 jako wej�cie, reszta jako wyj�cie
PORTB = &B1111 'Wszystkie ustawiamy na stan wysoki
MCUCR.1 = 1 'Ustawili�my aby przerwanie INT0 na zbocze opadaj�ce
SREG.7 = 1 'Zezwolenie na wykonywanie przerwa� musi by� w��czone
GIMSK.6 = 1 'Zezwolenie na wykonywanie przerwania INT0

DIM A as byte 'Zadeklarowanie zmiennej A typu bajt

ON INT0 pisz

do         'P�tla niesko�czona

loop

end

pisz:       'Obs�ua przerwania
incr A      'Zwi�kszanie warto�ci zmiennej A
return


