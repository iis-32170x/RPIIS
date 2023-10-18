#!/bin/bash

read -p "Введите путь к папке: " folder
report="report.txt"

if [ ! -d "$folder" ]; then
    echo "Данной папки нет!"
    exit 1
fi

declare -A count

find "$folder" -type f | while read -r file; do
    ext="${file##*.}"
    ((count[$ext]++))
done

{
    for ext in "${!count[@]}"; do
        echo "$ext - ${count[$ext]}"
    done
} | sort -rn > "$report"