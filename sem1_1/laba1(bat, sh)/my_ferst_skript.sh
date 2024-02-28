#!/bin/bash
 folder_path="$1"

if [ ! -d "$folder_path" ]; then  echo "Данной папки нет" 
	exit 1 
fi
echo $folder_path
find "$folder_path" -type f -name "*temp*" -exec head -n 5 {} \; > /home/ilja/.myskript/result