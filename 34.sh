#!/bin/bash

directory=$1
extension=$2
max_length=$3
output_file="FileList.txt"

if [ ! -d "$directory" ]; then
  echo "Данной папки нет"
  exit 1
fi

cd "$directory"

find . -type f -name "*.$extension" -printf "%f\n" | awk -v len="$max_length" 'length($0) <= len' | sort > "$output_file"

echo "Список файлов, удовлетворяющих критериям, сохранен в файле: $output_file"
