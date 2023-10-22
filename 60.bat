@echo off
chcp 65001 > nul

set /p folder_path=Введите путь к папке:

if not exist "%folder_path%" (
    echo Папка не найдена
    exit/b
)
tasklist /v /fi "cputime gt 00:10:00" /fo csv | sort/r > %folder_path%/result.txt
