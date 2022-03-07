@echo off
set /p n=Podaj ile liczb zapisac 
for /l %%i in (1,1,%n%) do (echo %%i >> %1.txt) 

echo %n% liczb zostalo zapisanych w pliku %1.txt :)

PAUSE