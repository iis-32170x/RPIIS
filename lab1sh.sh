#!/bin/bash
n=0
date=0
put=$1
if [ ! -d "$put" ]; then
echo "Данной папки нет"
read -p "Нажмите Enter для продолжения..."
exit
else
n=$(find "$put" -type f | wc -l)
fi
echo "Количество файлов в данной папке и ее подпапках: $n"
rm "$n.txt"
read -p "Нажмите Enter для продолжения..."
date=$(date +%Y%m%d)
m=0
for ((i=0; i<${#date}; i++)); do
    d=${date:i:1}
    if (( d > m )); then
        m=$d
    fi
done
echo "Максимальная цифра в сегодняшней дате : $m"
k=$((n*m))
echo $k >> "$n.txt"
read -p "Нажмите Enter для продолжения..."