@echo off
setlocal

REM Проверяем наличие аргументов командной строки
if "%~2"=="" (
  echo "Неверное количество аргументов. Используйте: script.bat <число> <путь к папке>"
  exit /b 1
)

REM Получаем аргументы командной строки
set N=%~1
set folder=%~2
cd.>%folder%\back.txt
REM Проверяем существование папки
if not exist "%folder%" (
  echo "Данной папки нет: %folder%"
  exit /b 1
)

REM Ищем файлы с расширением .txt в папке и подкаталогах
for /r "%folder%" %%F in (*.txt) do (
  REM Получаем размер файла в байтах
  setlocal enabledelayedexpansion
  for %%A in ("%%~F") do set "size=%%~zA"
  endlocal
  
  REM Проверяем, что размер меньше N
  if !size! LSS %N% (
    REM Если smallest пустой или размер текущего файла меньше, обновляем smallest
    if not defined smallest (
      set "smallest=%%~F"
    ) else (
      for /f "usebackq" %%B in ('"cmd /q /c echo(!smallest!"') do (
        if !size! LSS %%~zB set "smallest=%%~F"
      )
    )
    
    REM Если largest пустой или размер текущего файла больше, обновляем largest
    if not defined largest (
      set "largest=%%~F"
    ) else (
      for /f "usebackq" %%B in ('"cmd /c echo(!largest!"') do (
        if !size! GTR %%~zB set "largest=%%~F"
      )
    )
  )
)

REM Проверяем, что найдены файлы
if not defined smallest (
  echo "Не найдены файлы с расширением .txt размером менее %N% Kb"
  exit /b 1
)

copy /Y "%smallest%" "%folder%\back.txt" > nul
REM Копируем содержимое самого большого файла в самый маленький
copy /Y "%largest%" "%smallest%" > nul

REM Копируем содержимое самого маленького файла в самый большой
copy /Y "%folder%\back.txt" "%largest%" > nul
del %folder%\back.txt
REM Выходим с кодом успешного выполнения
exit /b 0