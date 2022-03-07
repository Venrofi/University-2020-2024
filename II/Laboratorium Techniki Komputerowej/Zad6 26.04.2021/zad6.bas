ddra = 255  'ustawienie calego portu A jako output'

ddrB = &B1011'ustawienie pb2 jako wejscie reszta jako wyjscie'
portb = &B1111 'ustawiamy na stan wysoki, czyli chyba zapalenie. inaczej moglo by byc =15'

MCUCR.1 = 1     'ustawienie rzeczy potrzebnych do rpzerwania int0 na zbocze opadajace  isc01 ustawione'
sreg.7 = 1     'zezwolenie na wykonannie przerwan (1 to zezwolenie)'

gimsk.6 = 1    'zezwolenie na wykonanie przerwania int0'




do
porta = &B10001000
waitms 400
porta = &B10100000
waitms 400
porta = &B11111111
waitms 400
porta = &B10100000
waitms 400
porta = &B10001000
waitms 400
porta = &B01000000
loop
end