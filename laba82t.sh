#!/bin/bash
mkdir /home/mayu/Рабочий\ стол/papka
date +%Y-%m-%d > /home/mayu/Рабочий\ стол/papka/data.txt
grep -o "[0-9]" /home/mayu/Рабочий\ стол/papka/data.txt > /home/mayu/Рабочий\ стол/papka/cifri.txt
counter=1
while [ $counter -le 8 ]
do
m[$counter]=`sed -n "$counter"p /home/mayu/Рабочий\ стол/papka/cifri.txt`
((counter++))
done
counter=1
while [ $counter -le 8 ]
do
if (( ${m[$counter]} >= ${m[1]} )) && (( ${m[$counter]} >= ${m[2]} )) && (( ${m[$counter]} >= ${m[3]} )) && (( ${m[$counter]} >= ${m[4]} )) && (( ${m[$counter]} >= ${m[5]} )) && (( ${m[$counter]} >= ${m[6]} )) && (( ${m[$counter]} >= ${m[7]} )) && (( ${m[$counter]} >= ${m[8]} )); then 
				a=${m[$counter]}
				fi
((counter++))
done
let "b=$a/2*2"
			if [ $b == $a ]; then
				echo "Hello"
			else
				echo > /home/mayu/Рабочий\ стол/papka/"$a"
			fi
rm /home/mayu/Рабочий\ стол/papka/data.txt
rm /home/mayu/Рабочий\ стол/papka/cifri.txt
rmdir /home/mayu/Рабочий\ стол/papka
read -p "Press any key"
