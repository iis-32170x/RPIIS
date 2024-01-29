#!/bin/bash

# Проверяем количество аргументов
if [ "$#" -lt 2 ]; then
  echo "Необходимо указать строку и путь к папке!"
  exit 1
fi

target_path="$2"

# Проверяем существование папки
if [ ! -d "$target_path" ]; then
  echo "Данной папки '$target_path' нет"
  exit 1
fi

# Функция для обхода файлов и папок
calculate_directory_size() {
  local directory="$1"
  local total_size=0
  local total_files=0

  # Цикл для обхода файлов и папок в заданной директории
  for item in "$directory"/*; do
    if [ -d "$item" ]; then
      # Если элемент является папкой, вызываем эту же функцию рекурсивно
      calculate_directory_size "$item"
    elif [ -f "$item" ]; then
      # Если элемент является файлом, увеличиваем суммарный размер и число файлов
      file_size=$(stat -c "%s" "$item")
      total_size=$((total_size + file_size))
      total_files=$((total_files + 1))
    fi
  done

  # Выводим результаты в файл
  echo "$directory ($directory), суммарный размер всех файлов: $total_size, число просмотренных файлов: $total_files" >> results.txt
}

# Вызываем функцию для основной директории
calculate_directory_size "$target_path"
