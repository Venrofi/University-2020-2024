@echo off 
:dalej
cls
echo Podaj pierwsza liczbe:
set /p liczba1= 


echo Wybierz operacje
echo Dodawanie: 1, Odejmowanie: 2,
echo Mnozenie: 3, Dzielenie: 4

set /p dzialanie=

echo Podaj druga liczbe:
set /p liczba2= 
set wynik=0

if %dzialanie%==1 (set /a wynik = %liczba1% + %liczba2%) 
if %dzialanie%==2 (set /a wynik = %liczba1% – %liczba2%) 
if %dzialanie%==3 (set /a wynik = %liczba1% * %liczba2%) 
if %dzialanie%==4 (set /a wynik = %liczba1% / %liczba2%) 
echo Wynik operacji to: %wynik%

echo Czy chcesz wykonac kolejne obliczenie?[y/n]

set /p dalej=
if %dalej%==y goto :dalej
PAUSE