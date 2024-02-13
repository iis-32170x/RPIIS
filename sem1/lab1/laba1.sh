#! /bin/bash

rm $1result.txt

smallest_file=""
smallest_size=9999999999

for file in "$1"/*.txt; do
    size=$(wc -c < "$file")
    if [ $size -lt $smallest_size ]; then
        smallest_file="$file"
        smallest_size=$size
    fi
done



touch $1result.txt
touch $1res.txt

rev $smallest_file > $1res.txt
tac "$1res.txt" > $1result.txt

rm $1res.txt
