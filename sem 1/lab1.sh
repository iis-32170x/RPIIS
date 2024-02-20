path=$1
if [ -f "$path" ]; 
then
echo "file exist"
else
echo "file does not exist"
exit 
fi
data=$(date +%d)
word=$(wc -w < $path)
letter=$(cat "$path"|tr -cd '[[:alpha:]]'|wc -c)
result=$((data*word*letter))
echo "$data"
echo "$word"
echo "$letter"
echo "$result"
echo "$result" > relult.txt
