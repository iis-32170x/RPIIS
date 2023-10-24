!/bin/bash

# Получаем суммарный объем памяти активных процессов
memory_usage=$(ps aux | awk '{ sum += $6 } END { print sum }')

# Получаем число активных процессов
process_count=$(ps -e | wc -l)

# Выводим результаты в файл
echo "Суммарный объем памяти: $memory_usage" > memory_usage.txt
echo "Число активных процессов: $process_count" >> memory_usage.txt

# Выводим результаты на экран
echo "Суммарный объем памяти: $memory_usage"
echo "Число активных процессов: $process_count"
