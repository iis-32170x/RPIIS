#!/bin/bash
echo -e "\n введите путь к директории:"
read path_to
if [ -e $path_to ]
then
# -o выводит не всю строчку 
	find $path_to -name "*.txt" -exec cat {} \; | grep -o "\b[vV][a-zA-Z]*\b" > result.txt
	else
	echo "Данной папки не существует"
	sleep 3m
fi


