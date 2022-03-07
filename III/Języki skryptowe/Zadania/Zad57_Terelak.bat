@echo off
cls

:dalej
echo Podaj tekst:
set /p tekst=

echo %tekst:~0,2% %tekst:~4,6%

echo Chcesz podac inny tekst?[y/n]
set /p dalej=
if %dalej%==y goto :dalej

PAUSE