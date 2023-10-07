touch {first.txt,second.txt}

i=0
while [ $i -le $(( RANDOM )) ]
do
echo $[ $RANDOM % 899 + 100 ]>> first.txt
((i++))
done
grep -i "23" first.txt >> second.txt
sort -r second.txt
start first.txt
start second.txt
