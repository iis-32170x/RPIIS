#!/bin/bash

echo "Введите путь к папке:"
read a

if [ ! -d "$a" ]; then
  echo "Данной папки нет"
  exit 1
fi

cat "$a"/*.text > DA.text

file_size=$(stat -c%s DA.text)

if [ $file_size -gt 102400 ]; then
  sed -i '2~2d' DA.text
elif [ $file_size -lt 102400 ]; then
  sed -i '1~2d' DA.text
else
  echo "File is 100 Kb"
fi