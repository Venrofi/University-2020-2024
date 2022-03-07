@echo off
cls

:dalej
echo Podaj miesiac:
set /p miesiac=

if %miesiac%==styczen (echo Numer miesiaca: 1
) else if %miesiac%==luty (echo Numer miesiaca: 2
) else if %miesiac%==marzec (echo Numer miesiaca: 3
) else if %miesiac%==kwiecien (echo Numer miesiaca: 4
) else if %miesiac%==maj (echo Numer miesiaca: 5
) else if %miesiac%==czerwiec (echo Numer miesiaca: 6
) else if %miesiac%==lipiec (echo Numer miesiaca: 7
) else if %miesiac%==sierpien (echo Numer miesiaca: 8
) else if %miesiac%==wrzesien (echo Numer miesiaca: 9
) else if %miesiac%==pazdziernik (echo Numer miesiaca: 10
) else if %miesiac%==listopad (echo Numer miesiaca: 11
) else if %miesiac%==grudzien (echo Numer miesiaca: 12
) else (echo Zle dane, podaj nazwe miesiaca malymi literami!)

echo Czy chcesz sprawdzic inny miesiac?[y/n]

set /p dalej=
if %dalej%==y goto :dalej
PAUSE