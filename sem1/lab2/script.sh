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


