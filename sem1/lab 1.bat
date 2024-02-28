@echo off
chcp 65001 > nul
echo Введите абсолютный путь: 
set /p upath= 
if not exist "%upath%" (
  echo Данной папки нет
  pause
  exit
)

echo.> "%upath%\result.txt"

for /F "tokens=* delims=" %%a in ('dir /a:h /o:n /b /s %upath%') do (
   echo %%~na>>%upath%\result.txt
)

if not exist "%upath%\result.txt" (
echo Файл не существует
) else (
for %%I in ("%upath%\result.txt") do (
if %%~zI EQU 2 (
echo Скрытых файлов нет 
echo Скрытых файлов не найдено > %upath%\result.txt
) else (
type %upath%\result.txt
)
)
)

pause
