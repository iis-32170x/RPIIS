read -p "input a size" file_size
echo $file_size
name="\\wsl.localhost\Ubuntu\home\qwerty\pppp\FILE1.txt"
head -c $file_size /dev/zero > $name
read -p "input any symbols" words
echo $words > $name
count=0
while [ -n "$words" ]; do
  words="${words#?}"
  ((count++))
done
echo $count
time_created=$(date +%m-%H) 
sum=$((10#${time_created:0:2} + 10#${time_created:3:2}))
let "sum1 = $sum * $count"
echo $sum
echo $sum1
for ((i=0; i<=$sum1; i++)); 
do
  mkdir $i
  cd $i
  time_file=$(date +%H_%M)
  echo  > $i\.$time_file.txt
done
