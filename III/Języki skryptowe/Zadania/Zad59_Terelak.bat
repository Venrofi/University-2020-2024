@echo off 
echo Tekst bez slowa 'nie': 

setlocal enabledelayedexpansion 
for /f "tokens=* delims=" %%i in (%1) do ( 
set string=%%i 
echo !string:nie=! 
) 
endlocal

PAUSE