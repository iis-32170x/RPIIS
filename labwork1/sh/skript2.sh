#!/bin/sh

read -p "Введите путь к директории: " directory

# Проверяем, что пользователь ввел директорию
if [ ! -d "$directory" ]; then
    echo "Данной папки нет"
    exit 1
fi

# Переходим в указанную директорию или выходим если невозможно перейти 
cd "$directory" || exit 1

# Создаем файл для записи результатов
result_file="result.txt"
rm -f "$result_file"

# Ищем все пакетные файлы sh в подкаталогах и запускаем их
find . -type f -name "*.sh" -exec sh {} \; >> "$result_file"

# Выводим значения из файла result.txt по убыванию
cat "$result_file" | sort -rn >>results.txt