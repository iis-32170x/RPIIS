#!/bin/bash
echo "Введите относительный путь"
read rput
# Ищем в указанной папке файлы с буквой "s" в названии
find "$rput" -type f -iname "*s*" | while read -r file; do
#Выводим последнюю строку каждого найденного файла
tail -n 1 "$file"
done > result.txt
echo "Выполнено! Результаты сохранены в файл result.txt"
