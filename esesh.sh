#!/bin/bash

number=0

for file in folder/*.txt
do 
echo $file
number=$((number + 1))

mv "$file" "$number.txt"
done
echo $number

echo "renamed, enter to exit"