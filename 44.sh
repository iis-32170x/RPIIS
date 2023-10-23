#!/bin/bash

read  directory

if [ ! -d "$directory" ]; then
  echo "Данного каталога не существует."
  exit 1
fi

find "$directory" -type f | while read -r file; do
    count=0
    count=($(wc -w "$file"))
    
    filename=$(basename "$file")
    filenamefile="${filename%.*}"
    extensionfile="${filename##*.}"
    newname="${count}""_""${filenamefile}"."${extensionfile}"
    
    mv "$file" "$directory/$newname"
done
echo "Готово."
sleep 2
