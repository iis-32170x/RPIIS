#!/bin/bash

echo "Введите относительный путь 1:"
read folder1
echo "Введите относительный путь 2:"
read folder2

if [ ! -d "$PWD/$folder1" ]; then
    echo "Данной папки нет - $PWD/$folder1"
    exit 1
fi

if [ ! -d "$PWD/$folder2" ]; then
    echo "Данной папки нет - $PWD/$folder2"
    exit 1
fi

for file in "$PWD/$folder1"/**.**; do
    if [[ "${file##*.}" != "txt" ]]; then
        chmod a=r "$file"
    fi
done
for file in "$PWD/$folder1"/**.txt; do
    mv $file "$PWD/$folder2"/
done

echo "Программа выполнена."
