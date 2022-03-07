DDRB = &B1011 'Ustawienie PB2 jako wejœcie, reszta jako wyjœcie
PORTB = &B1111 'Wszystkie ustawiamy na stan wysoki
MCUCR.1 = 1 'Ustawiliœmy aby przerwanie INT0 na zbocze opadaj¹ce
SREG.7 = 1 'Zezwolenie na wykonywanie przerwañ musi byæ w³¹czone
GIMSK.6 = 1 'Zezwolenie na wykonywanie przerwania INT0

DIM A as byte 'Zadeklarowanie zmiennej A typu bajt

ON INT0 pisz

do         'Pêtla nieskoñczona

loop

end

pisz:       'Obs³ua przerwania
incr A      'Zwiêkszanie wartoœci zmiennej A
return


