#!/bin/bash

num_files=$1     #заведем две переменные для названия и количетсво файлов
folder_name=$2

mkdir "$folder_name"  #создание директория 

for ((i=1; i<=num_files; i++))
do
  file_name=$i.txt 
  touch "$folder_name/$file_name" #создание папки 
  
  if ((i % 3 == 0)) #проверка числа на кратность трём
  then
    echo "Hello World" > "$folder_name/$file_name"
  fi
done