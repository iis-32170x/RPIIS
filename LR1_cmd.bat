@echo off
chcp 65001
setlocal enabledelayedexpansion

if "%~1"=="" (
    echo Пожалуйста, укажите путь к папке в качестве аргумента
    exit /b 1
)

if not exist "%~1" (
    echo Данной папки нет
    exit /b 1
)

set "temp_file=temp.txt"
if exist "%temp_file%" del "%temp_file%"


for /d %%a in ("%~1%\*") do (
    set "file_count=0"
    for %%b in ("%%a\*") do (
        set /a "file_count+=1"
    )
    echo !file_count!,%%~nxa >> "%temp_file%"
)

sort "%temp_file%" > "temp1.txt"

(for /f "tokens=1,* delims=," %%c in (temp1.txt) do echo %%d) > "result.txt"


echo Список подкаталогов отсортирован и сохранен в файле result.txt.

del "%temp_file%"
del "temp1.txt"