#!/bin/bash
echo "Введите абсолютный путь: "
read upath

if [ ! -d "$upath" ]; then
  read -rsp "Данной папки нет" -n1 key
  exit
fi

touch "$upath/result.txt"
> "$upath/result.txt"

while IFS= read -r -d '' file; do
  echo "$(basename "$file")" >> "$upath/result.txt" 
done < <(find "$upath" -type f -name '.*' -print0 | sort -k1.2r)
if [ ! -s "$upath/result.txt" ]; then
  echo "Скрытых файлов не найдено" > "$upath/result.txt"
  read -rsp "Скрытых файлов не найдено" -n1 key
else
  echo "Скрытые файлы:"
  cat "$upath/result.txt"
  read -rsp "Press any key to continue..." -n1 key
 fi
