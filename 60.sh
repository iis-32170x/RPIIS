#!/bin/bash

read -p "Введите путь к папке: " folder
if [ ! -d "$folder" ]; then
    echo "Данной папки нет"
    exit 1
fi

ps -eo pid,etime,cmd --sort=-etime | awk '$2 ~ /([0-9]+-[0-9]+:)?([0-9]+:)?[0-9]+/ && $2 >= "00:10:00" {print}' > result.txt.
