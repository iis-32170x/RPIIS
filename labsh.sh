#!/bin/bash

if [ -z "$1" ]; then
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
