@echo off
REM Skrypt jest taki sam, ponieważ już wcześniej użyłem komendy SET by ustalić ilość iteracji pętli

set /p n=Podaj ile liczb zapisac 
for /l %%i in (1,1,%n%) do (echo %%i >> %1.txt) 

echo %n% liczb zostalo zapisanych w pliku %1.txt :)

PAUSE 