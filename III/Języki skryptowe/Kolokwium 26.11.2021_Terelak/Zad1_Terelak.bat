@echo off
echo Zadanie 1 Radosław Terelak
SETLOCAL ENABLEDELAYEDEXPANSION

REM Dla każdego pliku .txt
FOR %%G IN (*.txt) DO (
    REM Jeśli ilość znaków w .txt modulo 2 jest równa 0, oznacza to że ta liczba jest parzysta
    IF (%%~zG %% 2 == 0) (
        SET string=!%%G:%1=Radek!
        ECHO !string!>%%G
    )
)

PAUSE