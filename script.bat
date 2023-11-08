@echo off
chcp 65001

set folder_path=%1
set attributte=%2

REM Проверяем, существует ли указанная папка
if not exist %folder_path% (
    echo This folder not exist
    exit /b
)

REM Поиск файлов с заданным атрибутом доступа и запись их имен в result.txt
dir %1 /a:%2 /s /b > result.txt 

echo The search is complete. The result is written to result.txt