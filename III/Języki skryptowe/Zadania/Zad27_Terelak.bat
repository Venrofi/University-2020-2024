@echo off
echo "Zmienna PATH z wartosciami systemowymi: " 
echo %PATH%
echo.
echo "Sciezka lokalna ustawiona na C: "
SETLOCAL
PATH="C:\"
echo %PATH%
ENDLOCAL
echo.
echo "Zmienna PATH po ENDLOCAL: "
echo %PATH%
PAUSE