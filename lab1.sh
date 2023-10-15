#!/bin/bash

echo 'Введите абсолютный путь: '
read var1

if [ -e $var1 ]
then
    touch log.txt # Создаем пустой файл log.txt
	cd $var1
find -type f -name "*.doc" | sort -r --output=log.txt # Ищем все файлы с расширением .doc и сортируем их имена

rm $var1/*.doc
else
    echo 'Данная папка не существует'
fi

$SHELL
