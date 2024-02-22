#!/bin/bash

file_name=$(find "$1" -type f -printf "%s %p\n" | sort -n | head -n 1 | awk '{print $2}') 
file_name=$(basename ${file_name})
file_size=$(stat -c "%s" "${1}/$file_name")  
echo "file min: ${file_name}, size min: ${file_size}" 

echo -n > result.txt

for file in "$(find "$2" -type f)"
do
  echo "$file" >> result.txt
done

files=()
sizes=()

while IfS= read -r line
do 
  line=$(basename "$line")
  files+=("$line")
done < result.txt

echo -n > result.txt

for ((i=0; i<${#files[@]}; i++)); do

    echo $(stat -c "%s" "${2}/${files[i]}") >> result.txt
done

while IfS= read -r line
do  
  sizes+=("$line")
done < result.txt

echo -n > result.txt


for ((i=0; i<${#sizes[@]}; i++)); do
    echo "file: ${files[i]}, size ${sizes[i]}"
    if ((file_size>sizes[i])); then
        echo "${file_name} > ${files[i]}" >> result.txt
    elif ((file_size<sizes[i])); then
        echo "${file_name} < ${files[i]}" >> result.txt
    else
        echo "${file_name} = ${files[i]}" >> result.txt
    fi
done

mv ${1}/${file_name} ${2}