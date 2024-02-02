#!/bin/bash


if [ -z "$1" ]; then 
  echo "Не указан входной файл."
  exit 1
fi 


sort "$1" -o "$1"


awk '{print $1}' "$1" > surnames.txt 
awk '{print $2}' "$1" > names.txt
awk '{print $3}' "$1" > patronymics.txt

echo "Файлы успешно созданы: surnames.txt, names.txt, otchestvo.txt." 
