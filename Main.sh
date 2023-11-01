#!/bin/bash
read -p "Введите строку: " directory_file
MIN=-32768
MAX=32768
range=$((MAX-MIN+1))
First_number=$((RANDOM % range + MIN))
Second_number=$((RANDOM % range + MIN))
Third_number=$((RANDOM % range + MIN))
summa=$((First_number + Second_number + Third_number))
proverka=$((summa % 2))
if [ -d "$directory_file" ]; then
    echo "$First_number, $Second_number, $Third_number" > Numbers.txt
    if [ $proverka -eq 0 ]; then
        env > Enviroment.txt
        grep -o "/" Enviroment.txt | grep -c . >> Enviroment.txt
    else
        IFS="." read -r day month year <<< "$(date +%d.%m.%Y)"
        if [ $month -lt 10 ]; then
            month="${month#0}"
        fi
        if [ $day -lt 10 ]; then
            day="${day#0}"
        fi
        sum=$((day + month + year))
        echo $sum > Date.txt
    fi
else
    echo "Данной папки нет"
fi
read -p "Нажмите Enter для продолжения..."
