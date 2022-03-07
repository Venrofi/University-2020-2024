@echo off 
set /p tekst=<%1

echo Przed zmiana: %tekst%
echo.
set tekst=%tekst:nie=tak!%

echo Po zmianie: %tekst%
echo %tekst%>%2
echo.
echo Zaktualizowany tekst zostal zapisany w pliku %2

PAUSE