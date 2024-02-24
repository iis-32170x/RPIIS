#!/bin/bash
read -p "Введите путь к папке: " folder
read -p "Введите формат файлов: " format
count=$(find "$folder" -maxdepth 1 -type f -name "*.$format" | wc -l)
echo "Число файлов формата $format: $count"
process_count=$(ps aux | wc -l)
remainder=$((count % 2))
if [ $remainder -eq 0 ]; then
    echo "Количество активных процессов: $process_count"
    read -p "Нажмите Enter для продолжения..."
else
    echo "Завершение программы через 7 секунд..."
    sleep 7
fi
