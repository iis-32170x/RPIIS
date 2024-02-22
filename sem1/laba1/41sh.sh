#!/bin/sh
read -p "Введите количество процессов N: " N
processes=$(top -b -n 1 -o %MEM | head -n "$((N+7))" | tail -n "$N")
echo "Список top $N процессов:
  "echo "$processes"
max_mem_process=$(echo "$processes" | head -n 1 | awk '{ print $NF }')
formatted_date=$(date +"%Y-%m-%d")
filename="${max_mem_process}_${formatted_date}.txt"
echo "$max_mem_process $formatted_date" > "$filename"
echo "Создан новый файл: $filename"

