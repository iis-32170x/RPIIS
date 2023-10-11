#!/bin/bash

echo "Введите абсолютный путь:"
read folder

smallestSize=99999999
smallestFile=""
filename=""

for file in "$folder"/*.txt; do
    if [ -f "$file" ]; then
        fileSize=$(stat -c %s "$file")
        if (( fileSize < smallestSize )); then
            smallestSize=$fileSize
            smallestFile=$file
        fi
    fi
done

if [ -n "$smallestFile" ]; then
    filename=$(basename "$smallestFile" .txt)
    cp "$smallestFile" "$folder/copy_$filename.txt"
    rm "$smallestFile"
    echo "Самый маленький txt-файл: $filename"
    echo "Размер: $smallestSize байт"
else
    echo "В папке $folder нет txt-файлов"
fi
echo 
sleep 5
