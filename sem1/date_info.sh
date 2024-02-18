#!/bin/bash
weekday=$1

current_date=$(date +"%Y-%m-%d")

next_year=$(date +"%Y" -d "+1 year")
next_year_start="${next_year}-01-01"

while [[ $current_date < $next_year_start ]]; do
    if [[ $(date +"%u" -d "$current_date") == $weekday ]]; then
        echo $current_date >> result.txt
        echo $current_date
    fi
    current_date=$(date +"%Y-%m-%d" -d "$current_date + 1 day")
done
