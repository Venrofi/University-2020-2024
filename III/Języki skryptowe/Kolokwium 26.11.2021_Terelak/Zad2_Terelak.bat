@echo off
echo Zadanie 2 Radosław Terelak
SETLOCAL ENABLEDELAYEDEXPANSION

SET /A ile_p=0
for %%x in (%*) do (
    REM Zliczanie ilości argumentów 
    SET /A ile_p=!ile_p!+1
)

SET /A licznik=0
REM Dla każdego parametru wykonaj:
for %%x in (%*) do (
    REM Zwiększ licznik
    SET /A licznik=!licznik!+1
    REM Jeśli argument nie jest nazwą folderu to scal jego kontent
    IF NOT !licznik! == !ile_p! (
        SET kontent=" "
        REM Dane z plików z odpowiednim rozszerzeniem dopisz do kontentu
        for %%i in (*.%%x) do (
            SET /p kontent=<%%i
        )
        REM kontent wstaw do pliku info_rozszerzenie.txt
        echo !kontent!>>"/%!ile_p!/info_%%x.txt"
    )
)

PAUSE