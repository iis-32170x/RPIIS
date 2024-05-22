#!/bin/bash

# Получаем абсолютный путь к каталогу
read -p "Введите абсолютный путь к каталогу: " directory
#directory=$1

# Получаем атрибут прав доступа к файлу
read -p "Введите атрибут прав доступа к файлу: " permissions
#permissions=$2

# Получаем символ
read -p "Введите символ: " symbol
#symbol=$3

# Переходим в указанный каталог
cd "$directory"
ls
echo $permissions

# Изменяем права доступа ко всем файлам, содержащим заданный символ в названии
for file in *$symbol*; do
    chmod -v $permissions $file
	
	echo $file
done

echo "Права доступа ко всем файлам, содержащим символ $symbol в названии, изменены на $permissions"
read -p "Нажмите любую клавишу для продолжения..."