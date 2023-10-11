 read N
 read path

 grep -h -E -i "^(.* )?[а-яёa-z]{$N}( .*)?$" $path*.txt > result.txt

 echo Press Enter to continue
 read randomVar