#!/bin/bash

inputFile=$1

if [ -d "LR1" ]; then
    cd LR1
else
    mkdir LR1
	cd LR1
fi

if [ -f "even_file_sh.txt" ]; then
  rm even_file_sh.txt
  rm odd_file_sh.txt
fi

if [ ! -f "$inputFile" ]; then
  echo "inputFile \"$inputFile\" не существует."
  exit 1
fi

sort "$inputFile" -o "$inputFile"

oddFile="odd_file_sh.txt"
evenFile="even_file_sh.txt"

count=1
while IFS= read -r string; do
  if ((count % 2 == 0)); then
    echo "$string" >> "$evenFile"
  else
    echo "$string" >> "$oddFile"
  fi
  ((count++))
done < "$inputFile"

exit 0