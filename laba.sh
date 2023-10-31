read -p ""  file1
read -p "" file2

string1=$(wc -l < $file1 | awk '{print $1}')
string2=$(wc -l < $file2| awk '{print $1}')
if [ $string1 -eq $string2 ]; then
  echo "Количество строк одинаковое"
else
    echo "Количество строк разное"
    word1=$(wc -w < $file1 | awk '{print $1}')
    word2=$(wc -w < $file2 | awk '{print $1}')
      if [ $word1 -eq $word2 ]; then
        echo "Количество cлов одинаковое"
      else
        echo "Количество слов разное"
      fi

fi


sleep 7
