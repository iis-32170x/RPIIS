#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Использование: $0 <количество файлов> <размер первого файла в байтах>"
    exit 1
fi

num_files=$1
file_size=$2

if [ $file_size -lt 10 ]; then
    num_files=1
fi

desktop_path="C:/Users/NoNameUser/Desktop"
mkdir -p "$desktop_path/generated_files"

for ((i=0; i<$num_files; i++)); do
    filename="$desktop_path/generated_files/file$i.txt"
    dd if=/dev/urandom of="$filename" bs=$file_size count=1 2>/dev/null
    file_size=$((file_size - 10))
done

echo "Создано $num_files файлов в каталоге $desktop_path/generated_files"
