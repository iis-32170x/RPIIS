#!/bin/bash
read -p "Length: " password_length
password_file="pwd.txt"
simvoli="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@!%%$#^"

if [ -f "$password_file" ]; then
    rm "$password_file"
fi

for i in {1..6}; do
    password=""
    for j in $(seq 1 "$password_length"); do
        char_index=$((RANDOM % 69))
        char="${simvoli:char_index:1}"
        password="$password$char"
    done
    echo "$password" >> "$password_file"
done
