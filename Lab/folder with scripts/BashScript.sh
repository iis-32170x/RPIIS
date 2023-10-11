echo Enter amount of letters
read Amount_Of_Letters 
echo Enter path
read path

grep -h -E -i "^(.* )?[а-яёa-z]{$Amount_Of_Letters}( .*)?$" $path*.txt > result.txt

echo Press Enter to continue
read randomVar