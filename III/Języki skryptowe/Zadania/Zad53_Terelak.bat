@echo off 
:dalej
echo Podaj liczbe HEX do konwersji:
set /p hex=
set /a dec=0x%hex%
echo Liczba %hex% w zapisie dziesietnym: %dec%

echo Czy chcesz zamienic kolejna liczbe?[y/n]

set /p dalej=
if %dalej%==y goto :dalej
PAUSE