#!/bin/bash  
mkdir /home/rivaking/Рабочий\ стол/folder1
mkdir /home/rivaking/Рабочий\ стол/folder2
mkdir /home/rivaking/Рабочий\ стол/folder3
date +%D > /home/rivaking/Рабочий\ стол/folder1/otchet.txt
cp /home/rivaking/Рабочий\ стол/folder1/otchet.txt /home/rivaking/Рабочий\ стол/folder2/otchet.txt
chislo=`date +%e`
mv /home/rivaking/Рабочий\ стол/folder2/otchet.txt /home/rivaking/Рабочий\ стол/folder2/$chislo.txt
dlina=`basename /home/rivaking/Рабочий\ стол/folder2/$chislo.txt`
n=${#dlina}
echo $n >> /home/rivaking/Рабочий\ стол/folder2/$chislo.txt
cp /home/rivaking/Рабочий\ стол/folder2/$chislo.txt /home/rivaking/Рабочий\ стол/folder3/$chislo.txt
versia=`uname -mrs`
echo $versia >>  /home/rivaking/Рабочий\ стол/folder3/$chislo.txt
