@echo off
chcp 65001
setlocal enabledelayedexpansion
IF "%~1"=="" (
    echo Данной папки нет
    exit /b
)

set "folder=%~1"

IF NOT EXIST "%folder%" (
    echo Данной папки нет
    exit /b
)

echo. > log.txt

for /r "%folder%" %%F in (*.txt) do (
    set "counter=0"
    for /f "usebackq tokens=*" %%L in ("%%F") do (
        set /a "counter+=1"
        if !counter! == 5 (
            echo %%L >> log.txt
        )
    )
)

sort log.txt /o log.txt

echo Процесс завершен. Строки из файлов txt сохранены в log.txt.

endlocal

