#!/bin/bash

directory=$1
size=$2

if [ ! -d "$directory" ]; then
  echo "Данной папки нет"
  exit 1
fi

output_file="laboratory1.txt"

find "$directory" -type f -size "-$size"c -exec basename {} \; > "$output_file"

echo "Файлы размером меньше $size байт:"
cat "$output_file"