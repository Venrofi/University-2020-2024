@echo off 
ren %1\*.txt *.xtx

echo Zamieniono wszystkie pliki .txt na .xtx

if "%~2"=="" goto end 
if %2==c (goto kopiowanie) else (goto end) 

:kopiowanie 
set /p katalog="Podaj katalog: " 
set /p data="Podaj date: " 

if not exist %1\%katalog% mkdir %1\%katalog% 
forfiles /p %1 /m *.xtx /c "cmd /c copy @path %katalog%\@file" /d -%data% 

echo Skopiowano odpowiednie pliki do %katalog%

:end 
PAUSE    