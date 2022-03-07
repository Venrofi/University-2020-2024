@echo off

:MENU
cls
echo =============== MENU ===============
echo 1. Znajdz falszywe worki z monetami
echo 2. Stworz nowy raport
echo 3. Wyswietl najnowszy raport
echo 4. Usun raporty
echo 5. Wyjdz

set /p wybor=
if %wybor%==1 GOTO JEDEN
if %wybor%==2 GOTO DWA
if %wybor%==3 GOTO TRZY
if %wybor%==4 GOTO CZTERY
if %wybor%==5 GOTO END
if not %wybor%==1 if not %wybor%==2 if not %wybor%==3 if not %wybor%==4 if not %wybor%==5 call :MENU

:JEDEN
cls
call Projekt_Terelak.py
echo Utworzono wyniki :)
PAUSE
GOTO :MENU

:DWA
cls
call Backup.py
echo Raport zostal utworzony :)
PAUSE
GOTO :MENU

:TRZY
cls
set path=%~dp0
FOR /F "eol=| delims=" %%I IN ('DIR "%path%\BACKUP\*.html" /A-D /B /O-D /TW 2^>nul') DO (
    SET NajnowszyRaport=%%I
    GOTO ZNALEZIONO
)
echo Nie znaleziono raportu!
PAUSE
GOTO :MENU

:ZNALEZIONO
echo Najnowszy raport to: %NajnowszyRaport%
call "%path%\BACKUP\%NajnowszyRaport%"
PAUSE
GOTO :MENU

:CZTERY
cls
set path=%~dp0
IF EXIST "%path%\BACKUP\*.html" (
    del "%path%\BACKUP\*.html"
    echo Pomyslnie usunieto istniejace raporty!
) ELSE echo Nie znaleziono raportow!

PAUSE
GOTO :MENU 

:END