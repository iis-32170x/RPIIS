if test -d $1; then (
num=$(ls $1 | wc -l)
ost=$(($num%2))
if [ $ost -eq 0 ]; then (
ls $1 -t > labfile.txt
) else (
ls $1 -s > labfile.txt
)
fi
) else ( 
echo Данной папки нет
)
fi