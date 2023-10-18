@echo off
chcp 65001 > nul
setlocal enabledelayedexpansion

set /p "folder=Введите путь к папке: "
set "report=report.txt"

if not exist "%folder%" (
    echo Данной папки нет!
    exit /b
)

for /r "%folder%" %%f in (*) do (
    set "ext=%%~xf"
    set /a "count[!ext!]+=1"
)

(for /f "tokens=2,3 delims=[]=" %%a in ('set count[') do (
    echo %%a - %%b
)) | sort /r > "%report%"

endlocal

pause