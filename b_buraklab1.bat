@echo off
rem Кодировка - UTF-8
chcp 65001 >nul
rem Для корректной работы переменных
setlocal EnableDelayedExpansion

rem Если папки, указанной в первом параметре, не существует:
if not exist %1%\ (
echo Данной папки нет
pause

rem В противном случае:
) else (

rem Проход по файлам в данной папке, в т.ч. и подпапках:
for /f "delims=" %%i in ('dir /a-d/b/s %1') do (

rem Т.к. в bat нет встроенной функции определения владельца файла,
rem необходимо вызвать скрипт PowerShell, в котором данная функция есть.
PowerShell.Exe -executionpolicy bypass -File "findowner.ps1" "%%i" >op.tmp
set /p owner=<op.tmp
del op.tmp

rem Если размер файла входит в заданный диапазон и у него подходящий владелец,
rem произвести вывод его полного названия, краткого названия и его размера:
if %%~zi leq %3 if %%~zi geq %2 if "!owner!" equ "%4" echo %%i %%~nxi %%~zi>con)

rem Отдельным циклом произвести подсчёт всех файлов в папке и её подпапках:
set ff=0 & for /f "delims=" %%i in ('dir /a-d/b/s %1') do @(set /a ff+=1 >nul)

rem Вывод количества файлов:
echo Всего файлов прочитано: !ff! && set "ff="
pause
)

rem Пример команды:
rem b_buraklab1.bat D:\abc 1 1000 WIN-H26RJ3278L3\user