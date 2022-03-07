@echo off
set sciezka="%~dpf0"

for /f "delims=" %%i in (%sciezka%) do set sciezka_bez=%%i

echo Sciezka z cudzyslowem: %sciezka%
echo Sciezka bez cudzyslowu: %sciezka_bez%

PAUSE