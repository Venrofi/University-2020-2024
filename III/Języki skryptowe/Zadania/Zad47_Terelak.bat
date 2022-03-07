@echo off
echo Podaj parametr (-dodaj / -usun): 
set /p parametr=

if /i %parametr%==-dodaj ( goto dodawanie )
if /i %parametr%==-usun ( goto usuwanie )

echo Zly parametr!
goto koniec

:dodawanie
type nul > test.txt
echo Utworzono plik test.txt
goto koniec

:usuwanie
del test.txt
echo Usunieto plik test.txt
goto koniec

:koniec
PAUSE