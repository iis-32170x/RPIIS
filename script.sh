#!/bin/bash

sdirectory=$1
date=$2
directory=$3
day=$(echo $date | cut -d '.' -f 1)
echo $day
month=$(echo $date | cut -d '.' -f 2)
echo $month
year=$(echo $date | cut -d '.' -f 3)
echo $year
fdate=$year$month$day

for oldfile in "$sdirectory"/*
do
    if [ -f "$oldfile" ]; then
        oldname=$(basename "$oldfile")
        createdate=$(stat -c %w "$oldfile")
        echo $createdate
        fday=$(echo $createdate | cut -d '-' -f 3 | cut -d ' ' -f 1)
        fmonth=$(echo $createdate | cut -d '-' -f 2)
        fyear=$(echo $createdate | cut -d '-' -f 1)
        filedate=$fyear$fmonth$fday

        if [ "$filedate" -le "$fdate" ]; then
            newname="${oldname%.*}_$fday.$fmonth.$fyear.${oldname##*.}"
            newfile="$directory/$newname"
            cp "$oldfile" "$newfile"
           fi
        else "file not found"
    fi
done

