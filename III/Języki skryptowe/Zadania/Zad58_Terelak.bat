@echo off 
echo Podaj tekst:
set /p tekst= 
set tekst=%tekst:nie=%

echo Tekst bez slowa 'nie': %tekst%

PAUSE