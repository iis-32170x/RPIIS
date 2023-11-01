# Лабараторная работа №2
---
##Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит число (N) и относительный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней и ее подкаталогах находим файлы с расширением txt, которые меньше N Kb и копируем содержимое самого большого найденного файла в самый маленький, а содержимое самого маленького в самый большой

---
### .bat файл
```bat
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
```


### .sh файл

```sh
#!/bin/bash

# Проверяем наличие аргументов командной строки
if [ $# -ne 2 ]; then
  echo "Неверное количество аргументов. Используйте: script.sh <число> <путь к папке>"
  exit 1
fi

# Получаем аргументы командной строки
N=$1
folder=$2
touch $folder/back.txt

# Проверяем существование папки
if [ ! -d "$folder" ]; then
  echo "Данной папки нет: $folder"
  exit 1
fi

# Ищем файлы с расширением .txt в папке и подкаталогах
for file in $(find "$folder" -type f -name "*.txt"); do
  # Получаем размер файла в байтах
  size=$(stat -c %s "$file")

  # Проверяем, что размер меньше N
  if [ $size -lt $N ]; then
    # Если smallest пустой или размер текущего файла меньше, обновляем smallest
    if [ -z "$smallest" ] || [ $size -lt $(stat -c %s "$smallest") ]; then
      smallest="$file"
    fi

    # Если largest пустой или размер текущего файла больше, обновляем largest
    if [ -z "$largest" ] || [ $size -gt $(stat -c %s "$largest") ]; then
      largest="$file"
    fi
  fi
done

# Проверяем, что найдены файлы
if [ -z "$smallest" ]; then
  echo "Не найдены файлы с расширением .txt размером менее $N Kb"
  exit 1
fi

cp "$smallest" "$folder/back.txt"

# Копируем содержимое самого большого файла в самый маленький
cp "$largest" "$smallest"

# Копируем содержимое самого маленького файла в самый большой
cp "$folder/back.txt" "$largest"

rm "$folder/back.txt"

# Выходим с кодом успешного выполнения
exit 0



```
## Их вывод (он одинаковый):
До исполнения скрипта

![IMG_1](img_1.png)

После исполнения скрипта

![IMG_2](img_2.png)
