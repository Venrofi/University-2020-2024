@echo off
mkdir kopia_zapasowa
xcopy %1 kopia_zapasowa /s /d
PAUSE