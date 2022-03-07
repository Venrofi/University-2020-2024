@echo off 
REM Lokalizacja pliku skryptowego ma duże znaczenie, należy go uruchomić z poziomu dysku C:, bez dodatkowych zagnieżdżeń w folderach

for %%i in (C: D:) do ( 
%%i 
cd %%i 
dir /s %1 )

PAUSE