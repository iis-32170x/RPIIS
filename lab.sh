#!/bin/bash
read -p "Enter number: " n
s=$((n % 2))
read year month day <<< $(date '+%Y %m %d')
if (( n < 0 )); then  echo "$month-$day-$year"
elif (( n > 0 )); then  if (( s == 0 )); then
    echo "$month/$day/$year"   
elif (( n > 0)); then if (( s == 1 )); then echo "$month"
  fi 
  fi
  fi
read -rsp "Press any key to continue..." -n1 key
