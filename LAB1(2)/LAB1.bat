@echo off

chcp 65001 > nul

echo Введите дату в формате MM/DD/YYYY:
set /p date= 

PowerShell -Command "(get-date %date%).DayOfWeek"

pause