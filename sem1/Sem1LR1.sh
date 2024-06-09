≈		#!/bin/bash
echo "Ку, напиши любое число" 
read num 
if (( num % 2 == 0 )); then

  echo "Число $num четное, создаю папки циклически"

  for ((i=1; i<=num; i++)); do
    
    mkdir -p folder$i/folder$((i+1))/folder$((i+2))

    
    filename=$(date +"%H_%M_%S")
    touch folder$i/folder$((i+1))/folder$((i+2))/$filename.txt
  done
else
  
  echo "Число $num нечетное."  
    echo "Произвольное число $i $RANDOM" >> numbers.txt

fi
