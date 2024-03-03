#!/bin/bash
read -p "Введите путь к папке: " pyt
read -p "Введите имя: " imya
ls $pyt/*.txt | awk -F "/" '{print $NF}' | sort > C:/test/$imya.txt
echo "New file has been created"
read -p "Нажмите любую клавишу для продолжения..."