#!/bin/bash

temp=$(($1%2))
if [ $temp -eq 0 ]
then
    for((i=0; i<$1; i++))
    do
        mkdir dir
        cd dir
        date +%H_%M_%S > output.txt
    done
else
    for((i=0; i<$1; i++))
    do
        echo "$RANDOM" >> output.txt
    done
fi
exit 0