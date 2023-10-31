#!/bin/bash

if [ -z "$1" ]; then
    echo "Пожалуйста, укажите путь к папке в качестве аргумента"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Данной папки нет"
    exit 1
fi


find $1 -type d | while read -r dir; do
   if [[ "$dir" != "$1" ]]; then
    file_count=$(find "$dir" -maxdepth 1 -type f | wc -l)
    echo "$file_count ,$(basename "$dir")" >> temp.txt
  fi
done

sort -n -k1 temp.txt > temp1.txt
cut -d',' -f2 temp1.txt > result.txt

rm temp.txt 
rm temp1.txt

echo Список подкаталогов отсортирован и сохранен в файле result.txt.