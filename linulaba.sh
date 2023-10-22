#!/bin/bash

B=512000
read -rp "Введите путь папки:" a

if [ ! -d "$a" ]; then
echo "Данной папки не существует"
read -p "Press enter to exit"
else
S=$B

while IFS= read -r -d '' file; do
size=$(stat -c %s "$file")

if [ "$size" -lt "$S" ]; then
S=$size
fi
done < <(find "$a" -name "*.txt" -print0)

while IFS= read -r -d '' file; do
size=$(stat -c %s "$file")

if [ "$size" -eq "$S" ]; then
rm -f "$file"
echo "$file удален"
fi
done < <(find "$a" -name "*.txt" -print0)

read -p "Press enter to exit"
fi