@echo off
set /p adres="Podaj katalog docelowy: "
set /p nazwa="Podaj nazwe pliku: "

call Zad33_Terelak.bat %adres% > %nazwa%
PAUSE