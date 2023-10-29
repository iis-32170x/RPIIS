@echo off
setlocal enabledelayedexpansion

set /p input=Vvedite put' k papke:
set "fas=%input%"

:: Проверяем существование указанной папки
if exist "%fas%" (
  echo dannaja papka jest
) else (
  echo dannoj papki net
)

:: Переход в указанную папку
pushd "%fas%"

:: Находим файлы с нужным расширенем 
set i=1
for %%f in (*.bat) do (
    set /a i+=1
    set "file[!i!]=%%f"
)

sort "%fas%"

:: Запускаем отсортированные файлы 
for /l %%c in (1,1,%i%) do (
    timeout 1
    start "" "!file[%%c]!"
)

sort /r result.txt /o results.txt
   
exit /b  