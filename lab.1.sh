#!/bin/bash
echo "Enter Source Directory: "
read -r x
echo "Enter Destination directory: "
read -r y
if [ ! -d "$x" ];then 
echo "not exist"
fi
if [ ! -d "$y" ]; then 
echo "not exist"
fi
 rsync -r --delete "$x/" "$y"
