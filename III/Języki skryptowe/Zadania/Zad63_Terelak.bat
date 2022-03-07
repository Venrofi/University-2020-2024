@echo off 
:menu 
cls 
echo ******  MENU  ******
echo ))) 1. Skrypt 1 (((
echo ))) 2. Skrypt 2 (((
echo ))) 3. Skrypt 3 ((( 
echo   ) 4. Wyjscie  ( 
echo. 
set /p wybor="Wybierz skrypt do wykonania:" 
IF %wybor%==1 GOTO nr1
IF %wybor%==2 GOTO nr2 
IF %wybor%==3 GOTO nr3 
IF %wybor%==4 GOTO exit 
 
:nr1 
echo Uruchamiam Skrypt 1..
pause 
call skrypt1.bat 
goto menu

:nr2 
echo Uruchamiam Skrypt 2..
pause
call skrypt2.bat 
goto menu
 
:nr3 
echo Uruchamiam Skrypt 3..
pause 
call skrypt3.bat
goto menu 

:exit 
echo Wyjscie..

PAUSE