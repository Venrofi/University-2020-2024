@echo off 
echo Podaj pierwszy tekst:
set /p tekst1=
echo Podaj drugi tekst: 
set /p tekst2=

set "wynik=%tekst1%%tekst2%"

echo Wynik polaczenia obu tekstow: %wynik%

PAUSE