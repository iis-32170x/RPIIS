#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory_path> <letter>"
    exit 1
fi

directory_path="$1"
letter="$2"

if [ ! -d "$directory_path" ]; then
    echo "This folder does not exist"
    exit 1
fi

find "$directory_path" -type f -name "*.txt" -exec grep -i "\<[a-zA-Z]*$letter\>" {} \; > result.txt

echo "Words ending with '$letter' in '*.txt' files have been saved in 'result.txt'"
