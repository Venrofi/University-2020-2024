@echo off 

if /i "%1"=="/a" goto akcja
if /i "%1"=="/h" goto hilfe

del "%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\*.*" /p /f 
reg delete HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Run /va
PAUSE 
goto:EOF 

:akcja
del "%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\*.*" /f 
reg delete HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Run /va /f 
PAUSE
goto:EOF 

:hilfe
cls
echo Program usuwa wpisy z podmenu Autostart menu Start. 
echo Kasuje rowniez wpisy w edytorze rejestru odpowiedzialne
echo za automatyczne uruchamianie programow przy starcie systemu
echo Atrybuty: 
echo /a Program usuwa wszystkie wpisy
echo /h Program wyswietla pomoc
PAUSE