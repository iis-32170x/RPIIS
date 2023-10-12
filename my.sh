#!/bin/bash

if ! [ -d "$1" ]; then
  echo "Folder do not exist"
  exit 1
fi

f=$(find $1 -type f | sort -n | tail -n 1)

echo "f=$f"

size=$(stat -c %s $f)
echo "размер файла=$size" > result.txt

countlet=$(wc -m < $f)

count=$(wc -w < $f)


echo "количество слов=" >> result.txt
echo $count >> result.txt

echo "количество букв=" >> result.txt
echo $countlet >> result.txt

echo "количество строк=" >> result.txt
wc -l < $f >> result.txt