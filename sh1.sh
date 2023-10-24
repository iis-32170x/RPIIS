```bash
# Получаем суммарный объем памяти всех активных процессов
totalmemory=$(ps -eo rss= | awk '{sum += $1} END {print sum}')

# Получаем число активных процессов
numprocesses=$(ps -e | wc -l)

# Выводим результаты в файл
echo "Суммарный объем памяти: $totalmemory KB" > results.txt
echo "Число активных процессов: $numprocesses" >> results.txt
```