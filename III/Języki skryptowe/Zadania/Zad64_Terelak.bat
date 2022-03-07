@echo off 
set /p tekst=<%1

echo Przed zmiana: %tekst%

set tekst=%tekst:nie=tak!%

echo Po zmianie: %tekst%

PAUSE