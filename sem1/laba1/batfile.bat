@echo off
chcp 1251
setlocal enabledelayedexpansion
set /p input=Введите путь к папке:
set "fas=%input%"

rem Проверяем существование указанной папки
IF not EXIST "%fas%" (
  echo Данной папки нет
  exit /b
)

rem Обход файлов .txt
(for /r "%fas%" %%F in (*.txt) do (
    rem Поиск строк "v" или "V"
    for /f "tokens=*" %%A in ('findstr /i "\<[vV][a-zA-Z]*[^ ]*" "%%F"') do (
        rem Разбиваем строки на слова и проверяем, начинаются ли они с "v"
        for %%W in (%%A) do (
            set "word=%%W"
            set "word=!word:~0,1!"
            if /i "!word!"=="v" (
                set "found="
                echo %%W>>result.txt
            )
        )
    )
))

pause