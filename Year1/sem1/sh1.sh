#!/bin/bash
echo "Enter number:"
read number

if [[ -z "$number" ]]; then
   echo "The parametre is not set"
   exit
fi
echo "Number of random numbers is $number"
for ((i=1; i<=$number; i++))
do
num=$RANDOM
echo "$num" >> 1.txt
done
