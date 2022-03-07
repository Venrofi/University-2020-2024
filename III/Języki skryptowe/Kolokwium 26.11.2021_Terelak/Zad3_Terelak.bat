@echo off
echo Zadanie 3 Radosław Terelak
SETLOCAL ENABLEDELAYEDEXPANSION

:dalej
cls

ECHO Podaj nazwe pliku .txt
SET /p nazwa=

REM Dla zadanego pliku .txt wykonaj
FOR %%G IN (%nazwa%.txt) DO (
    SET string=!%%G: =!
    ECHO !string!>"nowy_%nazwa%.txt"
)

echo Czy chcesz usunac biale znaki w kolejnym pliku?[y/n]

set /p dalej=
if %dalej%==y goto :dalej

PAUSE