#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory_path> <permissions>"
    exit 1
fi

DIR=$1
PERMS=$2

if [ ! -d "$DIR" ]; then
    echo "Данной папки нет"
    exit 1
fi

find "$DIR" -type f -perm "$PERMS" > result.txt

echo "Файлы с правами доступа $PERMS сохранены в result.txt"