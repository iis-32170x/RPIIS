
#!/bin/sh
mkdir test
cd test
count=0
read kolichestvo
for ((i=1; i<=kolichestvo; i++)); do
  echo $(date +"%H_%M_%S") > $i.txt
  count=$((count+1))
  if [ $count -eq 3 ]; then
    echo "" > $i.txt
    mv $i.txt $i.doc
    count=0
  fi
done
echo "" > kniga.txt
for file in *.txt; do
  if grep -q "24" "$file"; then
    echo "$file" >> kniga.txt
  fi
done

