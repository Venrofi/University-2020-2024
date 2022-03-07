@echo off 
echo Podaj lokalizacje pierwszego pliku txt:
set /p lokalizacja1=
echo Podaj lokalizacje drugiego pliku txt:
set /p lokalizacja2=

set /p tekst1=<%lokalizacja1%
set /p tekst2=<%lokalizacja2%

set "wynik=%tekst1%%tekst2%"

echo Wynik polaczenia obu tekstow: %wynik%

PAUSE