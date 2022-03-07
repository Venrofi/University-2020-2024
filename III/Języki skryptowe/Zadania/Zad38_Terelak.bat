@echo off
set /p adres="Podaj katalog docelowy: "
for /l %%i in (0,1,%1) do (echo %%i >> %adres%\liczby.txt) 

echo %1 liczb zostalo zapisanych w pliku liczby.txt w podanej lokalizacji :)
PAUSE