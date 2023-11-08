#!/bin/bash

folder=$1
permission=$2

# Проверяем существование папки
if [ ! -d "$folder" ]; then
  echo "Данной папки нет"
  exit 1
fi

# Поиск файлов с заданным атрибутом доступа
find "$folder" -type f -perm "$permission" > result.txt

echo "Файлы с заданным атрибутом доступа найдены и записаны в файл result.txt"