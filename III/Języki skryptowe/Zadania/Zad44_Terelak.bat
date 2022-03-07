@echo off
set /p plik=Podaj typ pliku do sprawdzenia 

if exist *.%plik% (goto usun) else (goto brak)

:usun
echo Usuwam pliki %plik%
del *.%plik%
goto koniec

:brak
echo Brak plikow o takim rozszerzeniu!

:koniec
PAUSE