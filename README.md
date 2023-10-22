# Лабораторная работа №2 

### Условие 

Создать файл sh и bat, который выполняет следующее: 

На вход пакетному файлу приходит абсолютный путь к папке (как параметр пакетного файла). 

Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы.

Если такая папка есть, то выполнить поиск файлов с одинаковым содержимым в указанной папке

с учетом подкаталогов. Результат поиска (путь к найденным одинаковым файлам) записать в файл result.txt.

Если в папке будет содержаться несколько видов одинаковых файлов в результирующем файле

отделять эти группы пустой строкой.

## File.bat

*Код:*  

```batch
@echo off
If "%~1"=="" (
    echo No input folder 
    pause 
    exit /b 2
)

rem "Команда If... используется для проверки, существует ли первый аргумент (папка). Двойка-код возврата, указывающий на ошибку." 

if exist "D:\study\batniki\alotoffiles" (
    echo Directory exists
) else (
    echo Directory not exists 
    pause
    exit
)

pause 

rem "Определяем переменные в пакетном файле"
set "searchDir=alotoffiles"
set "outputFile=result.txt"

rem "Нижняя команда создаёт пустой файл или очищает содержимое существующего."
type nul > "%outputFile%" 

rem "Инициируем перебор всех файлов в спискe"
for /r "%searchDir%" %%A in (*) do (
    for /r "%searchDir%" %%B in (*) do (
       if /I "%%A" neq "%%B" (
          rem "/I задает сравнение текстовых строк без учета регистра; neq - неактуален ли один одному"
          fc /b "%%A" "%%B" > nul
          rem "nul - отказ от вывода данных в терминал"  
          if errorlevel 1 (
          echo "files are different" > nul 
          ) else (
          echo %%A >> "%outputFile%"
          echo %%B >> "%outputFile%"
          echo %%--------------------------------------------------------- >> "%outputFile%"
          )
      )
   )
)

echo "Results in result.txt"
pause
```
## File.sh
*Код:*
```bash
#!/bin/bash

if [ -z "$1" ]; 
    then
    echo "No input folder"
    
    #Выводит текст с ожиданием ввода для продолжения (pause)
    read -p "Press any key to continue..."
    exit
fi

searchDir="D:/study/batniki/alotoffiles"
outputFile="result.txt"

#Проверка, является ли папкой и существует ли
if [ ! -d "$searchDir" ]; then
    echo "Directory does not exist"
    read -p "Press any key to continue..."
    exit
fi

read -p "Press any key to continue..."

# Создаем пустой файл result.txt
> "$outputFile"

# Цикл обхода всех файлов в указанной папке и ее подкаталогах
for fileA in "$searchDir"/*; do
    for fileB in "$searchDir"/*; do
        if [ "$fileA" != "$fileB" ]; then
            if ! cmp -s "$fileA" "$fileB"; then
                echo "files are different" > /dev/null
            else
                echo "$fileA" >> "$outputFile"
                echo "$fileB" >> "$outputFile"
                echo "---------------------------------------------------------" >> "$outputFile"
            fi
        fi
    done
done

echo "Results in $outputFile"
read -p "Press any key to continue..."
exit
```


