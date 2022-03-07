DDRA.1 = 1 'ustawienie portu PA1 na wyjscie'
DDRA = 255  'ustawienie calego portu A jako output'
DDRA = &B10101010 'tam gdzie jest 1 jest wyjscie/zapis binarny od lewej zaczynajac'

DO
   PORTA.1 = 1 'zapalamy'

   wait 1
   waitms 10

   PORTA.1 = 0  'gasimy'
   wait 100
LOOP

end