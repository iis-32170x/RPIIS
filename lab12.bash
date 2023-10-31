#!/bin/bash

echo "Введите абсолютный путь."
read mpath
count=$(grep -c "+" "$mpath")
data=$(date +%m-%d-%Y)
echo "Всего $count знака(ов) \"+\""
check=$((count % 2))
if [ $check -eq 0 ]; then
  sum=$(( ${data:0:1}+${data:1:1}+${data:3:1}+${data:4:1}+${data:6:1}+${data:7:1}+${data:8:1}+${data:9:1} ))
  echo "Сумма цифр: $sum"
else
  multi=$(( ${data:0:1}*${data:1:1}*${data:3:1}*${data:4:1}*${data:6:1}*${data:7:1}*${data:8:1}*${data:9:1} ))
  echo "Произведение цифр: $multi"
fi
