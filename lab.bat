@echo off
chcp 65001 > nul 
netstat -ano | findstr %~1
IF %ERRORLEVEL% EQU 1 (
echo Нет запущенных процессов
exit 1
) ELSE (
echo Процесс запущен
)
for /f "tokens=5" %PID% in ('netstat -ano ^| findstr "%~1"') do (
echo PID процесса: %PID%
)
:ask
SET /P choice= "Хотите завершить процесс? [Y/n]"
IF /I %choice% == Y (
taskkill /pid %PID%
echo Процесс завершен
) ELSE IF /I %choice% == n ( 
exit 0
) ELSE (
goto :ask
)
pause
