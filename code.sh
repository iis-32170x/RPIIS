#!/bin/bash
path=$(pwd)$1
if test -d $path; then
	echo folder exists
else
	echo папка не существует
	exit 0
fi
IFS=$'\n'
i=1
for file in $(find $path -type f -name "*.txt"); do
	let i=1
	while [[ $i -eq 1 ]]; do
		echo "Удалить файл "$file" Y/n (Для предварительного просмотра нажмите O) "
		read responce
		if [ $responce = "Y" ]; then
			echo файл будет удалён
			rm $file
			let i=0
		fi
		if [ $responce = "n" ]; then
			echo файл не будет удалён
			let i=0
		fi
		if [ $responce = "O" ]; then
			cat $file
			echo -e "\n"
			let i=1
		fi
	done
done
