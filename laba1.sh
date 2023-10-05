#!/bin/bash 
#trap 'echo "--------# $BASH_COMMAND-------";read' DEBUG
read -p "Введите путь к папке: " path

if [ ! -d "$path" ]; then  
    echo "папки не существует" 
	exit
fi

if [ ! -d "$path/files" ]; then
	mkdir $path/files
fi

find "$path" -type f -size +1M | while read file; do
	echo $file
	cp "$file" "$path/files"
done
