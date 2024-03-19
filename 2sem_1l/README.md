# Лабораторная работа №1 (Вариант 2)

### Цель работы:

Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных.

### Задача:

Создать множество и реализовать следующий функционал: добавление элемента во множество, удаление элемента из
множества, поиск элемента во множестве, объединение двух
множеств, пересечение двух множеств.

### Список ключевых понятий:

Множество – это структурированный тип данных, представляющий собой набор взаимосвязанных по какому-либо признаку или группе признаков неповторяющихся объектов, которые  можно рассматривать как единое целое.

### Реализация:












*Код:*  

```batch
@echo off
rem "На вход пакетному файлу отправляем абсолютный путь к папке. Если такой папки нет, то пишет “No input folder” и выполнение программы завершается.
if "%~1"=="" (
    echo No input folder 
    pause 
    exit /b 2
)

rem "Команда If...() используется для проверки, существует ли первый аргумент (папка). Двойка-код возврата, указывающий на ошибку." 

if exist "D:\study\batniki\alotoffiles" (
    echo Directory exists
) else (
    echo Directory not exists 
    pause
    exit
)

pause 

rem "Определяем переменные в пакетном файле:searchDir - папка с файлами, outputFile - текстовый файл с результатом программы"
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
### Пример выполнения работы:

1.На вход пакетному файлу отправляем абсолютный путь к папке. Если путь не задан, то пишет “No input folder” и выполнение программы завершается.
![Пример](/images/failbatpng.png)  


2.Далее используем команду if...() для проверки, существует ли первый аргумент(папка).
![Пример](/images/excelbatpng2.png)

3.Следующим шагом определяем переменные в пакетном файле, где searchDir - папка с файлами для сортировки (в случае примера это папка alotoffiles), а текстовый документ, куда отправится результат - outputFile (result.txt в примере)
![Пример](/images/alotoffielspng.png)  

4.Создаём пустой файл под результат или очищаем содержимое существующего.

5.Далее с помощью команд for...() инициализируем перебор всех файлов в папке, после чего выводится сообщение о том, что результаты записаны.
![Пример](/images/filebatresultpng.png)  
![Пример](/images/resultpng.png)  







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

#Определяем переменные в пакетном файле:searchDir - папка с файлами, outputFile - текстовый файл с результатом программы
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

### Пример выполнения работы:

Ход выполнения работы аналогичен предыдущей программе. Главным и единственным же отличием является синтаксис.
![Пример](/images/fileshresult.png)
![Пример](/images/resultpng.png)

### Итог

В ходе работы были приобретены некоторые основные навыки работы в Git Bush. А так же научился командам для работы в GitHub.



