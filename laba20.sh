#!/bin/bash

read -p "Enter file path: " name

if [ -e "$name" ]
then
  echo "Такое есть"
else
  echo "такого нет"
  exit 0
fi

sumtxt=0
sumdoc=0
sumexe=0

for i in $(find "$name" -name '*.txt'); do
   sumtxt=$((sumtxt+1))
done
for i in $(find "$name" -name '*.doc'); do
   sumdoc=$((sumdoc+1))
done
for i in $(find "$name" -name '*.exe'); do
   sumexe=$((sumexe+1))
done

if [ $sumtxt -ge $sumdoc ] && [ $sumdoc -ge $sumexe ]
then
   echo "txt - $sumtxt doc - $sumdoc exe - $sumexe" >> /home/vboxuser/Desktop/laba1/report.txt
elif [ $sumtxt -ge $sumexe ] && [ $sumexe -ge $sumdoc ]
then
   echo "txt - $sumtxt exe - $sumexe doc - $sumdoc" >> /home/vboxuser/Desktop/laba1/report.txt
fi

if [ $sumdoc -ge $sumtxt ] && [ $sumtxt -ge $sumexe ]
then
   echo "doc - $sumdoc txt - $sumtxt exe - $sumexe" >> /home/vboxuser/Desktop/laba1/report.txt
elif [ $sumdoc -ge $sumexe ] && [ $sumexe -ge $sumtxt ]
then
   echo "doc - $sumdoc exe - $sumexe txt - $sumtxt" >> /home/vboxuser/Desktop/laba1/report.txt
fi

if [ $sumexe -ge $sumtxt ] && [ $sumtxt -ge $sumdoc ]
then
   echo "exe - $sumexe txt - $sumtxt doc - $sumdoc" >> /home/vboxuser/Desktop/laba1/report.txt
elif [ $sumexe -ge $sumdoc ] && [ $sumdoc -ge $sumtxt ]
then
   echo "exe - $sumexe doc - $sumdoc txt - $sumtxt" >> /home/vboxuser/Desktop/laba1/report.txt
fi

read -p "Press [Enter] key to continue."