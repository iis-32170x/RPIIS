#!/bin/bash
folder=$2
keywords=$1
number=$3
count=0
papka2=${folder}_search
mkdir ./$folder/$papka2
for file in $folder/*; do
if [ -f $file ]; then
for keyword in $keywords; do
if grep -q "$keyword" $file; then
count=$((count+1))
fi
done
if [ $count -ge $number ]; then
cp $file $folder/$papka2
fi
count=0
fi
done
