read -rp "Enter the path to a directory: " directory
read -p "Enter first positive smaller number: " num1
read -p "Enter second positive bigger number: " num2

if [[ -e result.txt ]]; then
  rm result.txt
fi

files=$(find "$directory" -type f -size +"$num1"c -size -"$num2"c)

touch result.txt

for file in $files
do
  echo "$(basename $file) $(date -r $file +"%F %T")" >> result.txt  
done

echo "$(sort result.txt)" > result.txt
